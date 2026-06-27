#include "library.h"

void terminalInteraction(int *status){
    char input[INPUT_SIZE];

    if(getInput(input, sizeof(input)) == 1){
        myExit(status);
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
        myExit(status);
    }

    else {
        printf("%s: command not found\n", command);
    }
}