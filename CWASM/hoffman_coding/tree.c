#include "tree.h"
#include "frequency.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "assign_num.h"

int make_huffman_tree(Character **characters, int *chararcters_count, Node **nodes, size_t *node_count) {

	Node **local_nodes = NULL;
    	int local_count = 0;

	for (size_t i = 0; i < *chararcters_count; ++i) {
	
		Node node = {
			.frequency = (*characters)[i].frequency,
			.charName = (*characters)[i].charName,
			.left = NULL,
			.right = NULL,
		};

		Node *p = malloc(sizeof(Node));
		if (p == NULL) {
			free(local_nodes);
			return ERR_ALLOC;
		}
		*p = node;

		Node **tmpN = realloc(local_nodes, (local_count + 1) * sizeof(Node *));
		if (tmpN == NULL) {
			free(p);
			free(local_nodes);
			return ERR_ALLOC;
		}
		local_nodes = tmpN;
		local_nodes[local_count] = p;
		local_count++;

	}


	while ((local_count) > 1 ) {
		
		Node merged = {
			.frequency = local_nodes[0]->frequency + local_nodes[1]->frequency,
			.left = local_nodes[0],
			.right = local_nodes[1],
		};
		Node *Mp = malloc(sizeof(Node));
		if (Mp == NULL) {
			free(Mp);
			free(local_nodes);
			return ERR_ALLOC;
		}
		*Mp = merged;

		for(int j = 0; j < 2; ++j) {
			for (int i = 0; i < local_count - 1; i++) {
			    local_nodes[i] = local_nodes[i + 1];
			}
			(local_count)--;
		}

		// Looks for where to put Mp
		int idx = local_count;
		for(int i = 0; i < local_count ; ++i) {
			if (local_nodes[i]->frequency >= merged.frequency) { 
				idx = i;
				break;
			}
		}

		Node **tmpN = realloc(local_nodes, (local_count + 1) * sizeof(Node *));
		if (tmpN == NULL) {
			free(Mp);
			free(local_nodes);
			return ERR_ALLOC;
		}
		for(int k = local_count - 1; k >= idx; k--) {
			tmpN[k + 1] = tmpN[k];
		}

		local_nodes = tmpN;
		local_nodes[idx] = Mp;
		local_count++;
	}

	assign_num(local_nodes, &local_count);

	nodes = local_nodes;
    	*node_count = local_count;

	return SUCCESS;
}
