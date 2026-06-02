#include <stdio.h>

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

void myExit(int *status){
    printf("\nExiting Terminal...\n");
    printf("Thank you for using mokaShell!\n\n");
    *status = 0;
}
