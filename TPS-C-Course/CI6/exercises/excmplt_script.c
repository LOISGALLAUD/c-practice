/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
	
int tarifs(double km_total, double nb_jours_total, float* prix_coutant1, float* prix_coutant2);

int tarifs(double km_total, double nb_jours_total, float* prix_coutant1, float* prix_coutant2) {
	*prix_coutant1 += 60.*nb_jours_total;
	if (km_total>200.) {
		*prix_coutant1 += 0.2*(200-km_total);
	}
	
	*prix_coutant2 += 80.*nb_jours_total;
	if (km_total>300.) {
		*prix_coutant2 += 0.05*(300-km_total);
	}
	return 0;
}
	
int main() {
	double km;
	double nb_jours;

	float prix_coutant1 = 0;
	float prix_coutant2 = 0;
	
	printf("Saisissez le nombre de km:");
	scanf("%lf", &km);
	printf("Saisissez le nombre de jours de location:");
	scanf("%lf", &nb_jours);
	tarifs(km, nb_jours, &prix_coutant1, &prix_coutant2);
	
	printf("Tarifs 1:\t%f\n", prix_coutant1);
	printf("Tarifs 2:\t%f\n", prix_coutant2);
		
	return 0; 
	}
