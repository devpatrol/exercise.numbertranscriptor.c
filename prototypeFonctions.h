#ifndef PROTOTYPEFONCTIONS_H
#define PROTOTYPEFONCTIONS_H
#include "fonctions.c"

// cette fonction verifie que l'expression saisie est composee uniquement des caracteres acceptes
int expressionValide(char *expression, int nombreCaracteres);

// Cette fonction verifie que l'expression ne comporte aucun caractere special c-a-d l'expression est faite uniquement d'une suite de chiffres
int expressionSimple(char *expression, int nombreCaracteres);

// cette fonction verifie si les caracteres de debut et de fin correspondent a un des caracteres speciaux qui sont definis dans la fonction
void verifiacationCaractereDebut_Fin(char *expression, int nombreCaracteres, char *caractereDebut, char *caractereFin, int *erreurDebut, int *erreurFin);

// cette fonction verifie si l'expression contient le caractere '%'
int modulo(char *expression, int nombreCaracteres);

// cette fonction verifie si les nombres de parentheses ouvrantes et fermantes sont egaux et si ces parentheses sont places dans le bon ordre
void parentheses(char expression[], int nombreCaracteres, int *erreurParentheseOuvrante, int *erreurParentheseFermante);

// cette fonction verifie s'il y'a un excedant du caractere '='
int excedantEgalite(char *expression, int nombreCaracteres);

#endif
