#ifndef SHELL_H
#define SHELL_H

int validateArguement(const char* arg, const char* cmd);

int startShell();
int getInput(char *input, int size);
int setUsername(char *name, int size);

void displayTitle();
void displayPrompt(const char *username);

#endif