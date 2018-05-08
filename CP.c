#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int fd1, fd2;
	int rfd1;
	char Buf[BUFSIZE];

	if(argc < 3)
	{
		perror("Usage : copy file1 file2\n");
		return -1;
	}

	if((fd1 = open(argv[1], O_RDONLY)) < 0)
	{
		perror(argv[1]);
		return -1;
	}

	if((fd2 = open(argv[2], O_WRONLY | O_CREAT | \
        S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)) < 0) //O_NBLOCK <-> O_RDWR
        {
                perror(argv[2]);
                return -1;
        }

	while((rfd1 = read(fd1, Buf, sizeof(Buf))) > 0)
		write(fd2, Buf, rfd1);
	close(fd1);
	close(fd2);
	return 0;
}
