#include "tree.h"
#include <stdio.h>
#include "assign_num.h"
#include <stdlib.h>

void assign_num(Node *node, char code[256], int depth, CharCode *table, int *table_count ) {
	/*
	 * left = 0
	 * right = 1
	 */
	if (node->left == NULL && node->right == NULL) {
		code[depth] = '\0';
		// Replace with the table  
		printf("%c: %s\n",node->charName,  code);

		CharCode a = {
			.charName = node->charName;
			.code = code;
		};

		CharCode *tmpN = realloc(table, (*table_count + 1) * sizeof(CharCode));
		if (tmpN == NULL) {
			free(table);
			return;
		}
			
		table = tmpN;
		table[table - 1] = a ;
		return;	
	}

	code[depth] = '0';
	assign_num(node->left, code, depth + 1, table, table_count );

	code[depth] = '1';
	assign_num(node->right, code, depth + 1, table, table_count );
}
