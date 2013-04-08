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
#include <malloc.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX_INT 2147483647

int myStrcpy(char *s, char *t, int n) {
	if (!*t) {
		*s = *t;
		return 0;
	}
	if (malloc_usable_size(s) < MIN(strlen(t), n) + strlen(s))
		return -1;
	while (*t && n > 0) {
		*s = *t;
		s++;
		t++;
		n--;
	}
	*s = '\0';
	return 0;
}
int myStrcat(char *s, char *t, int n) {
	if (malloc_usable_size(s) < MIN(strlen(t), n) + strlen(s))
		return -1;
	while (*(s))
		s++;

	while (*t && n > 0) {
		*s = *t;
		s++;
		t++;
		n--;
	}
	return 0;

}

void mygetline(char *s) {
	char c;
	while ((c = getchar()) != EOF && c != '\n') {
		*s = c;
		s++;
	}
}
int myStrcmp(char *s, char *t, int n) {
	int i;
	if (n == 0)
		return 0;
	for (i = 0; i < n; i++) {
		if (*s != *t) {
			if (*s - *t > 0)
				return 1;
			if (*s - *t < 0)
				return -1;
			return 0;
		}
		if (*s == '\0')
			return 0;
		s++;
		t++;
	}
	s--;
	t--;
	if (*s - *t > 0)
		return 1;
	if (*s - *t < 0)
		return -1;
	return 0;

}

int myAtoi(char *s, int *ans) {
	long int tmp = 0;
	int sg = 1;
	if (*s == '\0') {
		return -1;
	}
	if (*s == '-') {
		if(strlen(s)>10) return -1;
		sg = -1;
		s++;
	} else
	if (*s == '+') {
		if(strlen(s)>10) return -1;
		sg = 1;
		s++;
	} else
		if(strlen(s)>=10) return -1;
	while (*s != '\0') {
		tmp *= 10;
		if (!isdigit(*s)) {
			return -1;
		}
		tmp += *s - '0';
		s++;
	}
	if(tmp>MAX_INT) return -1;
	*ans = tmp * sg;

	return 0;
}
int myItoa(int x, char *s) {
	int sg = 1;
	char *t;
	t = s;
	if (x < 0) {
		x *= -1;
		sg = -1;
	}

	int tsize=0;
	int tmp=x;
	do {
		tsize++;
		tmp/=10;
	} while (tmp>0);
	if(tsize-MIN(sg,0)>malloc_usable_size(s)) return -1;
	//useless condition cause malloc_usable_size
	//returns 12 bytes ever for malloc(sizeof(char))
	*s = '0';
	while (x > 0) {
		*s = x % 10 + '0';
		x /= 10;
		s++;
	}
	if (sg < 0)
		*s = '-';
	reverse(t);
	return 0;
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
		cnt -= 2;
	}
}

int stridx(char c, char *s) {
	int ans = 0;
	while (*s != c) {
		s++;
		ans++;
	}
	if (*s == '\0')
		return -1;
	return ans;

}

#ifndef TEST
int main() {
	char *b = malloc(sizeof(char) * 5);
	char *a = malloc(sizeof(char));
	char *c = malloc(sizeof(char) * 50);
	int t;
	scanf("%d",&t);
	int f=myItoa(t,a);
	printf("%d\n", f);
	printf("%s\n", a);
	printf("%d\n",malloc_usable_size(a));
	free(a);
	free(b);
	free(c);
	return 0;

}
#endif
