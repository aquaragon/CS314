#include <stdio.h>

long fact(long x) 
{
	 if (x <= 1) {
		 return 1;
	 }
	 return x * fact(x - 1);
}

int main ()
{
	printf("%ld\n",fact(1));
	printf("%ld\n",fact(3));
	printf("%ld\n",fact(5));
	return 0;
}

//instructions that modify the stack pointer:
//call fact
//ret 
//pushq %rbx
//popq %rbx

//the size of the stack frame will be 8 bytes because it returns a pointer 
