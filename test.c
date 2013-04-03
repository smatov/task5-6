/*
 * test.c
 */

#include "lib.h"
#include <assert.h>

char* a;
char* b;
char* c;

void test_setup()
{
	b = malloc(sizeof(char) * 50);
	a = malloc(sizeof(char) * 50);
	c = malloc(sizeof(char) * 50);
}

void test1()
{
	//getline and atoi
	mygetline(a);
	int x = myAtoi(a);
	printf("str = %s\n", a);
	printf("int = %d\n", x);
}

void test2()
{
	//ITOA and REVERSE
	int f;
	scanf("%d", &f);
	mygetline(c);
	myItoa(f, b);
	printf("str = %s\n", b);
	reverse(b);
	printf("rev = %s\n", b);
}

void test3()
{
	//string index
	mygetline(c);
	char l;
	scanf("%c",&l);
	int idx=stridx(l,c);
	printf("idx = %d\n",idx);
}

void test4()
{
	//ITOA for 0
	int f = 0;
	myItoa(f, b);
	assert(b != 0);
	assert(strlen(b) == 1);
	assert(b[0] == '0');
}

void test_teardown()
{
	free(a);
	free(b);
	free(c);
}

int main() {
	test_setup();
	//test1();
	//test2();
	//test3();
	test4();
	test_teardown();
	return 0;
}
