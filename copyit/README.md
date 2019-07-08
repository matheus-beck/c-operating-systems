# copyit.c
C program that copy files using system calls and error verification. Developed at MATA58 - OPERATING SYSTEMS at Federal University of Bahia. 

To execute the program:
```c
$ gcc -o copyit copyit.c
$ ./copyit sourceFile destFile
```

The effectiveness of the program was verified using the md5sum program where both the source and destination files presented the same 128-bit MD5 hashes. The md5sum is able to calculate a checksum from the file, creating a "fingerprint" in the form of a hexadecimal number using the MD5 algorithm.

To check the effectiveness:
```c
$ md5sum sourceFile
$ md5sum destFile
```

![copyit in execution](https://i.imgur.com/YCcv04e.gif)
