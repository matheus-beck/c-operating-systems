//Author: Matheus de Alencar Beck - UFBA

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

void display_message(int s){
    printf("copyit: cópia em andamento ...\n");
    alarm(1); //Keeps the alarm running
}

void getError(int status, char *nameSystemCall){
    if (status < 0){
	printf("Erro na chamada %s: %s\n", nameSystemCall, strerror(errno));
	exit(1);
    }
}

int main(int argc, char *argv[]){
    //Step 0 - Verify amount of arguments passed
    if (argc != 3){
        printf("%s: Número incorreto de argumentos\n", argv[0]);
    	printf("use: %s ArquivoOrigem ArquivoDestino\n", argv[0]);
    	exit(1);
    }
    
    //Step 1 - Configure handler to display message
    signal(SIGALRM, display_message); //Receive alarm signal and executes display_message
    alarm(1); //Sets alarm to 1s
    
    //Step 2 - Open source file and verify errors
    int sourceFile = open(argv[1], O_RDONLY); //Returns new file descriptor
    getError(sourceFile, argv[1]);
    
    //Step 3 - Create destination file and verify errors
    int destFile = creat(argv[2], S_IRWXU); //Returns new file descriptor
    getError(destFile, argv[2]);
    
    char *buffer = (char *) malloc(1000); //Holds the content that will be read
    long int copiedBytes = 0; 
    
    //Step 4 - Read content from source and verify errors
    int readContent = read(sourceFile, buffer, 1000); //Returns the  number of bytes readed 
    while (readContent != 0) { //Stops when everything is read
    	if (readContent < 0){
    	    if (errno == EINTR){ //If read was interrupted
    		readContent = read(sourceFile, buffer, 1000); //Try again
    	    } else {
    		getError(readContent, argv[2]);
    	    }
    	}
    
    	//Step 5 - Write content readed into destination file and verify errors
    	int writeContent = write(destFile, buffer, readContent); //Returns the number of bytes writed
    	if (writeContent < 0){
    	    if (errno == EINTR){ //If write was interrupted
    		writeContent = write(destFile, buffer, readContent); //Try again
    	    } else {
    		getError(readContent, argv[3]);
    	    }
    	}
    	copiedBytes += writeContent;
    	readContent = read(sourceFile, buffer, 1000); //Read again till 0 bytes get returned
    }
    
    free(buffer);
    
    //Step 6 - Closes both files
    close(sourceFile);
    close(destFile);
    
    printf("copyit: foram copiados %li bytes do arquivo %s para o arquivo %s\n", copiedBytes, argv[1], argv[2]);
    return 0;
}
