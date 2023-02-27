/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>

int FiboRec(int n);

int FiboRec(int n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		 return 1;
	} else {
		return FiboRec(n-1)+FiboRec(n-2);
	}
}

void main (void) {
	int entry;
	printf("Enter an integer: ");
	scanf("%i", &entry);
	printf("Fibonacci sequence step %i: %i\n", entry, FiboRec(entry));
}
