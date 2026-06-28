#include "iosize.h"
#include "shell.h"
#include "shellcmd.h"

int main(void){
    char username[USERNAME_SIZE];

    displayTitle();

    while(1){
        if(setUsername(username, sizeof(username)) == 1){
            continue;
        }
        break;
    }

    myClear();

    while (1){
        displayPrompt(username);
        if(startShell() == 1){
            myExit();
            break;
        }
        continue;
    }
}