/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	char car;
	
	printf("Please enter a character: ");
	scanf("%c", &car);
	printf("\n");
	
	if (car=='a'||car=='e'||car=='i'||car=='o'||car=='u'||car=='y'){
	printf("Your entry is a vowel.\n");
	}
	else {
	printf("Your entry is a consonant.\n");
	}
	
	
	return 0;
}
