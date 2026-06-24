#include <stdio.h>
#include <string.h>
#include "command.c"
#include "terminal.c"

#define USERNAME_SIZE 50

int main(void){
    int status = 1;
    char username[50];

    displayTitle();
    setUsername(username, sizeof(username), &status);
    myClear();

    while (status == 1){
        displayPrompt(username);
        terminalInteraction(&status);
    }
}