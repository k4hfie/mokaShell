#include "iosize.h"
#include "shell.h"

int main(void){
    int status = 0;
    char username[USERNAME_SIZE];

    displayTitle();
    setUsername(username, sizeof(username));
    myClear();

    while (status == 0){
        displayPrompt(username);
        terminalInteraction(&status);
    }
}