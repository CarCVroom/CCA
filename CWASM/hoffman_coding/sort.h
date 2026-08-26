#ifndef SORT_H
#define SORT_H

#include "frequency.h"

#define SUCCESS 0
#define ERR_ALLOC 1

int partition(Character *characters, int *l, int *r);
int sort(Character *characters, int chararcters_count, int *l, int *r);

#endif
