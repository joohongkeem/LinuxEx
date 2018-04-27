#include<stdio.h>

void increaseNum()
{
	static int num = 0;
	printf("%d\n", num);
	num++;
}

int main(void)
{
	increaseNum();
	increaseNum();
	increaseNum();
	increaseNum();

	return 0;
}
