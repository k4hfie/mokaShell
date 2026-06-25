#include "library.h"

int checkArguement(const char *arg){
    if (arg == NULL || arg[0] == '\0'){
        printf("Argument missing!\n\n");
        return 1;
    }
    return 0;
}

void myHelp(){
    printf("\nCommand List:\n");
    printf("    1. help  : print command list\n");
    printf("    2. clear : clear terminal\n");
    printf("    3. pwd   : print working directory\n");
    printf("    4. ls    : list files and directories\n");
    printf("    5. cd    : change directory\n");
    printf("    6. echo  : print line\n");
    printf("    7. cat   : read file\n");
    printf("    8. exit  : exit teriminal\n\n");
}

void myClear(){
    printf("\033[2J\033[H");
}

void myPwd(){
    char pwd[OUTPUT_SIZE];
    getcwd(pwd, sizeof(pwd));
    printf("%s\n\n", pwd);
}

void myLs(){
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(".")) == NULL){
        perror("ls");
        printf("\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL){
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            printf("%s ", entry->d_name);
        }   
    }
    printf("\n\n");
    
    closedir(dir);
}

void myCd(const char *dirName){
    if (checkArguement(dirName) == 1){
        return;
    }
    
    if (chdir(dirName) != 0){
        perror("cd");
        printf("\n");
    }
}

void myEcho(const char *line){
    if (checkArguement(line) == 1){
        return;
    }

    printf("%s\n\n", line);
}

void myCat(const char *fileName){
    if (checkArguement(fileName) == 1){
        return;
    }

    FILE *fp;
    fp = fopen(fileName, "r");
    char output[OUTPUT_SIZE];

    if (fp == NULL){
        perror("cat");
        printf("\n");
        return;
    }
    
    while (fgets(output, sizeof(output), fp) != NULL){
        printf("%s", output);
    }   printf("\n\n");

    fclose(fp);
}

void myExit(int *status){
    *status = 1;
    printf("\nExiting Terminal...\n");
    printf("Thank you for using mokaShell!\n\n");
}