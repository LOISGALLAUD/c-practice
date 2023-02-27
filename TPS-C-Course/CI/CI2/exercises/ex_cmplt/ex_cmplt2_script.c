/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("\n");
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
