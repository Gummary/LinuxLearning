#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1024 

void copyfile(int, int);
void arguement_process(int, char **);
void copyFileWithnoTips(char **);
void copyFileWithTips(char **);
void oops(char *, char *);
void closeFile(int, int);
char buf[MAXSIZE];


int main(int argc, char *argv[])
{
	arguement_process(argc, argv);
//	if(access(argv[3], F_OK) == 0)
//	{
//		printf("cunzai\n");
//	}
//	int ffd = open(argv[2],O_RDONLY);	
//	int fd = creat(argv[3], 0644);
//
//	printf("%d %d\n", ffd, fd);
//	copyfile(ffd, fd);
//	close(fd);
//	close(ffd);

	return 0;
}
void arguement_process(int argc, char *argv[])
{
	if(argc<3)
		oops("Input wrong", "");

	if(argc == 3)
		copyFileWithnoTips(argv);

	if(argc == 4)
		copyFileWithTips(argv);
}

void copyFileWithTips(char *argv[])
{
	if(strcmp("-i", argv[1]) != 0)
		oops("Usage : cp2 [-i] file1 fil2", "");


	int ofd, nfd;	
	if((ofd = open(argv[2], O_RDONLY)) == -1)
		oops("Can not open", argv[2]);
	
	if(access(argv[3], F_OK) == 0)
	{
		printf("The %s already exist,do you want to overwrite it?[y/N]",argv[3]);
		char c;
		scanf("%c", &c);
		if(c != 'y'&& c != 'Y')
		{
			if(close(ofd) == -1)
				oops("Close file failed", argv[2]);
			exit(0);
		}
	}

	if((nfd = creat(argv[3], 0644))== -1)
		oops("Cannot creat file", argv[3]);
	copyfile(ofd, nfd);
	closeFile(ofd, nfd);
}

void copyFileWithnoTips(char *argv[])
{
	int ofd = -1, nfd = -1;
	if((ofd = open(argv[1], O_RDONLY)) == -1)
		oops("Can not open", argv[1]);
	
	if((nfd = creat(argv[2] ,0644)) == -1)
		oops("Can not creat", argv[2]);
	copyfile(ofd, nfd);
	closeFile(ofd, nfd);
}

void closeFile(int ofd, int nfd)
{
	if(close(ofd) == -1 | close(nfd) == -1)
		oops("Error closing files", "");
}

void copyfile(int ofd, int nfd)
{
	int len;
	while((len = read(ofd, buf, MAXSIZE)) > 0)
	{
		if(write(nfd, buf, len)!=len)
			oops("Write error to","");
	}
	
	if(len == -1)
		oops("Read error from", "");
}


void oops(char *s1, char *s2)
{
	printf("error occur\n");
	fprintf(stderr, "ERROR: %s", s1);
	perror(s2);
	exit(0);
}
