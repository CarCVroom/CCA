#include "assign_num.h"
#include "frequency.h"
#include "tree.h"
#include <stdio.h>

int assign_num(Node **nodes, int *node_count) {
	/*
	 * left = 0
	 * right = 1
	 */
	printf("%d\n", nodes[0]->right->frequency);
	printf("%c\n", nodes[0]->right->charName);
}
