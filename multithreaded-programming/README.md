# Multithreaded programming using C
Multithreaded programming examples using C. Developed at MATA58 - OPERATING SYSTEMS at Federal University of Bahia

# max-min-avg.c

This program will receive a list of numbers on the command line, and then create three separate threads. One of the threads will determine the average of the numbers, the second thread will determine the minimum value, and the third thread will determine the maximum value.

To execute the program:

```c
$ gcc max-min-avg.c -o thread -lpthread
$ ./thread 42 56 89 10
```
![max-min-avg.c execution](https://i.imgur.com/R0mxFCl.gif)

# primes.c

Given an integer, this program will create a thread to calculate all the prime numbers less than or equal to that integer.

To execute the program:

```c
$ gcc primes.c -o thread -lpthread
$ ./thread 15
```
![primes.c execution](https://i.imgur.com/WgXTiW7.gif)
