#include "structurePile.c"

// cette fonction permet d'initialiser notre pile
pile *init_pile()
{

    pile *p = malloc(sizeof(pile));
    caractere *nouveau = malloc(sizeof(caractere *));

    if (p == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->caractere = '0'; // on initialise la pile avec le caractere '0'. Ainsi, dire que la pile est vide revient a dire que le dernier caractere est '0'
    nouveau->suivant = NULL;
    p->premier = nouveau;

    return p;
}

// cette fonction permet d'empiler les caracteres
void empiler(pile *p, char caractereEmpiler)
{

    caractere *nouveau = malloc(sizeof(caractere *)); // on alloue de l'espace memoire pour le nouveau caractere qu'on va empiler

    nouveau->caractere = caractereEmpiler;
    nouveau->suivant = p->premier;
    p->premier = nouveau;
}

// cette fonction permet de depiler les caracteres
void depiler(pile *p)
{
    caractere *caractereDepile = p->premier;

    if (caractereDepile->caractere != '0') // on verifie si la pile n'est pas vide (le sommet de la pile est different de '0')
    {
        p->premier = caractereDepile->suivant;
        free(caractereDepile);
    }
}

// cette fonction permet d'afficher le contenu de la pile
void afficherPile(pile *p)
{
    caractere *caractere_a_afficher = p->premier;

    while (caractere_a_afficher->caractere != '0')
    {
        printf(" %c", caractere_a_afficher->caractere);
        caractere_a_afficher = caractere_a_afficher->suivant;
    }
    printf("\n\n");
}
