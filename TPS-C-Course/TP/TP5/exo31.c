/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkISBN(char* codeISBN, int len);

int checkISBN(char* codeISBN, int len) {
	int s1[30];
	int s2 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	
	printf("s1 = [\t");
	for (int i = 0; i<len; i++) {
		//conversion
		if (*(codeISBN+i) != (int)'X'){
		*(codeISBN+i) = (int)*(codeISBN+i)-48; //-48 pour convertir les valeurs ascii
		} else {
			*(codeISBN+i) = 10; //converti "X" en 10 (de type int)
		}
		
		//initialisation de s1
		tmp1 += *(codeISBN+i);
		*(s1+i) = tmp1;
		printf("%d\t", tmp1);
		
		//calcul de s2
		tmp2 += tmp1;
	}
	
	printf("]\ns2 = %d\n", tmp2);
	
	if (tmp2%11 == 0) {
		printf("Le code est valide.\n");
		return 1;
	}
	
	printf("Le code n'est pas valide.\n");
	return 0;
}

int main (void) {
	char codeISBN[30];
	int len;
	
	printf("Saisissez un code ISBN:");
	scanf("%s", codeISBN);
	len = strlen(codeISBN);
	
	checkISBN(codeISBN, len);
	
	return 0;
}
