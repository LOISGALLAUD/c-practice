/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int var;
	
	printf("Please enter a number: ");
	scanf("%i", &var);
	printf("\n");
	
	if (var%2 == 0){
	printf("Your entry is odd.\n");
	}
	else {
	printf("Your entry is even.\n");
	}
	
	if (var < 0){
	printf("Your entry is a negative number.\n");
	}
	else if (var > 0){
	printf("Your entry is a positive number.\n");
	}
	else {
	printf("Your entry is not positive nor negative, its 0!\n");
	}
	
	return 0;
}
