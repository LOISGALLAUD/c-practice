/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

int random_range(int, int);
void affiche (int *tab, int n);

int random_range (int range_min, int range_max) {
/**************************************************************
*Retourne un entier dans l’intervalle [range_min , range_max] *
***************************************************************/
	return range_min+(rand()%(range_max-range_min));
}


void affiche (int *tab, int n) {
	int i;
	for (i=0; i<=n ; i++){
		printf("+----"); 
		}
	printf("+\n");
	for (i=0; i<=n ; i++){
		printf("| %d ",*(tab+i)); 
		}
	printf("|\n");
	for (i=0; i<=n ; i++){
		printf("+----"); 
		}
	printf("+\n");
	}
	
	
int main() {
	int n1;
	int n2;
	int* tab1 = NULL;
	int* tab2 = NULL;
	int* tab = NULL;
	
	printf("Choissisez la taille du premier tableau:");
	scanf("%i", &n1);
	printf("Choissisez la taille du second tableau:");
	scanf("%i", &n2);
	
	tab1 = (int*)malloc((n1-1)*sizeof(int));
	tab2 = (int*)malloc((n2-1)*sizeof(int));
	tab = (int*)malloc((n1-1+n2-1)*sizeof(int));
	
	if (tab1 == NULL || tab2 == NULL || tab == NULL) { 
		printf("echec de l’allocation");
		return (-1);
	}
	
	for (int i = 0; i<n1; i++) {
		*(tab1+i) = random_range(0,99);
	}
	for (int i = 0; i<n2; i++) {
		*(tab2+i) = random_range(0,99);
	}
	
	for (int i = 0; i<n1+n2; i++) {
		if (i<=n1) {
		*(tab+i) = *(tab1+i);
		}
		if (i>n1) {
		*(tab+i) = *(tab2+i-n1);
		}
	}
	
	affiche(tab1, n1);
	affiche(tab2, n2);
	affiche(tab, n1+n2);
	free(tab1);
	free(tab2);
	free(tab);
	
	return(0); 
	}
