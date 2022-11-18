#include <stdio.h>

unsigned int mask(int n)
{
	unsigned int mask = 0xFFFFFFFF << n; //shifts the mask over n amount of insignifican bits so that it is the opposite of the desired number
	return ~mask; //flips the bits of the opposite so the desired number is achieved
}

int main()
{
	printf("0x%X\n",mask(1));
	printf("0x%X\n",mask(2));
	printf("0x%X\n",mask(3));
	printf("0x%X\n",mask(5));
	printf("0x%X\n",mask(8));
	printf("0x%X\n",mask(16));
	printf("0x%X\n",mask(31));
	return 0;
}

