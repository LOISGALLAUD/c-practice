/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

void Fahrenheit(void);

void Fahrenheit(void) {
	double entryF;
	double conversion;
	printf("What is the temperature in celcius you want to convert? \n");
	scanf("%lf", &entryF);
	conversion = (5./9) * (entryF-32);
	printf("The temperature is %f.\n", conversion);
}


int main(void){
	Fahrenheit();
	return 0;
}
