#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest)
{
	int i = 0;
	float sum = 0.0f;
	for(i = 0; i < length; i+=4)
	{
		sum += u[i] * v[i];
		sum += u[i+1] * v[i+1];
		sum += u[i+2] * v[i+2];
		sum += u[i+3] * v[i+3];
	}
	*dest = sum;
}

int main ()
{
	 int sizes[10] = {1,10,100,1000,10000,100000,100000,1000000,10000000,100000000};
	 for (int i = 0; i < 10; i++){
	 	int n = sizes[i]; //array size
		float *u = (float *)malloc(n * sizeof(float)); //array allocation
		float *v = (float *)malloc(n * sizeof(float)); // ^^^
	 	for (int i = 0; i < n; i++)
	 	{
			 u[i]= i; // filling arrays
			 v[i]= i;
	 	}
	 	float *result = (float *) malloc(sizeof(float));
	 	float *result1 = (float *) malloc(sizeof(float));

	 	clock_t start = clock();
	 	inner(u, v, n,result); 
	 	clock_t end = clock();
	 	double totalTime = ((double) ( end - start)) / CLOCKS_PER_SEC;

	 	clock_t start1 = clock();
	 	inner2(u, v, n,result1);
	 	clock_t end1 = clock();
	 	double totalTime1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC; 

		printf("For array size: %d\n",n); 
	 	printf("Value for inner: %f\n",*result);
	 	printf("Value for inner2:%f\n",*result1);

	 	printf("Time for inner: %f\n", totalTime);	
	 	printf("Time for inner2:%f\n\n", totalTime1);

	 	free(u);
	 	free(v);

		

	 	free(result);
		free(result1);
	}

	return 0;
}
