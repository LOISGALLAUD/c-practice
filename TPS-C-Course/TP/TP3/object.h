#ifndef OBJECT_H
#define OBJECT_H


typedef struct
{
	char name[40];
	int type;		/* -1=non-defini  0=etoile, 1=galaxie, 2=quasar*/
	double ra,dec;		/*position dans le ciel:  ascension droite et declinaison */
	double magnitude;	/*intensité lumineuse*/
	double redshift;	/*decalage dans le rouge du spectre*/
	char imageFile[40];	/*nom du fichier image associe*/
} object_t;


#endif
