/*
Loïs GALLAUD 1A Généraliste
*/

#include <stdio.h>   	/*Prototypes of printf, scanf...*/
#include <stdlib.h>   	/*Prototypes of malloc, free...*/
#include <math.h>

void P_init(int *P, int n);
void elimine_mult(int* P, int n);
int is_mult(int k, int l);
int conv_int(int* P, int n, int* tab);
int decomp_premier(int* nb_prem, int size, int num, int* decomposition);
void get_unique(int* decomposition, int size);

struct factor {
	int premier;
	int multiplicite;
};


// Met toutes les valeurs de P à True.
void P_init(int *P, int n) {
	for (int i = 1; i<n; i++) {
		*(P+i) = 1;
	}
}

int is_mult(int k, int l) {
	if (k%l==0) {
		return 1;
	}
	return 0;
}

void elimine_mult(int* P, int n) {
	int lim = (int)sqrt(n);
	printf("%d\n", lim);
	for (int i = 2; i<=lim; i ++) {
		for (int j = i+1; j<=n; j ++) {
			if (is_mult(j, i)) {
				*(P+j-1) = 0;
			}
		}
	}
}


int conv_int(int* P, int n, int* tab) {
	int step = 0;
	for (int i = 0; i<=n; i++) {
		if (*(P+i)) {
			*(tab+step) = i+1;
			printf("%d ", i+1);
			step++;
		}
	}
	printf("\n");
	return step;
}

int decomp_premier(int* nb_prem, int size, int num, int* decomposition) {
	int step = 0;
	printf("Prime factorization : ");
	for (int i = 0; i<size; i++) {
		while (num%*(nb_prem+i)==0) {
			num /= *(nb_prem+i);
			*(decomposition+step) = *(nb_prem+i);
			
			printf("%d ", *(decomposition+step));
			
			step++;
			}
	}
	return step;
}


int main(void) {
	int num, number;
	int* P;
	int* nb_prem;
	int* decomposition;
	int qtt_nb_prem;
	
	printf("Enter a number to test:\n");
	scanf("%d",&num);
	number = num-1;
	P=(int*)malloc(number*sizeof(int));
	P_init(P, number);
	
	elimine_mult(P, number);
	
	nb_prem=(int*)malloc(((int)sqrt(number))*sizeof(int));
	qtt_nb_prem = conv_int(P, number, nb_prem);
	free(P);
	
	decomposition=(int*)malloc(qtt_nb_prem*sizeof(int));
	
	free(nb_prem);
	
	return 0;
}
