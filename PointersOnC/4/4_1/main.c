#include <stdio.h>

int main()
{
	double n;
	double pre = 1;
	double now = 1; 
	enum { FITRST, NOT}status;
	status = FITRST;
	scanf("%lf", &n);
	do{
		pre = now;
		now = (pre + n/pre)/2;
	}while(pre!=now);
	printf("%lf\n",now); 
	return 0;
}
