/*
 * lib.h
 *
 * Created on: 26.03.2013
 * Author: dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

extern myStrcpy(char *s, char *t, int n);

extern void myStrcat(char *s, char *t, int n);

extern void mygetline(char *s);

extern int myStrcmp(char *s, char *t, int n);

extern int myAtoi(char *s);

extern void myItoa(int x, char *s) ;

extern void reverse(char *s) ;

extern int stridx(char c, char *s);

