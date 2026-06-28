#include "iosize.h"
#include "shellcmd.h"
#include "shell.h"
#include "helper.h"
#include "color.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int startShell(){
    char input[INPUT_SIZE];

    getInput(input, sizeof(input));
    if(validateInput(input) == 1){
        return 0;
    }

    char *command = strtok(input, " ");
    char *arguement = strtok(NULL, " ");

    if (strcmp(command, "help") == 0){
        myHelp();
    }

    else if (strcmp(command, "clear") == 0){
        myClear();
    }

    else if (strcmp(command, "pwd") == 0){
        myPwd();
    }

    else if (strcmp(command, "ls") == 0){
        myLs();
    }

    else if (strcmp(command, "cd") == 0){
        myCd(arguement);
    }

    else if (strcmp(command, "echo") == 0){
        myEcho(arguement);
    }

    else if (strcmp(command, "cat") == 0){
        myCat(arguement);
    }

    else if (strcmp(command, "exit") == 0){
        return 1;
    }

    else {
        printf("%s: command not found\n\n", command);
    }
    
    return 0;
}

void getInput(char *input, int size){
    if(fgets(input, size, stdin) == NULL){
        return;
    }
    
    input[strcspn(input, "\n")] = '\0';
    return;
}

int setUsername(char *name, int size){
    printf("Enter Username: ");
    getInput(name, size);
    if(validateInput(name) == 1){
        printf("Username is empty!\n\n");
        return 1;
    }
    return 0;
}

void displayTitle(){
    printf("\033[2J\033[H");
    printf("Welcome to mokaShell v1.0.0!\n");
}

void displayPrompt(const char *username){
    char directory[OUTPUT_SIZE];
    getcwd(directory, sizeof(directory));
    printf(
        HGRN "%s@mokashell" RESET ":" 
        HCYN "%s" RESET "$ ", 
        username, 
        directory
    );
}