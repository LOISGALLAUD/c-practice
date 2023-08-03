/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>

#define c 299792


double velocityFromZ(double z);
double distanceFromMagnitude(double magn);
void velocity_tab(double *tab_decalage, int taille);
void distance_tab(double *tab_magn, int taille);
double sum(double arr[], int size);
double sum2(double arr[], int size);
double summult(double arr1[], double arr2[], int size);
void reglin(double X[], double Y[], double* a, double* b, int taille);



double velocityFromZ(double z) {
	return z*c;
}

double distanceFromMagnitude(double magn) {
	return 286.7*magn - 4450.7;
}

void velocity_tab(double *tab_decalage, int taille) {
	for (int i=0; i<taille; i++) {
		*(tab_decalage+i) = velocityFromZ(*(tab_decalage+i));
	}
}

void distance_tab(double *tab_magn, int taille) {
	for (int i=0; i<taille; i++) {
		*(tab_magn+i) = distanceFromMagnitude(*(tab_magn+i));
	}
}

double sum(double arr[], int size) {
	double somme = 0;
	for (int i = 0; i<size; i++) {
		somme += arr[i];
	}
	return somme;
}

double sum2(double arr[], int size) {
	double somme = 0;
	for (int i = 0; i<size; i++) {
		somme += arr[i]*arr[i];
	}
	return somme;
}

double summult(double arr1[], double arr2[], int size) {
	double somme = 0;
	for (int i = 0; i<size; i++) {
		somme += arr2[i]*arr1[i];
	}
	return somme;
}

void reglin(double X[], double Y[], double* a, double* b, int taille) {
	double sumx = sum(X, taille);
	double sumy = sum(Y, taille);
	double sumx2 = sum2(X, taille);
	double sumy2 = sum2(Y, taille);
	double summulti = summult(X, Y, taille);
	
	*a = (taille*summulti-sumx*sumy)/(taille*sumx2-sumx*sumx);
	*b = ((1./taille)*sumy) - ((*a)*(1./taille)*sumx);
}

int main(void) {

	/* Questions 1 et 2
	
	double decalage;
	double magnitude;

	printf("Entrez un décalage vers le rouge (sans unité):");
	scanf("%lf", &decalage);
	
	printf("Vitesse de l'objet stellaire associé: %f\n", velocityFromZ(decalage));
	
	printf("Entrez une magnitude (sans unité):");
	scanf("%lf", &decalage);
	
	printf("Vitesse de l'objet stellaire associé: %f\n", velocityFromZ(decalage));
	*/
	
	
	FILE *f;
	FILE *result;
	double tab_magn[5];
	double tab_decalage[5];
	int i = 0;
	int j = 0;
	double a = 0;
	double b = 0;
	double tmp;
	
	f = fopen("data_hubble.txt", "r");
	
	// Vérifie l'ouverture du fichier
	if (f == NULL) {
		printf("ERROR");
		return -2;
	}
	
	
	// Question 3
	while (fscanf(f, "%lf", &tmp) != EOF) {
		if (i%2==0) {
			*(tab_magn+j) = tmp;
		}
		else {
			*(tab_decalage+j) = tmp;
			j++;
		}
		i++;
	}
	
	fclose(f);
	
	/* Vérification Question 3
	for (int j=0; j<5; j++) {
		printf("%f\t", *(tab_magn+j));
		printf("%f\n", *(tab_decalage+j));
	}*/
	
	
	// Calcul des vitesses et distances
	velocity_tab(tab_decalage, 5);
	distance_tab(tab_magn, 5);
	
	// Vérification changements
	/*for (int j=0; j<5; j++) {
		printf("%f\t", *(tab_magn+j));
		printf("%f\n", *(tab_decalage+j));
	}*/
	
	// Regression linéaire
	reglin(tab_magn, tab_decalage, &a, &b, 5);
	printf("\nLa constante de Hubble H0 = %f\n", a);
	
	result = fopen("result.txt", "w");
	
	// Vérifie l'ouverture du fichier
	if (result == NULL) {
		printf("ERROR");
		return -2;
	}

	// Question 5
	fprintf(result, "%f", a);
	fclose(result);
	
	printf("EOF\n");
	
	return 0;
}
