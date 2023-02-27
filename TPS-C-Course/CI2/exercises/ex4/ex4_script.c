/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	const int TVA = 20; // in percents
	double brut_price, net_price;
	
	printf("Enter a net price: ");
	scanf("%lf", &net_price);
	
	brut_price = net_price + net_price * ((double)TVA/100); // Type conversion from int to double
	
	printf("Net price is: %f\nBrut price is: %f\n", net_price, brut_price);
	return 0;
}
