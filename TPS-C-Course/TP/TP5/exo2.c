/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int is_palindrome(char* str, int len);

int is_palindrome(char* str, int len){
	if (len%2==0) {
		for (int i = 0; i<=len/2; i++) {
			if (*(str+i) == *(str+len-i)) {
				return 0;
			}
		}
	} else {
		for (int i = 0; i<len/2; i++) {
			if (*(str+i) == *(str+len-i)) {
				return 0;
			}
		}
	}
	return 1;
}

int main (void) {
	char str[30];
	int len;
	int booleen;
	
	printf("Entrez une chaine de caracteres: ");
	scanf("%s", str);
	len = strlen(str);
	
	booleen = is_palindrome(str, len);
	
	if (booleen) {
		printf("C'est un palindrome.\n");
	} else {
		printf("Ce n'est pas un palindrome.\n");
	}
	
	return 0;
}
