#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
	uid_t euid = geteuid();
	struct passwd* eusr;
	eusr = getpwuid(euid);
	printf("%s\n", eusr->pw_name);
	
}
