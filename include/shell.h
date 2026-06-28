#ifndef SHELL_H
#define SHELL_H

int startShell();
void getInput(char *input, int size);
int setUsername(char *name, int size);

void displayTitle();
void displayPrompt(const char *username);

#endif