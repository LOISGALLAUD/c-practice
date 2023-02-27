/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int n;
	int sum = 0;
	
	printf("Please enter a integer: ");
	scanf("%d", &n);
	printf("\n");
	
	for (int i = 0; i <= n; i++){
		sum += i;
	}
	
	printf("The sum of all integer from 0 to %d is: %d\n", n, sum);
	
	return 0;
}
