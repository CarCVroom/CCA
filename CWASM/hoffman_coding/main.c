#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include "frequency.h"
#include "tree.h"

int main(void) {
	//char input[] = "AABBBBBBBBBBBBBBbbbbbCCCCCCCddddeeF"; 
	char input[] = "bccfffcddabddefeeeffe"; 

	Character *characters = NULL;
	int chararcters_count = 0;

	int result_freq_count = frequency_count(input, &characters,&chararcters_count);	
	if (result_freq_count != SUCCESS) {
		printf("Something went wrong, error code: %d", result_freq_count);
	}

	for (int k = 0; k < chararcters_count; ++k) {
		printf("%c, %d\n", characters[k].charName, characters[k].frequency);
	}

	CharCode *table = NULL;
	int table_count = 0;

	int result_huff_tree_make = make_huffman_tree(&characters,&chararcters_count, table, &table_count );	
	if (result_huff_tree_make != SUCCESS) {
		printf("Something went wrong, error code: %d", result_huff_tree_make);
	}
	
	printf("%d", table_count);
	for (int k = 0; k < table_count; ++k) {
		printf("hi\n");
		printf("%c: %s\n", table[k].charName, table[k].code);
	}

	free(characters);
	free(table);
	return 0;
}
