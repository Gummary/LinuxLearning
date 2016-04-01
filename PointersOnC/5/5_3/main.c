#include <stdio.h>

unsigned int reversal_bit(unsigned int);

int main()
{
	unsigned int test = 25;
	printf("%u\n", reversal_bit(test));
	/*unsigned int test = 0;
	unsigned int one = 1;
	test = test ^ one;
	printf("%u\n", test);
	int i = 1;
	for(;i<=32;i++)
		printf("%u\n", test << i);
	*/	

}

unsigned int reversal_bit(unsigned int input)
{
	const unsigned int one = 1;
	unsigned int result = 0;
	int time = 1;
	while(input)
	{
		if(input&one) result = result ^ one;
		result = result << 1;
		input = input >> 1;
		//printf("%d : %u\n", time, result);
		time++;
	}
	return result << (32 - time);
}
