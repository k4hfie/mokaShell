#include "iosize.h"
#include "shellcmd.h"
#include "helper.h"

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

void myHelp(){
    printf("Command List:\n");
    printf("    1. help  : print command list\n");
    printf("    2. clear : clear terminal\n");
    printf("    3. pwd   : print working directory\n");
    printf("    4. ls    : list files and directories\n");
    printf("    5. cd    : change directory\n");
    printf("    6. echo  : print line\n");
    printf("    7. cat   : read file\n");
    printf("    8. exit  : exit terminal\n\n");
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

void myCd(const char *dir){
    if (validateInput(dir) == 1){
        char *homeDir = getenv("USERPROFILE");
        if(validateInput(homeDir) == 1){
            printf("cd: home enviroment variable not found\n\n");
            return;
        }

        if (chdir(homeDir) != 0){
            perror("cd");
            printf("\n");
        }

        return;
    }
    
    if (chdir(dir) != 0){
        perror("cd");
        printf("\n");
    }
}

void myEcho(const char *line){
    if (validateArguement(line, "echo") == 1){
        return;
    }

    printf("%s\n\n", line);
}

void myCat(const char *fileName){
    if (validateArguement(fileName, "cat") == 1){
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

void myExit(){
    printf("\nExiting Terminal...\n");
    printf("Thank you for using mokaShell!\n\n");
}