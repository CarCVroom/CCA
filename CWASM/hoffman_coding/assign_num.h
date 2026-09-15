#ifndef ASSIGN_NUM_H
#define ASSIGN_NUM_H

#include "tree.h"
#include <stddef.h>

typedef struct {
	char charName;
	char code[256];
} CharCode;

void assign_num(Node *node, char code[256], int depth);

#endif
