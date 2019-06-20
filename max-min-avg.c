// Author: Matheus Beck
// To compile this code: gcc max-min-avg.c -o thread -lpthread 
// To execute: ./thread 42 56 89 10

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double avg = 0;        
int min = 0;
int max = 0;
int size = 0;


void *avg_thread(void *arg){
    int *myArray = (int *) arg;
    
    int i;
    for(i = 0; i < size; i++){
        avg += myArray[i];
    }

    avg = (int)(avg/size);          
}

void *min_thread(void *arg){
    int *myArray = (int *) arg;
    
    int i;
    min = myArray[0];
    for(i = 1; i < size; i++){
        if(min > myArray[0]) min = myArray[i];
    }
}

void *max_thread(void *arg){
    int *myArray = (int *) arg;
    
    int i;
    max = myArray[0];
    for(i = 1; i < size; i++){
        if(max < myArray[i]) max = myArray[i];
    }
}

main(int argc, char *argv[])
{
    if (argc <=1){
        printf("%s: Incorrect number of arguments\n", argv[0]);
		printf("Example of use: %s 42 56 89 10 \n", argv[0]);
		exit(1);
	}
	
    // Save input into array:
    int i = 0;
    int myArray[argc-1];
    for(i; i < (argc -1); i++){
        myArray[i] = atoi(argv[i+1]);
        size++;
    }
        
    pthread_t thread1, thread2, thread3;
    int t1, t2, t3;
 
    // Create threads to execute appropriate functions:
    t1 = pthread_create(&thread1, NULL, (void *) avg_thread, (void*)myArray);
    t2 = pthread_create(&thread2, NULL, (void *) min_thread, (void*)myArray);
    t3 = pthread_create(&thread3, NULL, (void *) max_thread, (void*)myArray);
 
 
    // Wait till threads complete:
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
 
    printf("The average value is :  %g\n", avg);
    printf("The minimum value is :  %d\n", min);
    printf("The maximum value is :  %d\n", max);
 
    return 0;
}
