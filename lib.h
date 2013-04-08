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

extern void myStrcpy(char *s, char *t, int n);
//tests:
//empty to non-empty
//non-empty to empty
//non-empty to non-empty, strlen(source)>=n
//non-empty to non-empty, strlen(source)<n


extern void myStrcat(char *s, char *t, int n);
//tests:
//non-empty to empty
//non-empty to non-empty, strlen(source)>=n
//non-empty to non-empty, strlen(source)<n


extern void mygetline(char *s);
//tests:
//get empty string
//get non-empty string
//more than 2 (non)empty strings are in input file


extern int myStrcmp(char *s, char *t, int n);
//tests:
//empty to empty
//empty to non-empty
//non-empty to non-empty with same prefix(prefix_length=n)
//non-empty to non empty with same prefix(prefix_length<n)

extern int myAtoi(char *s);
//tests:
//empty string
//non-empty string, but not INT value(some !isdigit() characters)
//non-empty string, INT value inside, probably "-"/"+" characters in front

extern void myItoa(int x, char *s) ;
//tests:
//big int values
//negative/positive values


extern void reverse(char *s) ;
//tests:
//non-empty string

extern int stridx(char c, char *s);
//test:
// '\0' in empty string
// '\0' in non-empty string
// character in non-empty string(character exist there)
// character in non-empty string(character does not exist there)


