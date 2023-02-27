/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
	
double sum(double arr[], int size);
double sum2(double arr[], int size);
double summult(double arr1[], double arr2[], int size);
int reglin(double X[], double Y[], double n, double* a, double* b);

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

int reglin(double X[], double Y[], double n, double* a, double* b) {
	double sumx = sum(X, n);
	double sumy = sum(Y, n);
	double sumx2 = sum2(X, n);
	double sumy2 = sum2(Y, n);
	double summulti = summult(X, Y, n);
	
	*a = (n*summulti-sumx*sumy)/(n*sumx2-sumx*sumx);
	*b = ((1./n)*sumy) - ((*a)*(1./n)*sumx);
	
	return 0;
}
	
int main() {
	double a = 0;
	double b = 0;
	double x[]={-4.2, -3.4, -1.3, 0.2, 1.7, 3.8} ;
	double y[]={-3.86, -2.59, 1.29, 3.72, 6.35, 10.07} ;
	
	reglin(x, y, 6., &a, &b);
	printf("y = %f x  +  %f\n", a, b);
	
	return 0; 
	}
