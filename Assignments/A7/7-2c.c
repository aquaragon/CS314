#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
	long a;
	long r;
	long g;
	long b;
};

struct ColorPoint** create2DArray(int n) {
 // Array to hold a pointer to the beginning of each row
 	struct ColorPoint **points = (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
 	for (int i = 0; i < n; ++i) {
 // Array to hold each row
 		points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
 		for (int j = 0; j < n; ++j) {
 // Init the ColorPoint struct
 			points[i][j].a = rand();
 			points[i][j].r = rand();
			points[i][j].g = rand();
 			points[i][j].b = rand();
	}
 }
	return points;
}
void free2DArray(struct ColorPoint** points, int n) {
 	for (int i = 0; i < n; ++i) {
 		free(points[i]);
 	}
 	free(points);
}

long f(struct ColorPoint **points, int n) {
	long sum = 0;
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < n; j++) {
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
 		}
 	}
	return sum;
}

long g(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
	return sum;
}




int main ()
{
	struct ColorPoint** array1 = create2DArray(2048);
	clock_t start = clock();
	for(int i = 0; i < 1000000; i++)
	{
		f(array1,2048);
	}
	clock_t end = clock();
	double totalTime = ((double) ( end - start)) / CLOCKS_PER_SEC;

	clock_t start1 = clock();
	for(int i = 0; i < 1000000; i++)
	{
		g(array1,2048);
	}
	clock_t end1 = clock();
	double totalTime1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;

	printf("f function took %f seconds\n", totalTime);
	printf("g function took %f seconds\n", totalTime1);
	
	return 0;
}

//f takes longer than g because f is column major so it doesnt get to take advantage of the fact that the cache will have the next row in the array like g (row major) will, so there will be more misses for f thus taking longer to compute
