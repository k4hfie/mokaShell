#ifndef SHELLCMD_H
#define SHELLCMD_H

void myHelp();
void myClear();
void myPwd();
void myLs();
void myCd(const char *dir);
void myEcho(const char *line);
void myCat(const char *filename);
void myExit();

#endif