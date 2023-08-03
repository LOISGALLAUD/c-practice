/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"object.h"

#define C 299792
#define MPC 3.085*pow(10, 19)

void register_object(object_t* object, char* name, int type, double ra, double dec, double magnitude, double redshift, char* imageFile);
double velocityFromZ(double z);
void display_object(object_t* object);
void display_photo(object_t* object);
double univers_an(double H0);


void register_object(object_t* object, char* name, int type, double ra, double dec, double magnitude, double redshift, char* imageFile) {
	strcpy(object->name, name);
	object->type = type;
	object->ra = ra;
	object->dec = dec;
	object->magnitude = magnitude;
	object->redshift = redshift;
	strcpy(object->imageFile, imageFile);
}

double velocityFromZ(double z) {
	return z*C;
}

void display_object(object_t* object) {
	printf("-----------------------------------\n");
	printf("        objet : %s\n", object->name);
	printf("-----------------------------------\n");
	printf("type : %c\n", object->type);
	printf("position : %f ra  %f dec\n", object->ra, object->dec);
	printf("redshift : %f\n", object->redshift);
	printf("magnitude : %f\n", object->magnitude);
	printf("Nom du fichier : %s\n", object->imageFile);
}

void display_photo(object_t* object) {
	char cmd[50]= "eog ";
	strcat(cmd,  object->imageFile);
	system(cmd);
}

double univers_an(double H0) {
	double age = MPC/H0;
	age /= 60; //sec->min
	age /= 60; //min->heures
	age /= 24; //heures->jours
	age /= 365.25; //jours->annee
	return age;	
}

int main(void) {
	object_t objet;
	
	char name[]="ngc4437";
	int type=1; // (galaxie)
	double ra =188.19;
	double dec = 0.1139;
	double magnitude = 15.7;
	double z = 0.00374;
	char imageFile[]="./images/ngc4437.jpg";
	
	FILE *f;
	double H0;
	f = fopen("result.txt", "r");
	// Vérifie l'ouverture du fichier
	if (f == NULL) {
		printf("ERROR");
		return -2;
	}
	fscanf(f, "%lf", &H0);
	fclose(f);
	
	register_object(&objet, name, type, ra, dec, magnitude, velocityFromZ(z), imageFile);
	display_object(&objet);
	//display_photo(&objet);
	
	printf("L'âge de l'Univers est: %f\n", univers_an(H0));
	return 0;
}
