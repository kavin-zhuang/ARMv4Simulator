/*
 * Copyright (C) 2017, Jinfeng Zhuang
 * All rights reserved.
 *
 * Support for ARMv4 Instruction Set.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "armv4.h"
#include "types.h"
#include "help.h"

int main(void)
{
	TRACE();

	FILE *binfile = fopen("app.bin", "rb");
	if (NULL == binfile) {
		ERROR();
		goto end;
	}

	unsigned char * content = (unsigned char*)malloc(SIZE_1M);
	if (NULL == content) {
		ERROR();
		goto end;
	}
	memset(content, 0, SIZE_1M);

	size_t bytesread = fread(content, sizeof(char), SIZE_1M, binfile);
	if (bytesread < 0) {
		ERROR();
		goto end;
	}

	TRACE();

	/* enter parse mode, unit size is 4 byte */
	unsigned int *instruction_pool = (unsigned int *)content;
	int instruction_count = bytesread / 4;
	int i;
	for (i = 0; i < 20; i++) {
		find_instruction(instruction_pool[i],
			InstructionMask,
			InstructionValue,
			InstructionString);
	}

end:
	if (binfile) {
		fclose(binfile);
	}
	if (content) {
		free(content);
	}
	return 0;
}
