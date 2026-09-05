#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>
#include "frequency.h"
#include "sort.h"
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

	Node *nodes = NULL;
	size_t node_count = 0;

	int result_huff_tree_make = make_huffman_tree(&characters,&chararcters_count, &nodes,  &node_count);	
	if (result_huff_tree_make != SUCCESS) {
		printf("Something went wrong, error code: %d", result_huff_tree_make);
	}

	free(characters);
	return 0;
}
