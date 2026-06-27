#include "library.h"

int getInput(char *input, int size){
    if(fgets(input, size, stdin) == NULL){
        return 1;
    }
    
    input[strcspn(input, "\n")] = '\0';
    return 0;
}

void setUsername(char *name, int size, int *status){
    printf("Enter Username: "); 
    if(getInput(name, size) == 1){
        printf("Username is empty!\n");
        myExit(status);
    }
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