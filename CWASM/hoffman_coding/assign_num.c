#include "tree.h"
#include <stdio.h>
#include "assign_num.h"
#include <stdlib.h>
#include <string.h>

void assign_num(Node *node, char code[256], int depth, CharCode **table, int *table_count ) {
	/*
	 * left = 0
	 * right = 1
	 */
	if (node->left == NULL && node->right == NULL) {
		code[depth] = '\0';
		// Replace with the table  
		printf("%c: %s\n",node->charName,  code);

		CharCode table_entry = {
			.charName = node->charName,
		};
		strcpy(table_entry.code, code);

		CharCode *tmpN = realloc(*table, (*table_count + 1) * sizeof(CharCode));
		if (tmpN == NULL) {
			return;
		}

		*table = tmpN;
		(*table)[*table_count] = table_entry;
		*table_count = *table_count + 1;
		// (*table_count)++;

		// printf("%c: %s\n",table->charName,  table->code);
		return;	
	}

	code[depth] = '0';
	assign_num(node->left, code, depth + 1, table, table_count );

	code[depth] = '1';
	assign_num(node->right, code, depth + 1, table, table_count );
}
