#include <stdio.h>

long f (long x, long y, long z)
{
	z += y;
	x *= z;
	z <<= 63;
	z >>= 63;
	long end = x;
	end ^= z;
	return end;
}

int main()
{
	printf("%ld\n", f(1,2,4));
	printf("%ld\n", f(3,5,7));
	printf("%ld\n", f(10,20,30));
	return 0;
}
