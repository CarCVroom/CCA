#include <stdio.h>

int string_length(char *str);

int main(void) {
	int length = string_length("hello");	
	printf("%d", length);
}

int string_length(char *str) {
	int length = 0;

	for (int i = 0; *(str + i) != '\0'; i++) {
		length++;	
	}

	return length;
}
