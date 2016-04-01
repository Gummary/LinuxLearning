#include <stdio.h>
#define MAXSIZE 1024

void copy_n(char dst[], char src[], int n);

int main()
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char dst[MAXSIZE];
	int i = 1;
	for(;i<=30;i++)
	{
		copy_n(dst, src, i);
		printf("%s\n", dst);
	}
}

void copy_n(char dst[], char src[], int n)
{
	int i = 0;
	while(src[i]!='\0'&&i<n){
		dst[i] = src[i];
		i++;
	}
	if(i<n)
	{
		while(i<n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	dst[i] = '\0';
}
