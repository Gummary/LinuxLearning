#include <stdio.h>
#include <fcntl.h>

int main()
{
	char buf[50];
	int fd1, fd2, fd3;
	fd1 = open("empty", O_RDONLY);
	fd2 = open("empty", O_WRONLY);
	fd3 = open("empty", O_RDONLY);
	if(fd1 == -1 | fd2 == -1 | fd3 == -1)
	{
		perror("open file error");
		return 0;
	}
	if(read(fd1, buf, 20) == -1)
	{
		perror("first read file error");
		return 0;
	}
	printf("The first read : %s\n", buf);

	if(write(fd2, buf, 20) == -1)
	{
		perror("write file error");
		return 0;
	}
	
	if(read(fd2, buf, 20) == -1)
	{
		perror("second read file error");
		return 0;
	}
	printf("The second read : %s\n", buf);



}
