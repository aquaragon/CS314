#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float f(float *a, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}

float* createArray(int size) {
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i) {
		// 50% chance that a[i] is 0.0f, random value on the range
		// [0.76, 1.26] otherwise.
		float r = rand()/(float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
		}
	return a;
}

float g(float *b, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i)
	{
		prod *= b[i];
	}					        
	return prod;
}

int main()
{	
	float *a = createArray(10000); //part a, timing the function call of f
	clock_t start = clock();
	for (int i = 0; i < 100000000; i++)
	{
		f(a, 10000);
	}
	clock_t end = clock();

	double totTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Array a: %f\n", totTime);

	float *b = (float *)malloc(100000 * sizeof(float));
	for (int i = 0; i < 10000; i++)
	{
		if (a[i] == 0.0f)
		{
			b[i] = 1.0f;
		}
		else
		{
			b[i] = a[i];
		}
	}

	clock_t startb = clock();
	for (int i = 0; i < 100000000; i++)
	{
		g(b, 10000);
	}
	clock_t endb = clock();
	
	double totTimeb = ((double) (endb - startb)) / CLOCKS_PER_SEC;
	printf("Array b: %f\n", totTimeb); //g is slower because it has to do a mult for every element where f has a checheck that determines if a element has to to a product or not which would in total be less cycles
	
	int num_zero = 0;
	for (int i = 0; i < 10000; i++) //determine number of zeroes in a
	{
		if (a[i] = 0)
		{
			num_zero++;
		}
	}
	float *c = (float *)(malloc((100000 - num_zero) * sizeof(float)));
	int c_indexer = 0; //adding non zero elements of a to c
	for (int i = 0; i < 10000; i++)
	{
		if (a[i] != 0)
		{
			c[c_indexer++] = a[i];
		}
	}	

	clock_t startc = clock(); //c array computation
	for (int i = 0; i < 100000000; i++)
	{
		g(c, 10000- num_zero);
	}
	clock_t endc = clock();
	double totTimec = ((double) (endc - startc)) / CLOCKS_PER_SEC;
	printf("Array c: %f\n", totTimec); //g(c) will most of the time be faster than a and b because there will be less elements in the array, altough that could not be the case if there is no zeroes in a

	free(a);
	free(b);
	free(c);
	return 0;
}
