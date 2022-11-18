#include <stdio.h>

int oddBit(unsigned int x)
{
	unsigned int y = x & 0xAAAAAAAA; //and's x with A because A has a one at every odd location
	return (y || 0); //logical comparison of previous result with zero, if there was ever a one at an odd location it returns one
}

int main()
{
	printf("%x\n", oddBit(0x1));
	printf("%x\n", oddBit(0x2));
	printf("%x\n", oddBit(0x3));
	printf("%x\n", oddBit(0x4));
	printf("%x\n", oddBit(0xFFFFFFFF));
	printf("%x\n", oddBit(0xAAAAAAAA));
	printf("%x\n", oddBit(0x55555555));

	return 0;
}
