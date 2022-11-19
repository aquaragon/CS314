#include <stdio.h>

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
		// // [0.76, 1.26] otherwise.
		// float r = rand()/(float)RAND_MAX;
		// a[i] = r < 0.5f ? 0.0f : r + 0.26f;
		// }
	return a;
}
