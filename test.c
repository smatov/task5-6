/*
 * test.c
 */

#include "lib.h"
#include <assert.h>

char* a;
char* b;
char* c;
char* d;
char* e;

void test_setup()
{
	b = malloc(sizeof(char) * 50);
	a = malloc(sizeof(char) * 50);
	c = malloc(sizeof(char) * 50);
	d = malloc(sizeof(char) * 100);
	e = malloc(sizeof(char) * 5);
}

void clear_all()
{
	memset(a,'\0',strlen(a));
	memset(b,'\0',strlen(b));
	memset(d,'\0',strlen(d));
	memset(e,'\0',strlen(e));
	memset(c,'\0',strlen(c));
}

void test_atoi_not_good_string()
{
	clear_all();
	//not int value in string for atoi
	strcpy(a,"142c123");
	int x;
	int f = myAtoi(a,&x);
	assert(f==-1);
}

void test_atoi_positive()
{
	clear_all();
	//positive int value in string for atoi
	a[0]='+';
	a[1]='1';
	int x;
	int f = myAtoi(a,&x);
	assert(x==1);
	assert(f==0);
	//accepted
}

void test_atoi_negative()
{
	clear_all();
	//negative int value in string for atoi
	a[0]='-';
	a[1]='2';
	int x;
	int f = myAtoi(a,&x);
	assert(x==-2);
	assert(f==0);
	//accepted
}

void test_atoi_empty()
{
	clear_all();
	//empty string 
	a[0]='\0';
	int x;
	int f=myAtoi(a,&x);
	assert(f==-1);
}

void test_cpy_empty()
{
	clear_all();
	//empty string to empty string with n>0
	int n=12;
	a[0]='\0';
	b[0]='\0';
	int f=myStrcpy(a,b,n);
	assert(strlen(a)==strlen(b));
	assert(strlen(a)==0);
	assert(f==0);
	//accepted
}

void test_cpy_nte()
{
	clear_all();
	//copy non-empty string to empty
	int n=12;
	a[0]='\0';
	b[0]='1';
	int f = myStrcpy(a,b,n);
	assert(strlen(a)==1);
	assert(f == 0);
	//accepted
}

void test_cpy_etn()
{
	clear_all();
	//copy empty string to non-empty
	int n=12;
	a[0]='\0';
	b[0]='1';
	int f=myStrcpy(b,a,n);
	assert(strlen(b)==0);
	assert(f==0);
	//accepted
}

void test_cpy_over()
{
	clear_all();
	//copy a long string to a smaller one
	int n=70;
	strcpy(e,"ajajajajaj");
	strcpy(d,"1234567890123456789012345678901234567890123456789012345678901234567890aaaaaaaaaaa");
	int f=myStrcpy(e,d,n);
	assert(f==-1);
	assert(strlen(e)==10);
	//accepted
}

void test_itoa_positive()
{
	clear_all();
	//positive int value
	int x=123;
	int f=myItoa(x,a);
	assert(strlen(a)==3);
	assert(a[0]=='1' && a[1]=='2' && a[2]=='3');
	assert(f==0);
	//accepted
		
}

void test_strcat_over()
{
	//very long string to very short string
	clear_all();
	int n=70;
	strcpy(e,"petya");
	strcpy(d,"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	int f = myStrcat(e,d,n);
	assert(f==-1);
	assert(strlen(e)==5);
}

void test_itoa_negative()
{
	clear_all();
	//negative int value
	int x=-980;
	int f = myItoa(x,a);
	assert(strlen(a)==4);
	assert(a[0]=='-' && a[1]=='9' && a[2]=='8' && a[3]=='0');
	assert(f == 0);
	//accepted
}

void test_itoa_bigvalue()
{
	clear_all();
	//big int value
	int x=1000000000;
	int f = myItoa(x,a);
	assert(strlen(a)==10);
	strcpy(b,"1000000000");
	assert(!strcmp(a,b));
	assert(f==0);
	//accepted
	
}




void test_reverse_empty()
{
	clear_all();
	//reverse of emtpy string
	a[0]='\0';
	reverse(a);
	assert(strlen(a)==0);
	assert(a[0]=='\0');
	//accepted
}

void test_reverse()
{
	clear_all();
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
	clear_all();
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
	clear_all();
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
	clear_all();
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
	clear_all();
	//compare 2 empty strings
	a[0]='\0';
	b[0]='\0';
	int x=myStrcmp(a,b,20);
	assert(x==0);
	//accepted
}

void test_strcmp_e1()
{
	clear_all();
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
	clear_all();
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

void test_strcmp_d()
{
	clear_all();
	//different strings
	strcpy(a,"lol");
	strcpy(b,"aol");
	int x=myStrcmp(a,b,3);
	assert(x==1);
	//accepted
	
}

void test_strcmp_same()
{
	clear_all();
	//same strings. n>strlen()
	strcpy(a,"abc");
	strcpy(b,"abc");
	int x=myStrcmp(a,b,5);
	assert(x==0);
	//accepted
}
void test_strcat_ete()
{
	clear_all();
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
	clear_all();
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
	clear_all();
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
	free(d);
	free(e);
}

void run_atoi_tests()
{
	//accepted
	test_atoi_positive();
	test_atoi_negative();
	test_atoi_empty();
	test_atoi_not_good_string();
}


void run_strcmp_tests()
{
	//accepted
	test_strcmp_same();
	test_strcmp_sp();
	test_strcmp_d();
	test_strcmp_e2();
	test_strcmp_e1();	
}

void run_itoa_tests()
{
	//accepted
	test_itoa_positive();
	test_itoa_negative();
	test_itoa_bigvalue();	
	test_itoa_zero();
}

void run_strcat_tests()
{
	//accepted
	test_strcat_ete();
	test_strcat_etn();
	test_strcat;
	test_strcat_over();
		
}

void run_strcpy_tests()
{
	//accepted
	test_cpy_over();
	test_cpy_etn();
	test_cpy_nte();
	test_cpy_empty();	
}

void run_reverse_tests()
{	
	//accepted
	test_reverse_empty();
	test_reverse();
}

void run_stridx_tests()
{	
	//accepted
	test_stridx();
	test_stridx_empty();
	
}

void run_all_tests()
{	
	//accepted
	run_strcmp_tests();
	run_itoa_tests();
	run_atoi_tests();
	run_strcpy_tests();
	run_stridx_tests();
	run_reverse_tests();
	run_strcat_tests();
}

int main() {
	test_setup();
	run_all_tests();
	test_teardown();
	return 0;
}
