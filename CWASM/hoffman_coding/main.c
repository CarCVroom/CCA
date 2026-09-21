#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include "frequency.h"
#include "tree.h"
#include "compress.h"

int main(void) {
	char input[] = "AABBBBBBBBBBBBBBbbbbbCCCCCCCddddeeF"; 
	//char input[] = "bccfffcddabddefeeeffe"; 
	char output[sizeof(input)]; 

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
	
	compress(input, output, table, table_count, lookup);

	free(characters);
	free(table);
	return 0;
}
