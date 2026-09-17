#ifndef TREE_H
#define TREE_H

#include "frequency.h"
#include "sort.h"
#include <stddef.h>

typedef struct Node {
	char charName;
	int frequency;
	int binary_num1or0;
	
	struct Node *left;
	struct Node *right;
} Node;

typedef struct {
	char charName;
	char code[256];
} CharCode;

int make_huffman_tree(Character **characters, int *chararcters_count, CharCode *table, int *table_count );

#endif
