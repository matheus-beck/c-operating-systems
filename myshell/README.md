# myshell.c
 C program that simulates Linux shell using system calls and error verification. Developed at MATA58 - OPERATING SYSTEMS at Federal University of Bahia. 
 
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
