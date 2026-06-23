#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 100

int getInput(char *input, int size){
    if(fgets(input, size, stdin) == NULL){
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    return 0;
}

void setUsername(char *name, int size, int *status){
    printf("Enter Username: "); 
    if(getInput(name, size)){
        myExit(status);
    }
}

void displayTitle(){
    myClear();
    printf("Welcome to mokaShell!\n");
}

void terminalPrompt(const char *username){
    printf("%s@mokaShell:~$ ", username);
}

char* parseInput(char *input){
    return strtok(input, " ");
}

void terminalInteraction(int *status){
    char input[INPUT_SIZE];
    char *command;
    char *aftercommand;

    if(getInput(input, sizeof(input))){
        myExit(status);
    }

    command = parseInput(input);
    aftercommand = command + strlen(command) + 1;
    
    if (strcmp(command, "help") == 0){
        myHelp();
    }

    if (strcmp(command, "echo") == 0){
        myEcho(aftercommand);
    }

    else if (strcmp(command, "clear") == 0){
        myClear();
    }

    else if (strcmp(command, "exit") == 0){
        myExit(status);
    }

    else{
        printf("\nCommand not Found!\n\n");
    }
}