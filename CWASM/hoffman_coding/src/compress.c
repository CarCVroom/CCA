#include "../include/compress.h"

#include <string.h>

void compress(char *input, char *output ,int *output_length, CharCode *table, int table_count, int *lookup) {
	unsigned char byte = 0;
	int bit_count = 0;
	int output_index = 1;

	for (int i = 0; input[i] != '\0'; ++i) {
		// write in as raw bits
	
		char code[256];
		strcpy(code, table[lookup[input[i]]].code);
		for (int j = 0; code[j] != '\0' ; ++j) {
			byte <<= 1;		

			if (code[j] == '1') { 
				byte |= 1;
			}
	
			bit_count++;

			if (bit_count == 8) {
				output[output_index] = byte;
				output_index++;

				byte = 0;
				bit_count = 0;
			}
		}
	}

	if (bit_count > 0) {
		int padding = 8 -bit_count;
		byte <<= padding;
		output[output_index] = byte;
		output_index++;
		output[0] = padding;
	} else {
		output[0] = 0;
	}

	*output_length = output_index;
}
