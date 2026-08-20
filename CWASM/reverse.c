#include <stdio.h>
#include <string.h>

void reverse(char *str);

int main(void) {
	char str[] = "et dixit eis ite comedite pinguia et bibite mulsum et mittite partes ei qui non praeparavit sibi quia sanctus dies Domini est et nolite contristari gaudium enim Domini est fortitudo nostra ";
	reverse(str);	
	printf("%s\n", str);
}

void reverse(char *str) {
	int len = strlen(str) / 2;

	for (int i = 0; i < len; i++) {
		char temp = str[strlen(str) - 1 - i];

		str[strlen(str) - 1 - i] = str[i];
		str[i] = temp;
	}
	printf("%s\n\n", str);
}
