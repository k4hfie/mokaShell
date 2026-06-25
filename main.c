#include "library.h"
#include "command.c"
#include "function.c"
#include "terminal.c"

int main(void){
    int status = 0;
    char username[USERNAME_SIZE];

    displayTitle();
    setUsername(username, sizeof(username), &status);
    myClear();

    while (status == 0){
        displayPrompt(username);
        terminalInteraction(&status);
    }
}