/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<math.h>

void affiche (int *tab, int n);
int stat(int *tab, int n);

void affiche (int *tab, int n) {
	int i;
	for (i=0; i<n ; i++){
		printf("|%d",tab[i]); 
		}
	printf("|\n");
	}
	
int stat(int *tab, int n) {
	int sommeM = 0;
	float sommeT = 0;
	float moyenne = 0;
	float ecartT = 0;
	
	for (int i = 0; i <= n; i++) {
		sommeM += tab[i];
	}
	moyenne = sommeM/n;
	
	for (int i = 0; i <= n; i++) {
		sommeT += (tab[i]-moyenne)*(tab[i]-moyenne);
	}
	ecartT = sqrt((1/n)*sommeT);
	
	return moyenne;
}
	
	
int main() {
	int notes[5] = {12 ,13 ,5 ,8, 16};
	
	affiche(notes, 4);
	affiche(stat(notes, 4), 2);
	
	return(0); 
	}
