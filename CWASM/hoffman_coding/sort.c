#include "frequency.h"
#include "sort.h"

int partition(Character *characters, int l, int r) {
	int pivot = characters[r].frequency;	
	int i = l - 1;
	for (int j = l; j < r ; j++) {
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
	Character temp2 = characters[r];
	characters[r] = characters[i + 1];
	characters[i + 1] = temp2;
	// Character temp2 = characters[*r];
	// characters[*r] = characters[i + 1];
	// characters[i + 1] = temp2;
	//printf("%c, %d\n", temp2.charName, temp2.frequency);
	//free(temp2);

	return i + 1;
}

int sort(Character *characters, int chararcters_count, int l, int r) {
	if (l >= r) {
		return SUCCESS;
	}

	int p = partition(characters, l, r);
	
	sort(characters, chararcters_count, l, p - 1);
	sort(characters, chararcters_count, p + 1, r);
	return SUCCESS;
}
