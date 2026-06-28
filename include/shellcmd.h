#ifndef SHELLCMD_H
#define SHELLCMD_H

void myhelp();
void myCleawr();
void myPwd();
void myLs();
void myCd(const char *dirname);
void myEcho(const char *line);
void myCat(const char *filename);
void myExit(int *status);

#endif