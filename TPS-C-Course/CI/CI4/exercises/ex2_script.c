/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>
#include<math.h>

#define gamma 7./5.

double VitesseGaz(double temperature, const double constGaz);

double VitesseGaz(double temperature, const double constGaz) {
	return sqrt((gamma)*constGaz*(temperature+273.15));
}


int main(void){
	double temp;
	double constante;
	
	printf("Entrez une température de gaz: ");
	scanf("%lf", &temp);
	printf("Entrez une constante de gaz (air = 287): ");
	scanf("%lf", &constante);
	
	printf("Le vitesse du son dans le gaz est: %f\n", VitesseGaz(287, 30));
	return 0;
}
