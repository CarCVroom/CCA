#include "assign_num.h"
#include "frequency.h"
#include "tree.h"
#include <stdio.h>

void assign_num(Node *node, char code[256], int depth) {
	/*
	 * left = 0
	 * right = 1
	 */
	if (node->left == NULL && node->right == NULL) {
		code[depth] = '\0';
		printf("%c: %s\n",node->charName,  code);
		return;	
	}

	code[depth] = '0';
	assign_num(node->left, code, depth + 1);

	code[depth] = '1';
	assign_num(node->right, code, depth + 1);
}
