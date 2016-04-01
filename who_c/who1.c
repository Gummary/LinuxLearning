#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST
void show_info(struct utmp*);
void show_time(long);
struct utmp* getNext();
void openUtmp();
int storeUtmp();
void closeUtmp();



int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		if(strcmp(argv[1], "am") !=0) return 0;
		if(strcmp(argv[2], "i") !=0) return 0;
	}

	struct utmp *currentrecord;
	openUtmp();
	while(1){
		currentrecord = getNext();
		if(currentrecord == NULL) break;
		show_info(currentrecord);
	}
	closeUtmp();

	return 0;
}

void show_info(struct utmp *utbufp)
{
	if(utbufp->ut_type != USER_PROCESS) return;

	printf("% -8.8s", utbufp->ut_user);
	printf(" ");
	printf("% -8.8s", utbufp->ut_line);
	printf(" ");
	show_time(utbufp->ut_time);	

#ifdef SHOWHOST
	printf("(%s)", utbufp->ut_host);
#endif
	printf("\n");
}

void show_time(long ltime)
{
	char * cp;
	cp = ctime(&ltime);
	printf("%12.12s", cp+4);
}
