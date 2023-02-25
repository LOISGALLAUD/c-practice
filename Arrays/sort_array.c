/*
Loïs GALLAUD
25/02

This script is a simple example of how to use arrays in C.
It shows how to use a fixed size array and how to sort it.
*/

#include<stdio.h>    /* prototypes de printf,scanf */
#include<stdlib.h>   /* prototypes de malloc, rand */

#define TAILLE_MAX  20  /*TAILLE_MAX will be remplaced by 20*/
						/*inside the code BEFORE compilation*/
						/*TAILLE_MAX isn't a variable*/


/*Prototypes*/
void affiche_array(int *, int ); /*show array*/
void minmax(int *, int , int *, int *); /*find min and max*/
void tri(int *, int ); /*sort array*/


/*Function definition*/
void affiche_array(int *tableau, int taille){
	int i;
	for (i=0;i<taille;i++){
		printf("%d ",tableau[i]);
	}
	printf("\n");
}

void minmax(int *tableau, int taille, int *min, int *max){
	int i;
	*min=tableau[0];
	*max=tableau[0];
	for (i=0;i<taille;i++){
		if(tableau[i]<*min){
			*min=tableau[i];
		}
		if(tableau[i]>*max){
			*max=tableau[i];
		}
	}
}

void sort(int *tableau, int taille){
	int i,j;
	int tmp;
	for(i=0;i<taille;i++){
		for(j=i+1;j<taille;j++){
			if(tableau[i]>tableau[j]){
				tmp=tableau[i];
				tableau[i]=tableau[j];
				tableau[j]=tmp;
			}
		}
	}
}

/*Main function*/
int main(){
	int i;
	int array[TAILLE_MAX];  /*Array with a fixed sized before*/
  			  	     		/*compilation so no need of malloc*/
	int n;

	printf("Enter the size of the array: ");
	scanf("%d",&n);

	/*Control the size of the array*/
	if(n>TAILLE_MAX){
		printf("Error: array size is too big\n");
		return 1;
	}

	for(i=0;i<n;i++){
		array[i]=(rand()%100)-50;
	}

	/*minmax*/
	int min,max;
	minmax(array,n,&min,&max);
	printf("min=%d max=%d\n",min,max);

	/*Sort the array*/
	sort(array,n);

	/*Show*/
	affiche_array(array,n);
	
	return 0;
}


