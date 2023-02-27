/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int n = 10;
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i <= 2*n+1) {
		while (j <= k) {
			printf("%d",j);
			j++;
		}
		
		j=0;
		printf("\n");
		
		if (i < n) {	
			k++;
		} else {
			k--;
		}
		i++;
	}
	return 0;
}
