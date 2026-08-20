#include <cstddef>
#include <string.h>
#include <stdio.h>

void RLE(char *input, size_t strSize);

int main(void) {
	char str[] = "XCXXXXffjjjww";
	
	RLE(str, sizeof(str));	

	printf("%s\n", str);
}

void RLE(char *str, size_t strSize) {
	int lLen = strlen(str); 
	char strCopy[100];
	strcpy(strCopy, str);
	str[0] = '\0';

	for(int i = 0; i < lLen -1 ; i++) {
		int j = i; 	
		int len = strlen(str);
		
		int x = 0;
		while (strCopy[i] == strCopy[j] && j < lLen) {
			x++;
			j++;
		}
		snprintf(str + len, strSize - len, "%d%c", x, strCopy[i]);
		i = j - 1;
	}
}	
