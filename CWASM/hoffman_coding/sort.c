#include "frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int partition(Character *characters, int *l, int *r) {
	int pivot = characters[*r].frequency;	
	printf("Pivot: %d\n", pivot);
	int i = *l - 1;
	for (int j = 0; j < *r ; j++) {
		if (characters[j].frequency < pivot) {
			i++;		
			//printf("%d %d\n", j, i);
			//swap
			Character temp = characters[j];
			characters[j] = characters[i]; 
			characters[i] = temp;
			//printf("%c, %d\n", temp.charName, temp.frequency);
		}	
	}
	Character temp2 = characters[*r];
	characters[*r] = characters[i + 1];
	characters[i + 1] = temp2;
	// Character temp2 = characters[*r];
	// characters[*r] = characters[i + 1];
	// characters[i + 1] = temp2;
	//printf("%c, %d\n", temp2.charName, temp2.frequency);
	//free(temp2);

	return i + 1;
}

int sort(Character *characters, int chararcters_count, int *l, int *r) {
	if (*l >= *r) {
		printf("%d, %d\n", *l, *r);
		return SUCCESS;
	}

	int p = partition(characters, l, r);
	printf("p: %d\n\n", p);
	int p1 = p - 1;
	int p2 = p + 1;
	printf("%d 1 %d 2\n", p1, p2);
	
	sort(characters, chararcters_count, l, &p1);
	//sort(characters, chararcters_count, &p2, r);
}
