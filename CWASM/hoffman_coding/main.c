#include <stdio.h> 
#include <stdlib.h>
#include "frequency.h"
#include "sort.h"

int main(void) {
	//char input[] = "AABBBBBBBBBBBBBBbbbbbCCCCCCCddddeeF"; 
	char input[] = "bccfffcddabddefeeeffe"; 

	Character *characters = NULL;
	int chararcters_count = 0;

	int result = frequency_count(input, &characters,&chararcters_count);	
	if (result != SUCCESS) {
		printf("Something went wrong, error code: %d", result);
	}

	for (int k = 0; k < chararcters_count; ++k) {
		printf("%c, %d\n", characters[k].charName, characters[k].frequency);
	}



	free(characters);
	return 0;
}
