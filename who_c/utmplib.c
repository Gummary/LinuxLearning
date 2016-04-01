#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <utmp.h>
#define UTMPSIZE sizeof(struct utmp)
#define STORESIZE 6

static int utmpfd;
static struct utmp utmpstore[STORESIZE];
static int index = 0;
static int getnum = 0;

int storeUtmp()
{
	int num = read(utmpfd, utmpstore, UTMPSIZE * STORESIZE);
	index = 0;
	return getnum = num/UTMPSIZE;
}

int openUtmp()
{
	utmpfd = open(UTMP_FILE, O_RDONLY);
	return 0;
}

struct utmp* getNext()
{
	if(utmpfd == -1) return (struct utmp*)NULL;
	if(getnum == index&&storeUtmp() == 0) return ((struct utmp*)NULL);
	
	struct utmp* temp = &utmpstore[index];
	index++;
	return temp;
}

void closeUtmp()
{
	if(utmpfd != -1) close(utmpfd);
}

	
