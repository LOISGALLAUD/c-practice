/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>
#include<math.h>

int main(void){
	double first_side;
	double second_side;
	double hypotenuse;
	
	printf("Please enter the lenght of the first side of your triangle: ");
	scanf("%lf", &first_side);
	printf("\n");
	
	printf("Please enter the lenght of the second side: ");
	scanf("%lf", &second_side);
	printf("\n");
	
	hypotenuse = sqrt(first_side*first_side+second_side*second_side);
	
	printf("The lenght of the hypotenuse is: %f\n", hypotenuse);
	
	return 0;
}
