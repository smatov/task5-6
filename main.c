/*
 * main.c
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

void myStrcpy(char *s, char *t, int n) {
	while (*s && *t && n > 0) {
		*s = *t;
		s++;
		t++;
		n--;
	}
}
void myStrcat(char *s, char *t, int n) {
	while (*(s))
		s++;
	while (*t && n > 0) {
		*s = *t;
		s++;
		t++;
		n--;
	}
}

void mygetline(char *s) {
	char c;
	while ((c = getchar())!=EOF && c != '\n') {
		*s = c;
		s++;
	}
}
int myStrcmp(char *s, char *t, int n) {
	int i;
	if (n == 0)
		return 0;
	for (i = 0; i < n; i++) {
		if (*s != *t)
			break;
		if (*s == '\0')
			return 0;
		s++;
		t++;

	}
	if (*s - *t > 0)
		return 1;
	else
		return -1;
}

int myAtoi(char *s) {
	int ans = 0;
	while (*s != '\0') {
		ans *= 10;
		ans += *s - '0';
		s++;
	}
	return ans;
}
void myItoa(int x, char *s) {
	int tmp = 10;
	while (tmp < x)
		tmp *= 10;
	tmp /= 10;
	while (x > 0) {
		*s = x / tmp + '0';
		x %= tmp;
		tmp /= 10;
		s++;
	}
}
void reverse(char *s) {
	int cnt = 0;
	char *t;
	t = s;
	while (*t) {
		cnt++;
		t++;
	}
	while (cnt > 0) {
		char tmp;
		tmp = *s;
		*s = *(s + cnt - 1);
		*(s + cnt - 1) = tmp;
		s++;
		cnt-=2;
	}
}

int stridx(char c, char *s){
	int ans=0;
	while(*s!=c)
		{
			s++;
			ans++;
		}
	if(*s=='\0') return -1;
	return ans;

}

#ifndef TEST
int main() {
	char *b = malloc(sizeof(char) * 50);
	char *a = malloc(sizeof(char) * 50);
	char *c = malloc(sizeof(char) * 50);
	//getline and atoi
	mygetline(a);
	int x = myAtoi(a);
	printf("%s\n", a);
	printf("%d\n", x);
	//ITOA and REVERSE
	int f;
	scanf("%d", &f);
	myItoa(f, b);
	printf("%s\n", b);
	reverse(b);
	printf("%s\n", b);
	
	//string index
	mygetline(c);
	mygetline(c);
	char l;
	scanf("%c",&l);
	int idx=stridx(l,c);
	printf("%d\n",idx);
	free(a);
	free(b);
	free(c);
	return 0;

}
#endif //TEST
