#include <stdio.h>
#include <math.h>

// COMPILE WITH -lm !!!
void printTSO(int blockSizeInBytes, int numSets, int archSizeInBits) {
        int setBits = 0;
        if (numSets > 1) {
                setBits = log2(numSets);
        }
        int offsetBits = log2(blockSizeInBytes);
        int tagBits = archSizeInBits - setBits - offsetBits;
        printf("%dB blocks, %d sets, %d-bit architecture: %d tag bits, %d set bits, %d offset bits.\n",
                        blockSizeInBytes, numSets, archSizeInBits, tagBits, setBits, offsetBits);
}

// address: 0x12345678
// points to *one* byte in memory

// for an X-bit architecture
// how many possibly pointers are there
// "normal" arch is 32 or 64 bits
// A: 2^X

// for an X-bit arch, we can point to 2^X diff bytes
//

// LAB 8: 256B block, 1 set, 32 bit arch
unsigned int getOffset(unsigned int address) {
        // returns the byte offset of the address within its cache block
	unsigned int mask = 0x000000FF;
	return (mask & address);
}

unsigned int getTag(unsigned int address) {
        // returns the cache tag for the address
	unsigned int mask = 0xFFFFFF00;
	return (mask & address) >> 8;
}

void main() {
        printTSO(256, 1, 32);
        unsigned int testAddr1 = 0x12345678;
        unsigned int testAddr2 = 0x87654321;
        // uncomment after implementing
        printf("0x%08x: offset - %x, tag - %x.\n", testAddr1, getOffset(testAddr1), getTag(testAddr1));
        printf("0x%08x: offset - %x, tag - %x.\n", testAddr2, getOffset(testAddr2), getTag(testAddr2));
}
