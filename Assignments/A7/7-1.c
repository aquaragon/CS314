#include <stdio.h>

unsigned int getOffset(unsigned int address)
{
	unsigned int mask = 0x000000FF;
	return mask & address;

}

unsigned int getTag(unsigned int address)
{
	unsigned int mask = 0xFFFFF000;
	return (mask & address) >> 12;
}

unsigned int getSet(unsigned int address)
{
	unsigned int mask = 0x00000F00;
	return (mask & address) >> 8;
}

int main()
{      
	unsigned int add1 = 0x12345678;
	unsigned int add2 = 0x87654321;
	printf("0x%x: offset: %x - tag: %x - set : %x\n",add1,getOffset(add1),getTag(add1),getSet(add1));
	printf("0x%x: offset: %x - tag: %x - set : %x\n",add2,getOffset(add2),getTag(add2),getSet(add2));
	return 0;
}
