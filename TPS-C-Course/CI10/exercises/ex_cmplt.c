/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>

int main (void) {
	FILE *f;
	f = fopen("/etc/passwd");
	int tmp = 0;
	
	while (fscanf(f, "%d", &tmp) != EOF) {
		printf("%d", tmp);
	}
	
	return 0;
}
