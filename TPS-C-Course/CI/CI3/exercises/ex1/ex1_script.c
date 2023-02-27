/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	int arr[5];
	int sum = 0;
	int entry;
	int min;
	int minIndex;
	
	for (int i = 0; i < 5; i++) {
		printf("Entrez un entier: ");
		scanf("%d", &entry);
		arr[i] = entry;
		sum += arr [i];
	}
	
	min = arr[0];
	minIndex = 0;
	for (int i = 1; i < 5; i++) {
		if (min > arr [i]) {
			min = arr[i];
			minIndex = i;
		}
	}
	
	printf("La somme des éléments du tableaux est: %d\n", sum);
	printf("L'élément du tableau le plus petit est: %d\n", min);
	printf("Son indice dans le tableaux est: %d\n", minIndex);
	
	return 0;
}
