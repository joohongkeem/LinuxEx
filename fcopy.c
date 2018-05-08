#include<stdio.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int byteCount;
	FILE *fd1, *fd2;
	char buf[BUFSIZE];

	if(argc!=3) //실행 파라미터 갯수
	{
		//write(2, "Usage : fcopy file1 file2\n", 25); 동일
		fprintf(stderr, "Usage : fcopy file1 file2\n");
		return -1;
	}
		
	if((fd1 = fopen(argv[1], "r")) == NULL) //1번째 파일 오픈
	{
		perror(argv[1]);
		return -1;
	}

	if((fd2 = fopen(argv[2], "w")) == NULL) //2번째 파일 오픈
	{
		perror(argv[2]);
		return -1;
	}
	
	while((byteCount = fread(buf, sizeof(char), BUFSIZE, fd1)) > 0)
		fwrite(buf, sizeof(char), byteCount, fd2);

	fclose(fd1);
	fclose(fd2);
	return 0;
}
