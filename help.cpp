#include <stdio.h>

#include "armv4.h"

void gen_hex_value(char *array[])
{
	unsigned int bit = 0, value = 0;

	int i, j;

	for (i = 0; i < 21; i++) {
		value = 0;
		for (j = 0; j < 32; j++) {
			bit = array[i][j] - '0';
			value |= bit << (31 - j); // litter endian
		}
		printf("0x%08X,\n", value);
	}
}

int find_instruction(unsigned int instruction, unsigned int imask[], unsigned int ivalue[], char idesc[][32])
{
	int i;
	unsigned int value;

	for (i = 0; i < 21; i++) {
		value = imask[i] & instruction;
		if (value == ivalue[i]) {
			break;
		}
	}

	if (21 == i) {
		printf("UNKNOWN\n");
		return -1;
	}

	printf("%s\n", idesc[i]);

	return i;
}