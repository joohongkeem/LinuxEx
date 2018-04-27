#include<stdio.h>
#include<string.h>

#define DEBUG

int main(void)
{
	int t, i;
	char str[51];
	int strsize;
	
	scanf("%s", str);

#ifdef DEBUG
	printf("%s\n", str);
#endif

	for(i=0; i<strlen(str); i++)
	{
		if(!(str[i] >= 'a' && str[i] <= 'z'))
		{
			printf("Error : strInput\n");
			return -1;
		}
	}
#ifdef DEBUG
	printf("strInput Ok\n");
#endif
}
