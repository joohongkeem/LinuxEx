#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern int **environ;

int main(int arg, char *argv[])
{
	char *p;
	int len;

	if(arg != 1)
	{
		len = strlen(getenv("FILEDIR")) + strlen(getenv("FILENAME")) + strlen(argv[1]) + 8;
		p = (char *)malloc(sizeof(char)*len);
		sprintf(p, "gcc -o %s %s%s", argv[1], getenv("FILEDIR"), getenv("FILENAME"));
		system(p);
		free(p);
	}
	else
	{
		len = strlen(getenv("FILEDIR")) + strlen(getenv("FILENAME")) + 12;
		p = (char *)malloc(sizeof(char)*len);
		sprintf(p, "gcc -o %s %s%s", "temp", getenv("FILEDIR"), getenv("FILENAME"));
		system(p);
		free(p);
	}
	return 0;
}
