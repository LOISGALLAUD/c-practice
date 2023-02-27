/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	srand(time(NULL));
	
	int random_num = rand()%100;
	int guess;
	int count = 1;
	int maxCount = 10;
	
	do {
		printf("Enter your number: ");
		scanf("%d", &guess);
		printf("\n");
		
		if (guess < random_num){
			printf("Bigger\n");
		} else if (guess > random_num){
			printf("Smaller!\n");
		} else if (guess == random_num){
		printf("You guess the correct number!\n");
		break;
		}
		count++;
		if(maxCount <= count){
			printf("You took too many attempts...\n");
			break;
		}
		
	} while (guess != random_num);
	printf("The answer was %d.\n", random_num);
	return 0;
}
