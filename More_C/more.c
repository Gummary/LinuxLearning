#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#define MAXSIZE 1024
#define DEFAULT 10

void showTheFile(FILE *, int);
int getLineNum();

int main(int argc, char *argv[])
{
	FILE *fd = NULL;
	if(argc == 1)
		showTheFile(stdin, DEFAULT);
	else
	{
		int i = 1;
		for(;i<argc;i++)
		{
			fd = fopen(argv[i], "r");
			if(fd != NULL)
			{
				showTheFile(fd, DEFAULT);
			}
		}
	}
	return 0;
}

void showTheFile(FILE *fd, int linenum)
{
	char buff[MAXSIZE];
	int lnum = linenum;
	int  i = 0;
	while(1)
	{
		while(lnum--)
		{
			if(fgets(buff, MAXSIZE, fd)!=NULL)
			{
				int len = strlen(buff);
				buff[len-1] = '\0';
				printf("%s\n", buff);
			}
			else return;
		}
		printf("\033[33m --More-- \033[0m");
		lnum = getLineNum();
		if(lnum == 0) break;
	}
}

int getLineNum()
{
	char input = getchar();
	switch(input)
	{
		case 'q':
			return 0;
		case ' ':
			return DEFAULT;
		case '\n' :
			return 1;
	}
}

