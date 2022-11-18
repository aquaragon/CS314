#include <stdio.h>


unsigned int replace (unsigned int x, int i, unsigned char b)
{
	unsigned int shift = i << 3; //converts byte location into amount of bits
	unsigned int mask1 = b << shift; //create mask1 to format the b char as an UI so that it can be properly compared to the second mask
	unsigned int mask2 = ~(0xFF << shift); //isolotes the byte location for x that we want to preserve so that it can be compared to the first mask
	return (mask1 | (mask2 & x)); //combines the mask of b(mask1, the replaced byte) with the 2nd mask which returns the final expression


}

int main()
{
	printf("0x%X\n", replace(0x12345678, 3, 0xAB));		
	printf("0x%X\n", replace(0x12345678, 0, 0xAB));		
	return 0;

}
