#include <stdio.h>
#include <stdlib.h>

int readInt() {
	char lineBuf[10];
	char *p = NULL;
	int n;

	while (1) {
		// char* fgets (char* str, int num, FILE* stream);
		// reads stdin into lineBuf
		fgets(lineBuf, sizeof(lineBuf), stdin);

		//long int strtol (const char* str, char** endptr, int base);
		n = strtol(lineBuf, &p, 10);
		if (lineBuf != p) {
			break;
		}
		printf("Invalid input\n");

	}

	return n;
}

int main() {

	// call stack is a stack of code to keep track of instructions and variables 
	// created when we run a program and destroyed on program completion

	// heap is a list of addresses that store information: 0x00000001, 0x000000002, ... up to "RAM size"


	// create int array of fixed length
	int length = 3;
	// (cast) malloc (size)
	int* arr = (int *)malloc(length * sizeof(int));

	// loop over array and fill with readInt
	int i;
	for(i = 0; i < length; i++) {
		printf("Enter an integer: ");
		arr[i] = readInt();
		printf("\n");
	}

	// loop over again and print
	printf("[");
	for(i = 0; i < length; i++){
		if(i < length -1) {
			printf("%d, ", arr[i]);
			continue;}
		printf("%d", arr[i]);
	}
	printf("]\n");
	
	free(arr);
	}

	// free malloc'd array pointer
