// Author: Matheus Beck
// To compile this code: gcc primes.c -o thread -lpthread 
// To execute: ./thread 15

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int size = 0;


void *primes_thread(void *arg){
    printf("Prime numbers: ");
    
    int *myNumber = (int *) arg;
    
    int i, j, fact;
    for(i=1; i<=*myNumber; i++){
        fact=0;
        for(j=1; j<=*myNumber; j++){
            if(i%j==0) fact++;
        }
        if (fact==2) printf("%d " ,i);
    }
}

main(int argc, char *argv[])
{
    if (argc != 2){
        printf("%s: Incorrect number of arguments\n", argv[0]);
		printf("Example of use: %s 15 \n", argv[0]);
		exit(1);
	}
	
	int myNumber = atoi(argv[1]);

    pthread_t thread1;
    int t1;
 
    // Create thread to execute appropriate function:
    t1 = pthread_create(&thread1, NULL, (void *) primes_thread, &myNumber);
 
    // Wait till thread complete:
    pthread_join(thread1, NULL);
 
    return 0;
}
