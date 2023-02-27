/*
Loïs GALLAUD 1A Généraliste
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"object.h"

#define TAILLE 30

int load_objects(object_t* object);
void list_objects(object_t* object, int nbObject);

int load_objects(object_t* object) {
	FILE *f;
	char tmp0[TAILLE];
	int tmp1;
	double tmp2;
	double tmp3;
	double tmp4;
	double tmp5;
	char tmp6[TAILLE];
	int count;
	
	f = fopen("data.txt", "r");
	fscanf(f, "%d", &count);
	
	while (fscanf(f, "%s %d %lf %lf %lf %lf %s", tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, tmp6) != EOF) {
		strcpy(object->name, tmp0);
		object->type = tmp1;
		object->ra = tmp2;
		object->dec = tmp3;
		object->magnitude = tmp4;
		object->redshift = tmp5;
		strcpy(object->imageFile, tmp6);
	}
	
	fclose(f);
	return 0;
}

void list_objects(object_t* objets_stellaires, int nbObject) {
	for (int i=0; i<nbObject; i++) {
		printf("%d)\t%s\n", i, objets_stellaires[0][i]);
	}
}


int main(void) {
	static object_t objets_stellaires[TAILLE];
	int obj_lu = 0;
	load_objects(objets_stellaires);
	list_objects(objets_stellaires, 12);
	
	return 0;
}
