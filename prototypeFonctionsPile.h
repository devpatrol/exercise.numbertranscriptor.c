#ifndef PROTOTYPEFONCTIONSPILE_H
#define PROTOTYPEFONCTIONSPILE_H
#include "pile_fonction.c"

// cette fonction permet d'initialiser notre pile
pile *init_pile();

// cette fonction permet d'empiler les caracteres
void empiler(pile *p, char parentheseOuvrante);

// cette fonction permet de depiler les caracteres
void depiler(pile *p);

// cette fonction permet d'afficher le contenu de la pile
void afficherPile(pile *p);

#endif