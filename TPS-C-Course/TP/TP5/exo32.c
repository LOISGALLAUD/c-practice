/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct livre {
	char titre[50];
	char isbn[50];
};




int checkISBN(char* codeISBN, int len);
void affich(struct livre *tab, int len);
void affich_valid(struct livre *tab, int len, struct livre* alph);
void trie(struct livre *alph, int len);


int checkISBN(char* codeISBN, int len) {
	int s1 = 0;
	int s2 = 0;
	int i;
	
	for (i = 0; i<len; i++) {
		/*conversion*/
		if (*(codeISBN+i) != (int)'X'){
		*(codeISBN+i) = (int)*(codeISBN+i)-48;
		} else {
			*(codeISBN+i) = 10;
		}
		
		/*initialisation de s1*/
		s1 += *(codeISBN+i);
		
		/*calcul de s2*/
		s2 += s1;
	}
	
	if (s2%11 == 0) {
		return 1;
	}

	return 0;
}


void affich(struct livre *tab, int len) {
	int i;
	for (i = 0; i<=len; i++) {
		printf("%s\t%s\n", (tab+i)->titre, (tab+i)->isbn);
	}
}

void affich_valid(struct livre *tab, int len, struct livre* alph) {
	int count = 0;
	int i;
	
	printf("La liste des livres dont l'ISBN est valide est:\n\n");
	for (i = 0; i<len; i++) {
		if (checkISBN(tab[i].isbn, strlen(tab[i].isbn))) {
			printf("%s\n", tab[i].titre);
			alph[count] = tab[i];
			count++;
			}
	}
}


void trie(struct livre *alph, int len) {
	double ordreAlph;
	struct livre tmp;
	int i;
	int j;
	

	for(i = 0;i<len;i++) { /*pour faire l'operation N fois*/
	/*
		for (int k = 0; k<len; k++) {
			printf("%s ", alph[k].titre);
		}*/
		printf("\n");
		
		    for(j = i;j<len;j++) {
		    	printf("%d", strcmp(alph[j].titre, alph[j+1].titre));
		    
			if (strcmp(alph[j].titre, alph[j+1].titre) > 0) {
				tmp = alph[j];
				alph[j] = alph[j+1];
				alph[j+1] = tmp;
				}
			}   
	}	
}


int main (void) {
	char codeISBN[50];
	int len;
	char titre[50];
	struct livre tab[20];
	int i = 0;
	char tmp;
	struct livre alph[10];
	struct livre tmptab[10];
	int lenTriee;
	
	FILE *f;
	
	f = fopen("livres.txt", "r");
	
	/*Vérifie l'ouverture du fichier*/
	if (f == NULL) {
		printf("ERROR");
		return -2;
	}
	
	while (fscanf(f, "%s %s", tab[i].titre, tab[i].isbn) != EOF) {
		i++;
	}
	
	affich_valid(tab, 10, alph);
	
	printf("\nDebut du tri\n\n");
	trie(alph, 5);
	
	printf("\n");
	
	affich_valid(alph, 5, tmptab);
	
	fclose(f);
	return 0;
}
