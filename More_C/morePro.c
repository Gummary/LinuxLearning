#include <stdio.h>
#include <sys/stat.h>
#include <termios.h>
#include <string.h>
#define MAXSIZE 1024
#define DEFAULT 10

void showTheFile(FILE *, int);
int getLineNum(FILE *, long, long);
void changeMode(int);
long getInputSize(FILE *);

int main(int argc, char *argv[])
{
	FILE *fd = NULL;
	if(argc == 1)
		showTheFile(stdin, DEFAULT);
	else
	{
		
		while(--argc)
		{
			fd = fopen(* ++argv, "r");
			if(fd != NULL)
			{
				showTheFile(fd, DEFAULT);
				fclose(fd);
			}
			else break;
		}
	}
	return 0;
}

void showTheFile(FILE *fd, int linenum)
{
	char buff[MAXSIZE];
	int  i = 0;
	FILE *fdin = fopen("/dev/tty", "r");
	long total = getInputSize(fd);
	long readsize = 0;
	if(fdin == NULL) return;

	while(fgets(buff, MAXSIZE, fd)!=NULL)
	{
		if(i == DEFAULT)
		{
			linenum = getLineNum(fdin, total, readsize);
			changeMode(1);
			if(linenum == 0) break;
			i-=linenum;
		}
		readsize+=strlen(buff);
		if(!fputs(buff, stdout)) break;
		i++;
	}
}
int getLineNum(FILE *fdin, long total, long readsize)
{
	double result = (double)readsize/(double)total;
	result*=100;
	printf("\033[33m --More--(%d%) \033[0m", (int)result);
	char input;
	changeMode(0);
	while((input = getc(fdin))!=EOF)
	{
		int i;
		switch(input)
		{
			case 'q':
				return 0;
			case ' ':
				return 10;
			case '\n' :
				return 1;
		}
	}
}

void changeMode(int mode)
{

	struct termios new;
	struct termios old;
	tcgetattr(0,&old);
	new = old;

	new.c_lflag &= ~(ICANON | ISIG);
	new.c_cc[VTIME] = 0;
	new.c_cc[VMIN] = 1;
	if(mode == 0) new.c_lflag &= ~ECHO;
	if(mode == 1) new.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &new);
}

long getInputSize(FILE *input)
{
	long size;
	fseek(input, 0L, SEEK_END);
	size = ftell(input);
	rewind(input);
	return size;
}
