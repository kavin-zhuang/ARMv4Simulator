#ifndef HELP_H
#define HELP_H

void gen_hex_value(void);
int find_instruction(
	unsigned int instruction, 
	unsigned int imask[], 
	unsigned int ivalue[], 
	char *idesc[]);

#endif