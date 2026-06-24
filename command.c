#include <stdio.h>
#include <unistd.h>
#define OUTPUT_SIZE 200

void myHelp(){
    printf("\nCommand List:\n");
    printf("    1. clear : clear terminal\n");
    printf("    2. pwd   : print working directory\n");
    printf("    3. cd    : change directory\n");
    printf("    4. echo  : print line\n");
    printf("    5. ls    : list files and directories\n");
    printf("    6. cat   : read file\n");
    printf("    7. exit  : exit teriminal\n\n");
}

void myClear(){
    printf("\033[2J\033[H");
}
void myPwd(){
    char pwd[OUTPUT_SIZE];
    getcwd(pwd, sizeof(pwd));
    printf("%s\n\n", pwd);
}

void myEcho(char* line){
    printf("%s\n", line);
}

void myCat(char* line){
    FILE *fp;
    fp = fopen(line, "r");
    char output[OUTPUT_SIZE];

    if (fp == NULL){
        printf("Could not open file\n");
    }
    
    while (fgets(output, sizeof(output), fp) != NULL){
        printf("%s", output);
    }   printf("\n\n");
}

void myExit(int *status){
    printf("\nExiting Terminal...\n");
    printf("Thank you for using mokaShell!\n\n");
    *status = 0;
}