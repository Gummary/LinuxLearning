#include <stdio.h>

int stroe_bit_field(int ov, int v2s, unsigned start, unsigned end);

int main()
{
	printf("0x%x\n",stroe_bit_field(0x0, 0x1, 4, 4));
	return 0;
}

int stroe_bit_field(int ov, int v2s, unsigned start, unsigned end)
{
	const int one = 1;
	int onenum = start - end + 1;
	int mask = 0x0;
	 int i = 0;
	 while(i<onenum)
	 {
		 mask = mask << one;
		 mask = mask ^ one;
		 i++;
	 }
	 mask = mask << end;
	 ov = (~mask) & ov;
	 v2s = v2s << end;
	 v2s = v2s & 0xffff;
	 v2s = v2s & mask;
	 return v2s | ov;
}

