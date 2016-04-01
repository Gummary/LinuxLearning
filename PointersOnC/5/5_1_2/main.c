#include <stdio.h>

char upper2lower(char);
char encryption(char);

int main()
{
	char ch;
	while(ch = getchar())
	{
		if(ch == '\n') continue;
		if(ch <= 'Z' && ch >= 'A') printf("%c",encryption(ch));
		else printf("%c", ch);
	}
	return 0;
}


char upper2lower(char input)
{
	return input + 'a' - 'A';
}

char encryption(char input)
{
	return input + 13 > 'Z'? input -13 : input + 13;
}
