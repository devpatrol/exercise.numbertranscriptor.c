#include "prototypeFonctionsPile.h"

// cette fonction verifie que l'expression saisie est composee uniquement des caracteres acceptes
int expressionValide(char *expression, int nombreCaracteres)
{
    int validite = 0;

    for (int i = 0; i < nombreCaracteres; i++)
    {
        if (expression[i] == '0' || expression[i] == '1' || expression[i] == '2' || expression[i] == '3' || expression[i] == '4' ||
            expression[i] == '5' || expression[i] == '6' || expression[i] == '7' || expression[i] == '8' || expression[i] == '9' ||
            expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '(' ||
            expression[i] == ')' || expression[i] == '=' || expression[i] == '.' || expression[i] == '%')
        {
            validite += 1;
        }
        else
        {
            validite -= 1;
        }
    }

    if (validite == nombreCaracteres)
    {
        return 1;
    }

    return 0;
}

// Cette fonction verifie que l'expression ne comporte aucun caractere special c-a-d l'expression est faite uniquement d'une suite de chiffres
int expressionSimple(char *expression, int nombreCaracteres)
{

    char caractereSpeciauxGlobaux[] = {'/', '+', '-', '*', '(', ')', '=', '.'};
    int formeSimple, sortie = 0;

    for (int i = 0; i < nombreCaracteres; i++)
    {
        for (int j = 0; j < strlen(caractereSpeciauxGlobaux); j++)
        {
            if (expression[i] == caractereSpeciauxGlobaux[j])
            {
                formeSimple = 0;
                sortie = 1;
                break;
            }
            else
            {
                formeSimple = 1;
            }
        }

        if (sortie == 1)
        {
            break;
        }
    }

    return formeSimple;
}

// cette fonction verifie si les caracteres de debut et de fin correspondent a un des caracteres speciaux qui sont definis dans la fonction
void verifiacationCaractereDebut_Fin(char *expression, int nombreCaracteres, char *caractereDebut, char *caractereFin, int *erreurDebut, int *erreurFin)
{
    char caractereSpeciauxDebut[] = {'/', '+', '-', '*', '=', '.'}, firstCaractere = expression[0], lastCaractere = expression[nombreCaracteres - 1];

    for (int i = 0; i < strlen(caractereSpeciauxDebut); i++)
    {
        if (firstCaractere == caractereSpeciauxDebut[i])
        {
            *erreurDebut = 1;
            *caractereDebut = caractereSpeciauxDebut[i];
        }
        else if (firstCaractere == ')')
        {
            *erreurDebut = 1;
            *caractereDebut = ')';
        }

        if (lastCaractere == caractereSpeciauxDebut[i])
        {
            *erreurFin = 1;
            *caractereFin = caractereSpeciauxDebut[i];
        }
        else if (lastCaractere == '(')
        {
            *erreurFin = 1;
            *caractereFin = '(';
        }
    }
}

// cette fonction verifie si l'expression contient le caractere '%'
int modulo(char *expression, int nombreCaracteres)
{

    for (int i = 0; i < nombreCaracteres; i++)
    {
        if (expression[i] == '%')
        {
            return 1;
        }
    }

    return 0;
}

// cette fonction verifie s'il y'a un excedant du caractere '='
int excedantEgalite(char *expression, int nombreCaracteres)
{

    int nbre = 0;

    for (int i = 0; i < nombreCaracteres; i++)
    {
        if (expression[i] == '=')
        {
            nbre++;
        }
    }

    if (nbre > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// cette fonction verifie si les nombres de parentheses ouvrantes et fermantes sont egaux et si ces parentheses sont places dans le bon ordre
void parentheses(char expression[], int nombreCaracteres, int *erreurParentheseOuvrante, int *erreurParentheseFermante)
{
    pile *p = init_pile();
    caractere *test = p->premier;

    for (int i = 0; i < nombreCaracteres; i++)
    {
        if (expression[i] == '(')
        {
            empiler(p, expression[i]); // on empile le caractere '('
            test = p->premier;         // la variable test pointe vers le nouveau caractere ajoute dans la pile
        }

        if (expression[i] == ')')
        {
            test = p->premier;
            if (test->caractere == '0') // on verifie si le sommet de la pile correspond a '0'
            {
                *erreurParentheseFermante = 1;
                break;
            }
            else
            {
                depiler(p);        // on depile le caractere '('
                test = p->premier; // la variable test pointe vers le nouveau sommet
            }
        }
    }

    if (test->caractere != '0') // on verifie si la pile est vide. La condition s'execute unique si la pile n'est pas vide
    {
        *erreurParentheseOuvrante = 1;
    }
}

// cette fonction permet de verifier si les caracteres {+,=,/,*,-,.} sont bien places et retourne la pile contenant les caracteres mal placés
pile *positionCaractere(char *expression, int nombreCaracteres, int *erreurPoint, int *erreur)
{

    pile *pile_valeur_erreur_a_cote = init_pile();
    char caractereSpeciaux[] = {'/', '+', '-', '*', '='};
    // int i = 1, j = 0;

    for (int i = 1; i < nombreCaracteres; i++)
    {
        if (expression[i] == '.')
        {
            // on verifie que le caractere avant le point est un chiffre
            if (expression[i - 1] == '0' || expression[i - 1] == '1' || expression[i - 1] == '2' || expression[i - 1] == '3' || expression[i - 1] == '4' ||
                expression[i - 1] == '5' || expression[i - 1] == '6' || expression[i - 1] == '7' || expression[i - 1] == '8' || expression[i - 1] == '9')
            {
                // on verifie que le caractere apres le point est un chiffre
                if (expression[i + 1] == '0' || expression[i + 1] == '1' || expression[i + 1] == '2' || expression[i + 1] == '3' || expression[i + 1] == '4' ||
                    expression[i + 1] == '5' || expression[i + 1] == '6' || expression[i + 1] == '7' || expression[i + 1] == '8' || expression[i + 1] == '9')
                {
                    *erreurPoint = 0;
                    i += 1;
                }
                // si le caractere apres le point n'est pas un chiffre, on a une erreur
                else
                {
                    *erreurPoint = 1;
                    i++;
                }
            }
        }
        else
        {
            for (int j = 0; j < strlen(caractereSpeciaux); j++)
            {
                if (expression[i] == caractereSpeciaux[j])
                {
                    // on verifie que le caractere precedent est un chiffre ou une parentheses fermante
                    if (expression[i - 1] == '0' || expression[i - 1] == '1' || expression[i - 1] == '2' || expression[i - 1] == '3' || expression[i - 1] == '4' ||
                        expression[i - 1] == '5' || expression[i - 1] == '6' || expression[i - 1] == '7' || expression[i - 1] == '8' || expression[i - 1] == '9' ||
                        expression[i - 1] == ')')
                    {
                        // on verifie que le caractere suivant est un chiffre ou une parentheses ouvrante
                        if (expression[i + 1] == '0' || expression[i + 1] == '1' || expression[i + 1] == '2' || expression[i + 1] == '3' || expression[i + 1] == '4' ||
                            expression[i + 1] == '5' || expression[i + 1] == '6' || expression[i + 1] == '7' || expression[i + 1] == '8' || expression[i + 1] == '9' ||
                            expression[i - 1] == '(')
                        {
                            *erreur = 0;
                            i += 1;
                        }
                        // si le caractere precedent n'est pas un chiffre ou une parenthese fermante, on a une erreur
                        else
                        {
                            empiler(pile_valeur_erreur_a_cote, expression[i + 1]);
                            i += 1;
                        }
                    }
                }
            }
        }
    }
    return pile_valeur_erreur_a_cote;
}
