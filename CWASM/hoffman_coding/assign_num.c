#include "assign_num.h"
#include "frequency.h"
#include "tree.h"
#include <stdio.h>

int assign_num(Node **nodes, int *node_count) {
	nodes[0]->binary_num1or0 = 1;
	nodes[0]->left->binary_num1or0 = 1;
	nodes[0]->right->binary_num1or0 = 0;

	return SUCCESS;
}
