/*
Loïs GALLAUD
25/02

*/

#include<stdio.h>    /* prototypes de printf,scanf */
#include<stdlib.h>   /* prototypes de malloc, rand */

#define c 299792.458 /*speed of light in km/s*/

/*Prototypes*/
double velocity_from_Z(double); /*calculates the velocity from the redshift*/

/*Function definition*/
double velocity_from_Z(double z){
    return c*z;
}


/*Main function*/
int main(){
    double z;
    printf("Enter the redshift: ");
    scanf("%lf",&z);
    printf("The velocity is %lf km/s",velocity_from_Z(z));
    return 0;
}
