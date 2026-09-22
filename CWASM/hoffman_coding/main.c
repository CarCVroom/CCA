#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
	
#include "frequency.h"
#include "tree.h"
#include "compress.h"

void decompress_test(char *output, char *reverse_enginerd,int *output_length, CharCode *table, int table_count, int lookup[256]);

int main(void) {
	char input[] = "AABBBBBBBBBBBBBBbbbbbCCCCCCCddddeeF"; 
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
	for (int i = 0; i < output_length; i++) {
    		printf("%02X ", (unsigned char)output[i]);
	}
	printf("\n");

	decompress_test(output, new_str, &output_length, table, table_count,lookup);
	printf("Input: %s\n", input);
	printf("New Str: %s\n", new_str);

	free(characters);
	free(table);
	return 0;
}

void decompress_test(char *output, char *reverse_enginerd,int *output_length, CharCode *table, int table_count, int lookup[256]) {
	unsigned char byte = 0;
	int bit_count = 0;
	int bit_index = 0;
	int bit_tally = 0;
	int bit_temp = 0;

	while (output) {
		// Read bits until match
		for (int i ; i < table_count; i++) {
			// do the they match in something in the table		
			if () {
				bit_temp += output[bit_index];
				bit_index = 0;
			} else {
				bit_index++;
			}
		}	
		
		// Assume no match is padding on the end
	}
}
