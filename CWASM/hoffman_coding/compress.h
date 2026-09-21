#ifndef COMPRESS_H
#define COMPRESS_H

#include "tree.h"

void compress(char *input, char *output, CharCode *table, int table_count, int lookup[256]);

#endif
