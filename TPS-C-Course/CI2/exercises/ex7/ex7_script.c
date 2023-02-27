/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int integer;
	int result;
	int i = 0;
	
	printf("Please enter a integer: ");
	scanf("%d", &integer);
	printf("\n");
	
	while (i <= 20){
		result = i*integer;
		printf("%d x %d = %d\n", i, integer, result);
		i++;
	}
	
	return 0;
}
