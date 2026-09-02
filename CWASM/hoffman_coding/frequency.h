#ifndef FREQUENCY_H 
#define FREQUENCY_H

typedef struct {
	char charName;
	int frequency;
} Character;

int frequency_count(char *input, Character **characters, int *chararcters_count);

#define SUCCESS 0
#define ERR_ALLOC 1

#endif
