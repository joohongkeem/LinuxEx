#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

#define BUFSIZE 40

int main(void){
	int fd, nw, nr, i, j;
	char Buffer[40];
	char temp[40];
	fd = open("./stringtest.txt", O_RDWR | O_CREAT | O_TRUNC, \
	S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
	
	if(fd==-1)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	
	//출력할 문자열 : Do not count the eggs beore they hatch.
	sprintf(Buffer, "Do not count the beore they hatch.\n");
	write(fd, Buffer, strlen(Buffer));
	lseek(fd, 0, SEEK_SET);
	read(fd, Buffer, BUFSIZE);
	for(i = 0; i < strlen(Buffer); i++)
	{
		if(Buffer[i] == 't' && Buffer[i+1] == 'h' && Buffer[i+2] == 'e')
			break;
	}
	i+=4;
	j=0;

	lseek(fd, i, SEEK_SET);
	write(fd, "eggs ", 5);

	for(;i<strlen(Buffer);i++)
	{
		temp[j] = Buffer[i];
		j++;
	}

	write(fd, temp, strlen(temp));
	close(fd);
	return 0;	
}
