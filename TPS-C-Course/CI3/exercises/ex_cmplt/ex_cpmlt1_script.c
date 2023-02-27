/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	char arr[] = {'a', 'e', 'i', 'o', 'u', 'y'};
	char entry;
	int boolean = 0;
	
	printf("Entrez un caractère: ");
	scanf("%c", &entry);
	for (int i = 0; i <= 5; i++) {
		if (arr[i] == entry) {
			boolean++;
			break;
		}
	}
	
	if (boolean == 0) {
		printf("L'entrée n'est pas une voyelle.\n'");
	} else {
		printf("L'entrée est une voyelle.\n");
	}
	
	
	return 0;
}
