/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int n;
	int count = 0;
	double average = 0;
	
	printf("Enter integers and enter -1 when you are done.\n");
	
	do {
		printf("Enter an integer: ");
		scanf("%d", &n);
		printf("\n");
		
		if (n != -1){
			average += n;
			count++;
		}
	}while(n!=-1);
	
	printf("The average of all the integers is: %f\n", average/count);
	
	return 0;
}
