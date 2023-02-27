/******************************************************************
 * 
 *      TP1
 * 
 * ****************************************************************/
 
#include <stdio.h>   	/*Prototypes of printf, scanf...*/
#include <stdlib.h>   	/*Prototypes of malloc, free...*/


/******* Prototypes ***********************************************/
int is_prime(int n);
void printf_array(int *tab, int size);
int prime_array(int* tab, int n);
void prime_factors(int num, int* tab, int size, int* is_prime_arg, int* is_power_arg, int* prime_factors);


/************* printf_array() ******************************************
	dysplay elements of a given array:
		Parameters:
		-tab, address of the array where prime numbers are stored, ie array name
		-size, number of element in tab to be displayed.    

***********************************************************************/
void printf_array(int *tab, int size)
{
	int i;
 	for (i=0; i<size; i++)
	{
		 printf("| %d ", tab[i]);
	}	
	printf("|\n");

}
/*************prime_array()*********************************************
	fill the given array with all the prime number under
	an integer n.
		parameters:
		-tab
		-n
***********************************************************************/
int prime_array(int* tab, int n) {
	int step = 0;
	for (int i = 0; i<=n; i++) {
		if (is_prime(i)) {
			*(tab+step) = i;
			step++;
		}
	}
	return step;
}

/*********************************************************************
 int is_prime(int n) : primality test
    parameters:
        - n, integer to test for primality
    return:
        - 1 if number n is prime
          0 otherwise
 *********************************************************************/
int is_prime(int n)
{
	if (n!=0){
		if (n<0) {
			n*=-1;
		}
		
		for (int i = 2; i<n; i++) {
			if (n%i ==0) {
				return 0;
			}
		return 1;
		}
	}
	return 0;
}



/*************prime_factors()********************************************
	fill the given array with all the prime number under
	an integer n.
		parameters:
		-tab
		-n
***********************************************************************/
void prime_factors(int num, int* tab, int size, int* is_prime_arg, int* is_power_arg, int* prime_factors) {
	int step = 0;
	
	if (is_prime(num)) {
		*is_prime_arg = 1;
		printf("The room is trapped. (room is a prime number)\n");
	}
	
	printf("Prime factorization : ");
	for (int i = 0; i<size; i++) {
		while (num%*(tab+i)==0) {
			printf("%d ", *(tab+i));
			num /= *(tab+i);
			*(prime_factors+step) = *(tab+i);
			step++;
			}	
		}
	printf("\n");
	
	for (int j = 0; j<step-1; j++) {
		if (*(prime_factors+step) != *(prime_factors+step+1)) {
			*is_power_arg = 0;
			printf("The room is not a prime power");
			
		}
	}
	if (*is_power_arg!=0) {		
		*is_power_arg = 1;
		printf("The room is trapped. (power of a prime number)\n");
	}
}
/****************************  main **********************************/

int main()
{
	int number=0;
	int *tab;
	int size;
	int is_prime = 0;
	int is_power = 2;
	int *prime_factors_tab;

	/*1- print if number is prime
	if (is_prime(number))
	{
	printf ("%i is a prime number\n", number);
	}
	else
	{
	printf("%i is not a prime number\n",number);
	}
   	*/

	/*2- ask for a number to test*/
	printf("Enter a number to test:\n");
	scanf("%d",&number);
	tab=(int*)malloc(number*sizeof(int));
	size = prime_array(tab, number);
	printf("Size of tab: %d\n", size);
	prime_factors_tab=(int*)malloc(size*sizeof(int));
	
	/*3- decomposition into prime factors*/
	prime_factors(number, tab, size, &is_prime, &is_power, prime_factors_tab);
	free(tab);
    return 0;
}
