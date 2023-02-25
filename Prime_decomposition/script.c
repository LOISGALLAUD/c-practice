/*
Loïs GALLAUD
24/02

This program is a prime decomposition program.
*/

#include <stdio.h>  /*Prototypes of printf, scanf...*/
#include <stdlib.h> /*Prototypes of malloc, free...*/


/*Prototypes*/
int is_prime(int n);
int prime_numbers(int n, int* array);
int prime_factorization(int n, int* array, int* array2);

/*Functions definition*/
int is_prime(int n){
    int i;
    for(i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int prime_numbers(int n, int* array){
    int count=0;
    int i;
    for(i=2; i<n; i++){
        if(is_prime(i)){
            array[count] = i;
            count++;
        }
    }
    return count;
}

int prime_factorization(int n, int* array, int* array2){
    int count=0;
    for (int i = 0; i < n; i++){
        while (n%array[i]==0){
            array2[count] = array[i];
            n = n/array[i];
            count++;
        }
    }
    return count;
}

/*Main function*/
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(is_prime(n)){
        printf("%d is prime.", n);
    }else{
        printf("%d isn't prime.", n);
    }

    int* array = (int*) malloc(n*sizeof(int));
    int count = prime_numbers(n, array);
    int* array2 = (int*) malloc(n*sizeof(int));
    int count2 = prime_factorization(n, array, array2);

    printf("\nPrime numbers under %d are: ", n);
    for (int i = 0; i < count; i++){
        printf("%d ", array[i]);
    }

    printf("\nPrime decomposition of %d: ", n);
    for (int i = 0; i < count2; i++){
        printf("%d ", array2[i]);
    }

    return 0;
}