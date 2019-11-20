# Operating Systems 
Operating Systems projects using C. Developed at MATA58 - OPERATING SYSTEMS at Federal University of Bahia

## Copyit
C program that copy files using system calls and error verification.

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


## MyShell
C program that simulates Linux shell using system calls and error verification.
 
 To execute the program:
```c
$ gcc -o myshell myshell.c
$ ./myshell
```
After the display of the prompt ```myshell>``` you can use the following commands to operate the shell:

start name-of-program command-line-aruments-if-needed (Starts a program) \
wait (Waits for the process to finish) \
run (Combination of start and wait) \
kill process-id (Kills the process) \
stop process-id (Stops the process) \
continue process-id (Continues process execution)

## Multithreaded Programming
Multithreaded programming examples using C. 

#### max-min-avg.c

This program will receive a list of numbers on the command line, and then create three separate threads. One of the threads will determine the average of the numbers, the second thread will determine the minimum value, and the third thread will determine the maximum value.

To execute the program:

```c
$ gcc max-min-avg.c -o thread -lpthread
$ ./thread 42 56 89 10
```
![max-min-avg.c execution](https://i.imgur.com/R0mxFCl.gif)

#### primes.c

Given an integer, this program will create a thread to calculate all the prime numbers less than or equal to that integer.

To execute the program:

```c
$ gcc primes.c -o thread -lpthread
$ ./thread 15
```
![primes.c execution](https://i.imgur.com/WgXTiW7.gif)


---

Made with ❤️ and ☕ by Matheus Beck :wave: [Get in touch!](https://www.linkedin.com/in/matheus-beck/)
