/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	double first_side;
	double second_side;
	double area;
	
	printf("Enter the length of the first side: \n");
	scanf("%lf", &first_side);
	printf("Enter the length of the second side: \n");
	scanf("%lf", &second_side);
	
	area = first_side*second_side/2; // Area formula of a right triangle
	printf("The area of your right triangle is %f\n", area);
	
	return 0;
}
