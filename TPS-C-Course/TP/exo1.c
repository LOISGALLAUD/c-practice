/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>

#define taux 1.4168

void GBPtoEUR(double gbp, int* partieEntiere, int* centimes);

void GBPtoEUR(double gbp, int* partieEntiere, int* centimes) {
	double eur = taux*gbp;
	*partieEntiere = (int) eur;
	*centimes = 100*(eur - (double)(*partieEntiere));
}


int main (void) {
	double gbp;
	int *partieEntiere = NULL;
	int *centimes = NULL;
	
	partieEntiere = (int*)malloc(sizeof(int));
	centimes = (int*)malloc(sizeof(int));
	
	printf("Rentrez un montant en livre Sterling:");
	scanf("%lf", &gbp);
	
	GBPtoEUR(gbp, partieEntiere, centimes);
	
	printf("Votre change en Euros est: %d euros et %d centimes.\n", *partieEntiere, *centimes);
	free(partieEntiere);
	free(centimes);
	return 0;
}
