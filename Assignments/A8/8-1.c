#include <stdio.h>
#include <stdlib.h>

struct Line {
	unsigned char data[2]; // 2-byte blocks
	unsigned int tag; // Assume tag is at most 32 bits
	unsigned char valid; // valid bit
};

struct Cache {
	struct Line *lines;
	int numLines;
};

unsigned int getOffset(unsigned int address) {
	return address & 0x1; // 2-byte blocks, so 1 offset bit
}

unsigned int getSet(unsigned int address) {
	return (address >> 1) & 0x7; // 2-byte blocks; 8 sets so 3 set bits
}

unsigned int getTag(unsigned int address) {
	return address >> 4; // total of 4 bits for offset and set
}

struct Cache* mallocCache(int numLines) {
	// TODO - malloc a pointer to a struct Cache, malloc a pointer to an array
	// of struct Line instances (array length is numLines). Also initialize
	// valid to 0 for each struct Line. Return the struct Cache pointer.
	//
	// allocates memory for cache struct and the array to the structs of line
	struct Cache * newCache = malloc(sizeof(struct Cache)*numLines);
       	newCache -> lines = malloc(sizeof(struct Line) * numLines);
	for (int i = 0; i < numLines; i++)
	{
		newCache->lines[i].valid = 0;
	}
	newCache -> numLines = numLines;
	return newCache;
}

void freeCache(struct Cache *cache) {
	free(cache->lines);
	free(cache);
}

void printLine(struct Line *line, unsigned int set) {
	unsigned char *data = line->data;
	printf("set: %x - tag: %x - valid: %u - data: %.2x %.2x\n",set, line->tag, line->valid, data[0], data[1]);
}

void printCache(struct Cache *cache) {
	// TODO - print all valid lines in the cache.
	//
	// iterates through and checks valid bit for 1 and prints if so
	int lineCounter = 0;
	while(lineCounter < cache->numLines)
	{
		if (cache->lines[lineCounter].valid == 1)
		{
			printLine(&cache->lines[lineCounter],lineCounter);
		}
		lineCounter++;
	}
}

void readValue(struct Cache *cache, unsigned int address) {
	// TODO - check the cache for a cached byte at the specified address.
	// If found, indicate a hit and print the byte. If not found, indicate
	// a miss due to either an invalid line (cold miss) or a tag mismatch
	// (conflict miss).
	printf("Looking for set: %x - tag: %x\n", getSet(address), getTag(address));
 	for(int i = 0; i < cache->numLines; i++)
	{
		//Case of a hit checks valid tag and set should be correct
		if (cache->lines[i].valid == 1 && cache->lines[i].tag == getTag(address) && i == getSet(address)) 
		{
				printf("Found set: ");
			       	printLine(&cache->lines[i], i);
				printf("Hit!\n");
				i = cache->numLines;
		}
		else
		{	//case of a conflict miss checks tag not being correct but valid bit and set are
			if(cache->lines[i].valid == 1 && i == getSet(address) && cache->lines[i].tag != getTag(address))
			{
				printf("Miss\n");
				i = cache->numLines;
			}//case of a cold miss, valid is zero tag and set should be correct
			else if(cache->lines[i].valid == 0 && cache->lines[i].tag == getTag(address) && i == getSet(address))
			{
				printf("Miss\n");
				i = cache->numLines;
			}
		}
	}
}

void writeValue(struct Cache *cache, unsigned int address, unsigned char *newData) {
	unsigned int s = getSet(address);
	unsigned int t = getTag(address);
	struct Line *line = &cache->lines[s];
	if (line->valid && line->tag != t) {
		unsigned char *data = line->data;
		printf("evicting line - ");
		printLine(line, s);
	}
	for (int i = 0; i < 4; ++i) {
		line->data[i] = newData[i];
	}
	line->tag = t;
	line->valid = 1;
	printf("wrote set: ");
	printLine(line, s);
}

unsigned int readUnsignedIntFromHex() {
	char buffer[10];
	char *p = NULL;
	unsigned int n;
	while (1) {
		fgets(buffer, sizeof(buffer), stdin);
		n = strtoul(buffer, &p, 16);
		if (buffer != p) {
			break;
		}
		printf("Invalid input - try again: ");
	}
	return n;
}

int main() {
	struct Cache *cache = mallocCache(8);
	char buffer[10];
	char c;
	do {
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
		fgets(buffer, sizeof(buffer), stdin);
		c = buffer[0];
		if (c == 'r') {
			printf("Enter 32-bit unsigned hex address: ");
			unsigned int a = readUnsignedIntFromHex();
			readValue(cache, a);
		} else if (c == 'w') {
			printf("Enter 32-bit unsigned hex address: ");
			unsigned int a = readUnsignedIntFromHex();
			printf("Enter 32-bit unsigned hex value: ");
			unsigned int v = readUnsignedIntFromHex();
			unsigned char *data = (unsigned char *)&v;
			writeValue(cache, a, data);
		} else if (c == 'p') {
			printCache(cache);
		}
	} while (c != 'q');
	freeCache(cache);
}
