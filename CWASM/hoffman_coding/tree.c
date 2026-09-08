#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int make_huffman_tree(Character **characters, int *chararcters_count, Node **nodes, size_t *node_count) {

	Node *local_nodes = NULL;
    	size_t local_count = 0;

	while ((*characters)) {
		Node node = {
			.frequency = (*characters)[0].frequency + (*characters)[1].frequency
		};

		local_count++;
		Node *tmpN = realloc(local_nodes, local_count * sizeof(Node));
		if (tmpN == NULL) {
			free(local_nodes);
			return ERR_ALLOC;
		}
		local_nodes = tmpN;
		local_nodes[local_count - 1] = node;

		printf(" %d\n", local_nodes[0].frequency);

		for(int j = 0; j < 2; ++j) {
			for (int i = 0; i < *chararcters_count - 1; i++) {
			    (*characters)[i] = (*characters)[i + 1];
			}
			(*chararcters_count)--;
		}
				
		for (int k = 0; k < *chararcters_count; ++k) {
			printf("%c, %d\n", (*characters)[k].charName, (*characters)[k].frequency);
		}

		// Add node back into the array
		
		return SUCCESS;
	}

	return SUCCESS;
}
