#include "prototypeFonctions.h"

char expression[100],
    caractereDebut,
    caractereFin;

int nombreCaracteres,
    erreurDebut = 0,
    erreurFin = 0,
    erreurParentheseOuvrante,
    erreurParentheseFermante = 0,
    erreurPoint,
    erreur,
    excesEgalite,
    modul = 0,
    parenthese1 = 0,
    parenthese2 = 0,
    debut_fin = 0,
    debut = 0,
    fin = 0;

pile *pile_valeur_erreur_a_cote;