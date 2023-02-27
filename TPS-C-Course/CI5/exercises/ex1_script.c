/*
Loïs GALLAUD 1A généraliste
*/

#include<stdio.h>

int main(void){
	float a = 1.0;
	float b = 2.0;
	float *p2, *p1 = &a;
	
	p2 = &b ;
	printf (" p1=%p p2=%p a=%f b=%f *p2=%f\n", p1, p2, a, b, *p2);
	p2 = p1 ;
	printf (" p1=%p p2=%p a=%f b=%f *p2=%f\n", p1, p2, a, b, *p2);
	*p2 = 3 ;
	printf (" p1=%p p2=%p a=%f b=%f *p2=%f\n", p1, p2, a, b, *p2);
	*p1 = *p2+1;
	printf (" p1=%p p2=%p a=%f b=%f *p2=%f\n", p1, p2, a, b, *p2);
	p2 = &b ;
	printf (" p1=%p p2=%p a=%f b=%f *p2=%f\n", p1, p2, a, b, *p2);
	b = *p1+1;
	printf (" p1=%p p2=%p a=%f b=%f *p2=%f\n", p1, p2, a, b, *p2);
	return 0 ;

}
