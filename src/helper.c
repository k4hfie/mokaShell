#include "helper.h"
#include <stdio.h>

int validateArguement(const char *arg, const char *cmd){
    if (arg == NULL || arg[0] == '\0'){
        printf("%s: argument not found\n\n", cmd);
        return 1;
    }
    return 0;
}

int validateInput(const char *input){
    if (input == NULL || input[0] == '\0'){
        return 1;
    }
    return 0;
}