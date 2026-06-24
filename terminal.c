#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define INPUT_SIZE 200
#define OUTPUT_SIZE 200


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

void displayPrompt(const char *username){
    char directory[OUTPUT_SIZE];
    getcwd(directory, sizeof(directory));
    printf("%s@mokaShell:%s$ ", username, directory);
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

    if (strcmp(command, "pwd") == 0){
        myPwd();
    }

    else if (strcmp(command, "echo") == 0){
        myEcho(aftercommand);
    }

    else if (strcmp(command, "cat") == 0){
        myCat(aftercommand);
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