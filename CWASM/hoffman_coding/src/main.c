#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
	
#include "frequency.h"
#include "tree.h"
#include "compress.h"

void decompress_test(char *output, char *reverse_enginerd,int *output_length, CharCode *table, int table_count, int lookup[256]);

int main(void) {
	char input[] = "Aoa%ZnQK9!zPxrS1xyH0kWX$yfQkkUH4Ya9+FGQt=O2MJQk3ddtP6zj+sfXKuXr$b202ACcJO&7Ah2V7hWhJfjTQomH$2Vue8@cM";
	//char input[] = "AABBBBBBBBBBBBBBbbbbbCCCCCCCddddeeF"; 
	//char input[] = "bccfffcddabddefeeeffe"; 
	char output[sizeof(input)]; 
	char new_str[sizeof(input)]; 

	Character *characters = NULL;
	int chararcters_count = 0;

	int result_freq_count = frequency_count(input, &characters,&chararcters_count);	
	if (result_freq_count != SUCCESS) {
		printf("Something went wrong, error code: %d", result_freq_count);
	}

	CharCode *table = NULL;
	int table_count = 0;

	int lookup[256];
	for (int i = 0; i < 256; i++) {
		lookup[i] = -1;
	}

	int result_huff_tree_make = make_huffman_tree(&characters,&chararcters_count, &table, &table_count, lookup);	
	if (result_huff_tree_make != SUCCESS) {
		printf("Something went wrong, error code: %d", result_huff_tree_make);
	}

	int output_length;
	compress(input, output, &output_length ,table, table_count, lookup);

	//printf("Output length: %d bytes\n", output_length);
	// for (int i = 0; i < output_length; i++) {
	//    		printf("%02X ", (unsigned char)output[i]);
	// }
	// printf("\n"); // prints the raw hex

	decompress_test(output, new_str, &output_length, table, table_count,lookup);
	printf("Input: %s\n", input);
	printf("New Str: %s\n", new_str);

	free(characters);
	free(table);
	return 0;
}

void decompress_test(char *output, char *reverse_enginerd,int *output_length, CharCode *table, int table_count, int lookup[256]) {
	int padding = (unsigned char) output[0];
	int total_bits = (*output_length - 1) * 8 - padding;
	char current_code[256] = "";
	int code_len = 0;
	int out_pos = 0;

	for (int bit_num = 0; bit_num < total_bits; bit_num++) {
		int byte_index = 1 + (bit_num / 8);
		int bit_in_byte = bit_num % 8;

		int bit = (output[byte_index] >> (7 - bit_in_byte)) & 1;

		current_code[code_len] = bit ? '1' : '0';
		code_len++;
		current_code[code_len] = '\0';

		for (int i = 0; i < table_count; i++) {
			if (strcmp(current_code, table[i].code) == 0) {
				reverse_enginerd[out_pos] = table[i].charName;	
				out_pos++;

				code_len = 0;
				current_code[0] = '\0';
				break;
			}
		}
	}

	reverse_enginerd[out_pos] = '\0';
}
