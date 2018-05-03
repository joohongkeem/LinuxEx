#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

#define BUFSIZE 10

int main(void){
	int fd, nw, nr;
	char Buffer[10];
	char Buffer2[10];
	fd = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, \
	S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
	
	//fd를 복사한다.
	//stdin -> fd => 0
	//stdout -> fd => 1
	//stderr -> fd => 2
	
	//open을 하면 -> fd = 3

	if(fd==-1)
	{
		printf("FILE OPEN ERROR\n");
		return -1;
	}
	
	sprintf(Buffer, "test\n");

	write(1, Buffer, strlen(Buffer)); //fd가 1인것은 stdin이므로 printf를 사용한 것이다
	nw = write(fd, Buffer, strlen(Buffer)); //fd가 3인 text파일에 쓰기
	printf("write return value : %d\n", nw); //write의 리턴값인 버퍼 크기를 확인
	lseek(fd, 0, SEEK_SET); //파일의 SEEK_SET(처음위치)로 커서 이동, 리턴값은 커서 위치
	nr = read(fd, Buffer2, BUFSIZE); //파일을 읽는다.
	printf("read return value : %d\n", nr); //read의 리턴값인 버퍼의 크기를 확인
	printf("read Buffer : %s", Buffer2); //read한 버퍼의 내용을 출력

	printf("first fd : %d\n", fd); //fd는 3을 가리킨다
	close(fd); //3을 가리키는 fd를 없앤다


	fd = creat("./test2.txt", 0764); //creat하면 fd는 3을 가리킨다
	
	if(fd==-1)
	{
		printf("FILE CREAT ERROR\n");
		return -1;
	}
	printf("second fd : %d\n", fd);
	close(fd);
	return 0;	

}
