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

void test_atoi_positive()
{
	//positive int value in string for atoi
	a[0]='+';
	a[1]='1';
	int x = myAtoi(a);
	assert(x==1);
	//accepted
}

void test_atoi_negative()
{
	//negative int value in string for atoi
	a[0]='-';
	a[1]='2';
	int x = myAtoi(a);
	assert(x==-2);
	//accepted
}

void test_cpy_empty()
{
	//empty string to empty string with n>0
	int n=12;
	a[0]='\0';
	b[0]='\0';
	myStrcpy(a,b,n);
	assert(strlen(a)==strlen(b));
	assert(strlen(a)==0);
	//accepted
}

void test_cpy_nte()
{
	//copy non-empty string to empty
	int n=12;
	a[0]='\0';
	b[0]='1';
	myStrcpy(a,b,n);
	assert(strlen(a)==1);
	//accepted
}

void test_cpy_etn()
{
	//copy empty string to non-empty
	int n=12;
	a[0]='\0';
	b[0]='1';
	myStrcpy(b,a,n);
	assert(strlen(b)==1);
	assert(b[0]=='1');
	//accepted
}

void test_itoa_positive()
{
	//positive int value
	int x=123;
	myItoa(x,a);
	assert(strlen(a)==3);
	assert(a[0]=='1' && a[1]=='2' && a[2]=='3');
	//accepted
		
}

void test_itoa_negative()
{
	//negative int value
	int x=-980;
	myItoa(x,a);
	assert(strlen(a)==4);
	assert(a[0]=='-' && a[1]=='9' && a[2]=='8' && a[3]=='0');
	//accepted
}

void test_reverse_empty()
{
	//reverse of emtpy string
	a[0]='\0';
	reverse(a);
	assert(strlen(a)==0);
	assert(a[0]=='\0');
	//accepted
}

void test_reverse()
{
	//non-empty string
	a[0]='1';
	a[1]='2';
	a[2]='3';
	reverse(a);
	assert(strlen(a)==3);
	assert(a[0]=='3' && a[1]=='2' && a[2]=='1');
	//accepted
}




void test_stridx()
{
	//non-empty char
	char l='g';
	a[0]='1';
	a[1]='g';
	a[2]='g';
	int idx=stridx(l,a);
	assert(idx==1);
	//accepted
}

void test_stridx_empty()
{
	//empty char
	char l='\0';
	a[0]='1';
	a[1]='g';
	a[2]='g';
	int idx=stridx(l,a);
	assert(idx==-1);
	//accepted
	
}

void test_itoa_zero()
{
	//ITOA for 0
	int f = 0;
	myItoa(f, b);
	assert(b != 0);
	assert(strlen(b) == 1);
	assert(b[0] == '0');
	//accepted
}

void test_strcmp_e2()
{
	//compare 2 empty strings
	a[0]='\0';
	b[0]='\0';
	int x=myStrcmp(a,b,20);
	assert(x==0);
	//accepted
}

void test_strcmp_e1()
{
	//compare an empty string and non-empty string
	a[0]='\0';
	b[0]='1';
	b[1]='a';
	int x=myStrcmp(a,b,20);
	assert(x==-1);
	//accepted
}

void test_strcmp_sp()
{
	//compare 2 strings with the same prefix
	//pref_len=2
	a[0]='1';
	a[1]='a';
	b[0]='1';
	b[1]='a';
	a[2]='s';
	b[2]='p';
	int x=myStrcmp(a,b,2);
	assert(x==0);
	//accepted
}

void test_strcat_ete()
{
	//strcat empty to empty string
	a[0]='\0';
	b[0]='\0';
	myStrcat(a,b,12);
	assert(strlen(a)==0 && strlen(b)==0);
	assert(a[0]=='\0');
	//accepted
}


void test_strcat_etn()
{
	//strcat empty to non-empty string
	a[0]='1';
	b[0]='\0';
	myStrcat(a,b,12);
	assert(strlen(a)==1 && strlen(b)==0);
	assert(a[0]=='1');
	//accepted
}

void test_strcat()
{
	//non-empty strcat to non-empty
	a[0]='1';
	a[1]='2';
	b[0]='f';
	b[1]='h';
	myStrcat(a,b,2);
	assert(strlen(a)==4);
	assert(a[0]=='1' && a[1]=='2' && a[2] == 'f' && a[3] == 'h');
	//accepted
}
void test_teardown()
{
	free(a);
	free(b);
	free(c);
}

int main() {
	test_setup();
	test_strcat();
	test_teardown();
	return 0;
}
