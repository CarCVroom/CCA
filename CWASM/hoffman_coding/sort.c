#include "frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int partition(Character *characters, int *l, int *r) {
	int pivot = characters[*r].frequency;	
	int i = *l - i;
	for (int j = 0; j < *r - 1; j++) {
		if (characters[j].frequency < pivot) {
			i++;		
			//swap
			Character *temp = &characters[j];
			characters[j] = characters[i]; 
			characters[i] = *temp;
			printf("%c, %d\n", temp->charName, temp->frequency);
			//free(temp);
		}	
	}
	Character temp2 = characters[*r];
	characters[*r] = characters[i + 1];
	characters[i + 1] = temp2;
	//free(temp2);

	return i + 1;
}

int sort(Character *characters, int chararcters_count, int *l, int *r) {

	if (l >= r) {
		return SUCCESS;
	}

	int p = partition(characters, l, r);
	int p1 = p - 1;
	int p2 = p + 1;
	
	sort(characters, chararcters_count, l, &p1);
	sort(characters, chararcters_count, &p2, r);
	return SUCCESS;
}
