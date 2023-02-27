/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>
#define MAX_SIZE 200

int main(void){
	FILE *f;
	int tmp;
	int temperatures[MAX_SIZE];
	int i = 0;
		
	f = fopen("date_temperature.txt", "r");
	
	while (fscanf(f,"%d", &tmp) != EOF) {
		temperatures[i] = tmp;
		printf("%i\n", temperatures[i]);
		i++;
	}
	
	return 0;
}
