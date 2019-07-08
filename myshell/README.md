# myshell.c
 C program that simulates Linux shell using system calls and error verification. Developed at MATA58 - OPERATING SYSTEMS at Federal University of Bahia. 
 
 To execute the program:
```c
$ gcc -o myshell myshell.c
$ ./myshell
```

As chamadas de sistema que foram utilizadas foram: fork, execvp, wait, waitpid, kill, exit, printf, fgets, strtok, strcmp, strsignal e atoi.

A função void getError(int status, char *nameSystemCall) recebe o status que cada chamada de sistema retorna e o nome da chamada de sistema para checar os possíveis erros gerados. Essa decisão foi tomada visando a não repetição de código, já que a cada chamada de sistema uma verificação de erro deve ser feita. Já a função void getPromptEntrance (char *buffer) é responsável por imprimir o prompt (“myshell: ”), receber os comandos digitados pelo usuário e salvar na variável char *buffer, além de verificar se um EOF foi encontrado para parar a execução do programa. A função void getWordsFromBuffer(char *buffer, char **words) é responsável por transformar a string armazenada em char *buffer em um vetor de palavras que será guardado em char **words. A função void executeCommand(char **words) verifica qual foi o comando digitado pelo usuário e executa a função correspondente através das chamadas de sistema.

Na função main() foram realizados 4 passos dentro de um laço de repetição. Essa decisão foi tomada visando uma maior legibilidade do código e uma maior modularização das funções:

```c
while(1){
      getPromptEntrance(buffer);
      getWordsFromBuffer(buffer, words);
      executeCommand(words);
      sleep(1); //Wait last function finish before start loop again
  }
```
