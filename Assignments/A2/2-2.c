#include <stdio.h>

unsigned int extract (unsigned int x, int i)
{
	unsigned int mask = 0x000000FF; //creates a mask in the least two significant bit locations
	unsigned int shift = x >> (i << 3); //shifts over the desired byte from the passed in number to the least significant bit location  
	mask = mask & shift; //ands the desired byte in order to save it from passed in number and clears the other bytes  
	signed int twos_comp = mask << 24; //makes a signed from previous int so that the leading sign can be extended 
	return (twos_comp >> 24); //extends the sign bit to fill the rest of the 32 bits

}

int main ()
{
	printf("0x%.8X\n",extract(0x12345678, 0));
	printf("0x%.8X\n",extract(0xABCDEF00, 2));
	return 0;
}
