/*
Loïs GALLAUD
25/02

This script is a simple example of how to use arrays in C.
It shows how to use a fixed size array and how to sort it.
*/

#include<stdio.h>    /* prototypes de printf,scanf */
#include<stdlib.h>   /* prototypes de malloc, rand */

/*Prototypes*/
void show_array2D(int **, int, int ); /*affichage d'un array 2D*/
int sum_line(int **, int, int); /*sum of line*/
int sum_column(int **, int, int); /*sum of column*/
int square_test(int **, int, int); /*Tests if the square is magic*/

/*Function definition*/
void show_array2D(int  **array, int lines, int columns){
	int i,j;
	for (i=0;i<lines;i++){
		for (j=0;j<columns;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}

int sum_line(int **array, int columns, int line_index){
	int sum=0;
	for (int j=0;j<columns;j++){
		sum+=array[line_index][j];
	}
	return sum;
}

int sum_column(int **array, int lines, int column_index){
	int sum=0;
	for (int i=0;i<lines;i++){
			sum+=array[i][column_index];
	}
	return sum;
}

int sum_diag(int **array, int lines, int diag_index){
	int sum=0;
	if (diag_index==0){
		for (int i=0;i<lines;i++){
			sum+=array[i][i];
		}
	}
	else{
		for (int i=0;i<lines;i++){
			sum+=array[i][lines-i-1];
		}
	}
	return sum;
}

int square_test(int **array, int lines, int columns){
	int line_sum_ref = sum_line(array, columns, 0);
	int column_sum_ref = sum_column(array, columns, 0);
	int diag_sum_ref = sum_diag(array, lines, 0);
	for (int i=0;i<lines;i++){
		if (sum_line(array, columns, i) != line_sum_ref){
			return 0;
		}
	}
	for (int i=0;i<columns;i++){
		if (sum_column(array, lines, i) != column_sum_ref){
			return 0;
		}
	}
	if (sum_diag(array, lines, 1) != diag_sum_ref){
		return 0;
	}
	return 1;
}

/*Main function*/
int main(){
	int n = 3;
	int n2 = 4;
	int **square;
	int **square2;

	/*allocation du array de pointeur dynamique*/
	square = (int **)malloc(n*sizeof(int *));
	square2 = (int **)malloc(n2*sizeof(int *));

	for (int i = 0; i < n; i++) {
    	square[i] = (int *)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n2; i++) {
    	square2[i] = (int *)malloc(n2 * sizeof(int));
	}

	/* Magic Square 3x3 TRUE */
	square[0][0]= 6; square[0][1]= 7; square[0][2]= 2;  /*filled by hand to debug easily*/
	square[1][0]= 1; square[1][1]= 5; square[1][2]= 9;  /*could be entered on keyboard*/
	square[2][0]= 8; square[2][1]= 3; square[2][2]= 4;  /*or read from a file*/

	/* Magic Square 4x4 but is it true? */
	square2[0][0]=  1; square2[0][1]= 12; square2[0][2]=  8; square2[0][3]= 13;  
	square2[1][0]=  6; square2[1][1]= 15; square2[1][2]=  3; square2[1][3]= 10;  
	square2[2][0]= 11; square2[2][1]=  2; square2[2][2]= 14; square2[2][3]=  7;  
	square2[3][0]= 16; square2[3][1]=  9; square2[3][2]=  5; square2[3][3]=  4;  

	/*Show*/
	show_array2D(square, n, n);
	printf("\n");
	show_array2D(square2, n2, n2);
	
	if (square_test(square, n, n)){
		printf("\nThis square is magic!");
	}
	else{
		printf("\nThis square is not magic!");
	}

	if (square_test(square2, n2, n2)){
		printf("\nSquare2 is magic!");
	}
	else{
		printf("\nSquare2 is not magic!");
	}

	/*Freeing memory*/
	free(square);
	free(square2);

	return 0;
}
