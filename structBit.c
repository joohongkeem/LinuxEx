#include<stdio.h>

struct Test{
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 7;
};

struct Test2{
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 13;
};

int main(void)
{
	struct Test t;
	struct Test2 t2;
	
	printf("%ld\n", sizeof(t));
	printf("%p\n", &t);
	printf("%ld\n", sizeof(t2));
	printf("%p\n", &t2);
	return 0;
}
