#include <stdio.h>

void printStr(char *str);

int main(void) {
	printStr("Hello\n");
	
}

void printStr(char *str) {
	while(*str != '\0') {

		printf("%c", *str);

		str++;
	}
}
