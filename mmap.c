#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <sys/resource.h>

#define SIZE_MB 16
#define SIZE_BUFFER_BYTE 32
#define OUTPUT_NAME "result.txt"

//A helper structure for storing variables used by I/O functions
typedef struct 
{
    int fd;
	char * str; //the buffer will be filled with this string
    char * buffer; //I/O operations will be applied to the buffer for the file
    int byte_size; //output file size in bytes
    int byte_size_bf; //buffer size in bytes
    int buffer_rate; //ratio between the size in bytes of ->str and buffer, or how many times ->str needs to be copied to fill the buffer
    int size_rate; //ratio between the size in bytes of the buffer and the output file, or how many times the buffer needs to be copied to fill the output file
    clock_t start;
    clock_t end;
} Descriptor;

void error_occ(char * input)
{
    printf("Error: %s\n", input);
    exit(0);
}

Descriptor* start_descriptor(int size_MB, int size_buffer_byte, char * filename)
{   
    int i = 0;
    Descriptor * descp = (Descriptor *) malloc(sizeof(Descriptor));

    descp->fd = open(filename, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (descp->fd == -1) error_occ("open");
    
    descp->str = "TEST";
    descp->byte_size = size_MB * 1024 * 1024;
    descp->byte_size_bf = size_buffer_byte;
    descp->buffer_rate = (int) (descp->byte_size_bf/strlen(descp->str));
    descp->size_rate = (int) (descp->byte_size/size_buffer_byte);
    descp->buffer = (char *) malloc(descp->byte_size_bf * sizeof(char)); 

    while(i < descp->buffer_rate)
    {
        strcat(descp->buffer, descp->str);
        i++;
    }

    i = 0; 

    do
    { 
        i++;
    } while(write(descp->fd, descp->buffer, descp->byte_size_bf) > 0 && i < descp->size_rate);

    return descp;
}

void finalize_descriptor(Descriptor *descp) 
{   
    close(descp->fd); 
    free(descp->buffer);
    free(descp);
}

void trad_write(Descriptor * descp)
{
    int i = 0;

    lseek(descp->fd, 0, SEEK_SET);

    descp->start = clock();

    do 
    {
        i++;
    } while(write(descp->fd, descp->buffer, descp->byte_size_bf) > 0 && i < descp->size_rate);

    descp->end = clock();
}

void trad_read(Descriptor * descp)
{
    int i = 0;

    lseek(descp->fd, 0, SEEK_SET);
    
    char buffer[descp->byte_size_bf];

    descp->start = clock();

    do 
    { 
        i++; 
    } while(read(descp->fd, buffer, descp->byte_size_bf) > 0 && i < descp->size_rate);

    descp->end = clock();
}

void mmap_write(Descriptor * descp)
{
    int i = 0;
    char *addr;

    lseek(descp->fd, 0, SEEK_SET);

    addr = mmap(NULL, descp->byte_size, PROT_WRITE, MAP_SHARED, descp->fd, 0);
    if (addr == MAP_FAILED) error_occ("mmap");
 
    descp->start = clock();

    while(i < descp->size_rate)
    {   
        memcpy(addr + i*(descp->byte_size_bf), descp->buffer, descp->byte_size_bf);
        i++;
    }

    descp->end = clock();

    munmap(addr, descp->byte_size);
}

void mmap_read(Descriptor * descp)
{
    char *addr;
    int i = 0;
    
    char buffer[descp->byte_size_bf];
    lseek(descp->fd, 0, SEEK_SET);

    addr = mmap(NULL, descp->byte_size, PROT_READ, MAP_SHARED, descp->fd, 0);
    if (addr == MAP_FAILED) error_occ("mmap");
    
    descp->start = clock();

    while(i < descp->size_rate)
    {
        memcpy(buffer, addr + i*(descp->byte_size_bf), descp->byte_size_bf);
        i++;
    }

    descp->end = clock();

    munmap(addr, descp->byte_size);
}

int main(int argc, char *argv[])
{
    int i, j, p_i, p_j;

    for(i = 0; i < 8; i++)
    {   
        p_i = (int) pow(2, i);
        printf("\n--------------------------------------------------------\n");
        printf("File Size: %d MB\n", SIZE_MB * p_i);
        for(j = 0; j < 4; j++)
        {
            p_j = (int) pow(2, j);
            printf("--------------------------------------------------------\n");
            printf("Buffer Size: %d BYTES\n\n", SIZE_BUFFER_BYTE * p_j);
            
            Descriptor * descp = start_descriptor(SIZE_MB * p_i, SIZE_BUFFER_BYTE * p_j, OUTPUT_NAME);

            trad_write(descp);

            printf("Execution time of traditional write was: %.2lf seconds.\n", ((double) (descp->end - descp->start))/CLOCKS_PER_SEC);

            trad_read(descp);

            printf("Execution time of traditional read was: %.2lf seconds.\n", ((double) (descp->end - descp->start))/CLOCKS_PER_SEC);

            mmap_write(descp);

            printf("Execution time of mmap write was: %.2lf seconds.\n", ((double) (descp->end - descp->start))/CLOCKS_PER_SEC);

            mmap_read(descp);

            printf("Execution time of mmap read was: %.2lf seconds.\n", ((double) (descp->end - descp->start))/CLOCKS_PER_SEC);

            finalize_descriptor(descp);
        }
    }

    exit(EXIT_SUCCESS);
}
