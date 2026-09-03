#include "frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int frequency_count(char *input, Character **characters, int *chararcters_count) {
	char *chache = malloc(3);
	int len = 0;
	int capacity = 2;

	Character *local_characters = NULL;
    	int local_count = 0;

	for (int i = 0; input[i] != '\0'; ++i) {
		
		if (len + 1 >= capacity) {
			capacity *= 2;

			char *tmp = realloc(chache, capacity);
			if (tmp == NULL) {
				return ERR_ALLOC;
			}

			chache = tmp;	
		}
		if (strchr(chache, input[i]) == NULL) {
			chache[len++] = input[i];
				
			Character character = {
				.charName = input[i],
				.frequency = 1
			};
			
			local_count++;
			Character *tmpC = realloc(local_characters, local_count * sizeof(Character));
			if (tmpC == NULL) {
				free(tmpC);
				return ERR_ALLOC;
			}
			local_characters = tmpC;
			local_characters[local_count - 1] = character;
		} else {
			//printf("Im in here%c", input[i]);
			for (int j = 0; j < local_count; j++) {
				if (input[i] == local_characters[j].charName) {
					local_characters[j].frequency++;
				}
			}
		}
	}

	chache[len] = '\0';

	//printf("%s\n", chache);
	free(chache);
	int l = 0;
	int r = local_count - 1;
	for (int k = 0; k < local_count; ++k) {
		printf("%c, %d\n", local_characters[k].charName, local_characters[k].frequency);
	}
	printf("\n\n");
	sort(local_characters, local_count, l, r);

	*characters = local_characters;
    	*chararcters_count = local_count;
	return 0;
}
