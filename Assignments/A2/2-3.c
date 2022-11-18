#include <stdio.h>

int le(float x, float y)
{
	unsigned int ux = *((unsigned int *) &x); // convert x raw bits
	unsigned int uy = *((unsigned int *) &y); // convert y raw bits
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy 
	return ((sx == 1 && sy == 0) ||( sy == 0 && (ux <= uy)) || ux == uy);
}

int main ()
{
	printf("%d\n",le(0.0f, 0.0f)); //1
	printf("%d\n",le(-0.0f, 0.0f)); //1
	printf("%d\n",le(-1.0f, -1.0f)); //1
	printf("%d\n",le(1.0f, 1.0f)); //1
	printf("%d\n",le(-1.0f, 0.0f)); //1
	printf("%d\n",le(0.0f, 1.0f)); //1 
	printf("%d\n",le(1.0f, 0.0f)); //0
	printf("%d\n",le(0.0f, -1.0f)); //0 
	printf("%d\n",le(-1.0f, -2.0f)); //0
	return 0;

}
