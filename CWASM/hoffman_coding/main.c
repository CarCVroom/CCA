#include <stdio.h> 
#include "frequency.h"

int main(void) {
	char input[] = "AABBBBBBBBBBBBBBBBBBBCCCCCCCddddeeF"; 

	int result = frequency_count(input);	
	if (result != SUCCESS) {
		printf("Something went wrong, error code: %d", result);
	}

	return 0;
}
