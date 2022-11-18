#include <stdio.h>

void printBytes(unsigned char *start, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt (int x)
{
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x)
{
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x)
{
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x)
{
	printBytes((unsigned char *) &x, sizeof(long));
}

void printLongLong(long long x)
{
	printBytes((unsigned char *) &x, sizeof(long long));

}

void printDouble(double x)
{
	printBytes((unsigned char *) &x, sizeof(double));
}


int main()
{
	printInt(4);
	printFloat(4);
	printShort(4);
	printLong(4);
	printLongLong(4);
	printDouble(4);
	return 0;
	//longlong and long are the same because becuase my input is the same and the value is too small for the data types to have any discrepency
	//the length of the outputs represent the size that each data type takes up in memory
	//float and double are differnt than the others becuase they have to take in account of decimals and using IEE notation	
}
