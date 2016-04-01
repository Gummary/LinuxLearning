#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define MAXSIZE 1024 

int iscommon(char *s1, char *s2);
void copyfile(int, int, char *);

int main(int argc, char *argv[])
{
	if(argc < 3){
		printf("arguement is wrong\n");
		return 0;
	}
	if(iscommon(argv[1], argv[2])){
		printf("arguement is different\n");
		return 0;
	}
	
	int ofd = open(argv[1], O_RDONLY);
	if(ofd == -1){
		printf("open old file failed\n");
		return 0;
	}
	int nfd = creat(argv[2],0644);
	if(nfd == -1){ 
		printf("open old file failed\n");
		return 0;
	}
	char buf[MAXSIZE];
	copyfile(ofd, nfd, buf);
	return 0;
}

int iscommon(char *s1, char *s2)
{
	if(strlen(s1) != strlen(s2)) return 0;
	int len = strlen(s1);
	int i = 0;
	for(;i<len;i++)	if(s1[i]!=s2[i]) return 0;
	
	return 1;
}

void copyfile(int ofd, int nfd, char *buf)
{
	size_t len;
	while(len = read(ofd, buf, MAXSIZE))
	{
		write(nfd, buf, len);
	}
}
