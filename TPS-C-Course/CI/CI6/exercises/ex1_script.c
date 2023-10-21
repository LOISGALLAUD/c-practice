/*
Loïs GALLAUD 1A Généraliste
*/

#include <stdio.h>

int conversion(int montantBillet, int indiceBillet);
void distribution(int somme);

int billet[3] = {
    1, 2, 14}; // Types de billets références qui servent pour la conversion.

int conversion(int montantBillet, int indiceBillet)
{
    int billetsConvertis = 0;

    // Tant qu'on peut retirer des billets de valeur "indiceBillet", on
    // décrémente le montant total.
    while (montantBillet - indiceBillet > 0)
    {
        billetsConvertis++;
        montantBillet -= indiceBillet;
    }

    // Si le compte est bon, il ne faut pas oublier de compter 1 fois (on
    // pourrait modifier le code et utiliser une structure en do-while pour
    // faire cela.)
    if (montantBillet - indiceBillet == 0)
    {
        billetsConvertis++;
    }

    return billetsConvertis;
}

void distribution(int somme)
{
    int billetsConvertis_Dist;

    printf("La somme convertie en billets est:\n");

    // Pour chaque valeur de billet référence on convertit en décrémentant au
    // fur et à mesure le montant total.
    for (int i = (sizeof(billet) / sizeof(int)) - 1; i >= 0; i--)
    {
        billetsConvertis_Dist = conversion(somme, billet[i]);

        printf("\nBillet de %i: %i\n", billet[i], billetsConvertis_Dist);
        somme -= billetsConvertis_Dist * billet[i];
    }

    // Restes non convertissables en billets:
    printf("\nIl reste %i euros à convertir.\n", somme);
}

int main(void)
{
    int entry;
    printf("Entrez un montant à convertir en billets: ");
    scanf("%i", &entry);
    distribution(entry);

    return 0;
}
