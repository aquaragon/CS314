#include <stdio.h>

unsigned int combine (unsigned int x, unsigned int y)
{
	unsigned int xmask = 0xFFFFFFFF << 8; //creates a mask of the x int by putting two zeroes in the first byte
	unsigned int ymask = 0xFFFFFFFF >> 24; //creates a mask of the y int by putting zeroes in the last three bytes

	return ((xmask & x) | (ymask & y)); //and's the bytes of the x_mask and x to in order grab the desired bytes from x, same with y, then combines the desired bytes from both y and x	
}

int main()
{
	printf("0x%X\n", combine(0x12345678, 0xABCDEF00));
	printf("0x%X\n", combine(0xABCDEF00, 0x12345678));
	return 0;
}
