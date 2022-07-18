# MMAP-Comparison
# Executing

Just type the following to compile the code and create the file to be executed:
```
gcc -o mmap mmap.c -lm
```

To execute the program, just type:

```
./mmap
```
# Output


<pre>
--------------------------------------------------------
File Size: 16 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 0.98 seconds.
Execution time of traditional read was: 0.42 seconds.
Execution time of mmap write was: 0.01 seconds.
Execution time of mmap read was: 0.01 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 0.49 seconds.
Execution time of traditional read was: 0.21 seconds.
Execution time of mmap write was: 0.01 seconds.
Execution time of mmap read was: 0.01 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 0.24 seconds.
Execution time of traditional read was: 0.11 seconds.
Execution time of mmap write was: 0.01 seconds.
Execution time of mmap read was: 0.00 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 0.13 seconds.
Execution time of traditional read was: 0.05 seconds.
Execution time of mmap write was: 0.01 seconds.
Execution time of mmap read was: 0.00 seconds.

--------------------------------------------------------
File Size: 32 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 1.95 seconds.
Execution time of traditional read was: 0.84 seconds.
Execution time of mmap write was: 0.03 seconds.
Execution time of mmap read was: 0.02 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 0.99 seconds.
Execution time of traditional read was: 0.42 seconds.
Execution time of mmap write was: 0.02 seconds.
Execution time of mmap read was: 0.01 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 0.54 seconds.
Execution time of traditional read was: 0.21 seconds.
Execution time of mmap write was: 0.02 seconds.
Execution time of mmap read was: 0.01 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 0.32 seconds.
Execution time of traditional read was: 0.12 seconds.
Execution time of mmap write was: 0.02 seconds.
Execution time of mmap read was: 0.01 seconds.

--------------------------------------------------------
File Size: 64 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 3.96 seconds.
Execution time of traditional read was: 1.68 seconds.
Execution time of mmap write was: 0.06 seconds.
Execution time of mmap read was: 0.04 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 1.90 seconds.
Execution time of traditional read was: 0.85 seconds.
Execution time of mmap write was: 0.04 seconds.
Execution time of mmap read was: 0.02 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 1.01 seconds.
Execution time of traditional read was: 0.43 seconds.
Execution time of mmap write was: 0.04 seconds.
Execution time of mmap read was: 0.02 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 0.49 seconds.
Execution time of traditional read was: 0.22 seconds.
Execution time of mmap write was: 0.03 seconds.
Execution time of mmap read was: 0.01 seconds.

--------------------------------------------------------
File Size: 128 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 8.08 seconds.
Execution time of traditional read was: 3.48 seconds.
Execution time of mmap write was: 0.16 seconds.
Execution time of mmap read was: 0.07 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 3.94 seconds.
Execution time of traditional read was: 1.68 seconds.
Execution time of mmap write was: 0.10 seconds.
Execution time of mmap read was: 0.04 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 2.00 seconds.
Execution time of traditional read was: 0.84 seconds.
Execution time of mmap write was: 0.08 seconds.
Execution time of mmap read was: 0.03 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 1.06 seconds.
Execution time of traditional read was: 0.44 seconds.
Execution time of mmap write was: 0.07 seconds.
Execution time of mmap read was: 0.02 seconds.

--------------------------------------------------------
File Size: 256 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 15.30 seconds.
Execution time of traditional read was: 6.72 seconds.
Execution time of mmap write was: 0.51 seconds.
Execution time of mmap read was: 0.15 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 7.71 seconds.
Execution time of traditional read was: 3.42 seconds.
Execution time of mmap write was: 0.25 seconds.
Execution time of mmap read was: 0.11 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 4.03 seconds.
Execution time of traditional read was: 1.71 seconds.
Execution time of mmap write was: 0.32 seconds.
Execution time of mmap read was: 0.05 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 2.13 seconds.
Execution time of traditional read was: 0.88 seconds.
Execution time of mmap write was: 0.15 seconds.
Execution time of mmap read was: 0.04 seconds.

--------------------------------------------------------
File Size: 512 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 31.13 seconds.
Execution time of traditional read was: 13.85 seconds.
Execution time of mmap write was: 0.84 seconds.
Execution time of mmap read was: 0.29 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 15.80 seconds.
Execution time of traditional read was: 6.87 seconds.
Execution time of mmap write was: 0.62 seconds.
Execution time of mmap read was: 0.19 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 8.49 seconds.
Execution time of traditional read was: 3.39 seconds.
Execution time of mmap write was: 0.48 seconds.
Execution time of mmap read was: 0.12 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 4.24 seconds.
Execution time of traditional read was: 1.74 seconds.
Execution time of mmap write was: 0.36 seconds.
Execution time of mmap read was: 0.09 seconds.

--------------------------------------------------------
File Size: 1024 MB
--------------------------------------------------------
Buffer Size: 32 BYTES

Execution time of traditional write was: 69.11 seconds.
Execution time of traditional read was: 28.52 seconds.
Execution time of mmap write was: 1.36 seconds.
Execution time of mmap read was: 0.59 seconds.
--------------------------------------------------------
Buffer Size: 64 BYTES

Execution time of traditional write was: 31.65 seconds.
Execution time of traditional read was: 14.12 seconds.
Execution time of mmap write was: 0.89 seconds.
Execution time of mmap read was: 0.32 seconds.
--------------------------------------------------------
Buffer Size: 128 BYTES

Execution time of traditional write was: 16.95 seconds.
Execution time of traditional read was: 7.00 seconds.
Execution time of mmap write was: 0.78 seconds.
Execution time of mmap read was: 0.22 seconds.
--------------------------------------------------------
Buffer Size: 256 BYTES

Execution time of traditional write was: 9.07 seconds.
Execution time of traditional read was: 3.47 seconds.
Execution time of mmap write was: 0.66 seconds.
Execution time of mmap read was: 0.14 seconds.


</pre>