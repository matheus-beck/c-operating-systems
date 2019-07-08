//Author: Matheus de Alencar Beck - UFBA

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_CHAR 4096
#define MAX_WORDS 100

void getError(int status, char *nameSystemCall){
	//Verify any error in system calls
	if (errno == ECHILD) { //Check if there is a process left
		printf("myshell: No process left.\n");
		errno = ESRCH; //Mandatory to don't print the ECHILD error everytime the function is called
	} 
	else if (status < 0) {
		printf("myshell: %s: %s\n", nameSystemCall, strerror(errno));
		exit(1);
	}
}

void getPromptEntrance (char *buffer){
	//Get the user's entrance in the prompt as string
	printf("myshell>"); // Prints prompt 

	int status = fflush(stdout); //Force exit on screen before read line
	getError(status, "fflush");

	char *entrance = fgets(buffer, MAX_CHAR, stdin);  //Receive line of text
	
	if (feof(stdin) != 0)  //Reach EOF
		exit(0); //End program with sucess
	else if (entrance == NULL) //Error happend
		getError(-1, "fgets"); //-1 was hard coded to force error
}

void getWordsFromBuffer(char *buffer, char **words){
	//Transform the string of commands into array of commands
	int i = 0;

	char *word = strtok(buffer, " \t\n"); //Gets first word
	if (word != NULL){ //Check if user pressed 'enter' only
		words[i] = word;
		
		//Stopping loop condition:
	  	if (strcmp(words[0],"exit") == 0 || strcmp(words[0],"quit") == 0)
	  		exit(0);

		while (word != NULL){ //Read next word
			i++;
			word = strtok(0, " \t\n");
			words[i] = word;
		}

		words[i+1] = 0; // i+1 = totalwords
	}
}

void executeCommand(char **words){
	if (words[0] != NULL) { //Check if user pressed 'enter' only
		if (strcmp(words[0],"start") == 0){
			pid_t childProcess = fork();
			getError(childProcess, "fork");

			char **arguments = &words[1]; //get arguments in string

			if (childProcess == 0) { //Child executes this if
				if (execvp(words[1], arguments) == -1); //Execute program and check error
					getError(-1, "execvp");
			} 
			else // Parent executes this else informing existence of process
				printf("myshell: process %d started\n", childProcess);
		} 

		else if (strcmp(words[0],"wait") == 0){
			int status;
			pid_t process = wait(&status);
			getError(process, "wait");

			if (status == 0)
				printf("myshell: process %d ended correctely with status: %d \n", process, status);		
			else if (status != 0)
				printf("myshell: process %d ended incorrectely with status %d: %s\n", process, status, strsignal(status));
		} 

		else if (strcmp(words[0],"run") == 0){
			pid_t childProcess = fork();
			getError(childProcess, "fork");

			char **arguments = &words[1]; //get arguments in string

			if (childProcess == 0) { //Child will execute this if
				if (execvp(words[1], arguments) == -1); //Execute program and check error	
					getError(-1, "execvp");
			}
			else { //Parent executes the waiting for the child process to finish
				int status = 0;
				pid_t process = waitpid(childProcess, &status, 0);
				getError(process, "wait");

				if (status == 0)
					printf("myshell: process %d ended correctely with status: %d \n", process, status);		
				else 
					printf("myshell: process %d ended incorrectely with status %d: %s\n", process, status, strsignal(status));
			}
		} 

		else if (strcmp(words[0],"kill") == 0){
			int process = kill((pid_t)atoi(words[1]), SIGKILL); //atoi() converts char into integer
			getError(process, "kill");

			if (process == 0)
				printf("myshell: process %d killed \n", atoi(words[1]));
		} 

		else if (strcmp(words[0],"stop") == 0){
			int process = kill((pid_t)atoi(words[1]), SIGSTOP); //atoi() converts char into integer
			getError(process, "stop");

			if (process == 0)
				printf("myshell: process %d stopped \n", atoi(words[1]));
		} 

		else if (strcmp(words[0],"continue") == 0){
			int process = kill((pid_t)atoi(words[1]), SIGCONT); //atoi() converts char into integer
			getError(process, "continue");

			if (process == 0)
				printf("myshell: process %d continue \n", atoi(words[1]));
		} 

		else {
			printf("myshell: command not found: %s\n", words[0]);
		}
	}
}

int main() {
  char buffer[MAX_CHAR];
  char *words[MAX_WORDS];

  while(1){
  	getPromptEntrance(buffer);
  	getWordsFromBuffer(buffer, words);
  	executeCommand(words);
  	sleep(1); //Wait last function finish before start loop again
  }

  return 0;
}
