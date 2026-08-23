#include "frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int frequency_count(char *input) {
	char *chache = malloc(3);
	int len = 0;
	int capacity = 2;

	Character *characters = NULL;
	int chararcters_count = 0;

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
			
			chararcters_count++;
			Character *tmpC = realloc(characters, chararcters_count * sizeof(Character));
			if (tmpC == NULL) {
				return ERR_ALLOC;
			}
			characters = tmpC;
			characters[chararcters_count - 1] = character;
		} else {
			//printf("Im in here%c", input[i]);
			for (int j = 0; j < strlen(chache) - 1; j++) {
					printf("Im in here%c%c\n", input[i], characters[j].charName);
				if (input[i] == characters[j].charName) {
					characters[j].frequency++;
				}
			}
		}
	}

	chache[len] = '\0';

	printf("%s\n", chache);
	printf("%d\n", characters[0].frequency);
	free(characters);
	free(chache);
	return 0;
}
