# Multithreaded programming using C
Multithreaded programming examples using C. Developed at MATA58 - OPERATING SYSTEMS at Federal University of Bahia

# max-min-avg.c

This program calculates several statistical values for a given list of numbers. This program will receive a series of numbers on the command line, and then create three separate threads. One of the threads will determine the average of the numbers, the second thread will determine the maximum value, and the third thread will determine the minimum value.

To execute the program:

```c
$ gcc max-min-avg.c -o thread -lpthread
$ ./thread 42 56 89 10
```
![max-min-avg.c execution](https://i.imgur.com/R0mxFCl.gif)
