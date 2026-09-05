#ifndef TREE_H
#define TREE_H

#include "frequency.h"
#include "sort.h"
#include <stddef.h>

typedef struct Node {
	char charName;
	int frequency;
	
	struct Node *left;
	struct Node *right;
} Node;

int make_huffman_tree(Character **characters, int *chararcters_count, Node **nodes, size_t *node_count);

#endif
