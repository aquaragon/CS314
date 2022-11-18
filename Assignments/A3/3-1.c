#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 15

struct IntArray
{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length)
{
	//using malloc this function creates a new array of dyamic length while also using a struct to hold the length and ptr to each piece of data
	struct IntArray * arr = malloc (length * sizeof(struct IntArray));
	arr->dataPtr = (int*)malloc(sizeof(int) * length);
	arr->length = length;
	return arr;
}


void freeIntArray(struct IntArray * arrayPtr)
{
	//using free this function releases the memory being held by the struct IntArray
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray * array)
{
	//using fgets this function reads in int values to insert into the array, will warn user of invalid entries
	int x = 0;
	while (x < array->length)
	{
		char buf[BUFSIZE];
		char *last;

		long value = 0L;
		while (value <= 0L)
		{
			printf("Please enter in an integer: ");
			fgets(buf, BUFSIZE, stdin);
			value = strtol (buf, &last, 10);
			if (last == buf)
			{
				printf("Invalid input\n");
			}else if (value < 0)
			{
				printf("Invalid input. Negative values are not allowed.\n");
			}
			array->dataPtr[x] = value;
		}
	x++;
	}
}

void swap(int * xp, int *yp)
{
	//swaps the values of two given array location used in bubble sort
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sortIntArray(struct IntArray * array)
{
	//bubble sort from geeks for geeks
	int i, j;
	for (i = 0; i < array->length - 1; i++)
		for (j = 0; j < array->length - i - 1; j++)
			if (array->dataPtr[j] > array->dataPtr[j + 1])
				swap(&array->dataPtr[j], &array->dataPtr[j + 1]);
}

void printIntArray(struct IntArray * array)
{
	//prints the array including the brackets and commas for formatting
	printf("[");
	for(int i = 0; i < array->length;i++)
	{
		printf("%d", array->dataPtr[i]);
		if(i < array->length - 1)
		{
			printf (", ");
		}
	}
	printf("]\n");
}

int main ()
{
	char buf[BUFSIZE];
	char *last;

	long size = 0L;
	while (size <= 0L)
	{
		printf("Enter length of the array: ");
		fgets(buf, BUFSIZE, stdin);
		size = strtol(buf, &last, 10);
		if (last == buf)
		{
			printf("Invalid input\n");

		}else if(size < 0)
		{
			printf ("Input Invalid. Cannot be a negative value.\n");
		}
	}

	int length = (int)size;
	struct IntArray *array = mallocIntArray(length);
	readIntArray(array);
	sortIntArray(array);
	printIntArray(array);
	freeIntArray(array);
	return 0;
}

//https://www.geeksforgeeks.org/bubble-sort/ source for bubble sort
