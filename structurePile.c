#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure qui cree un element de la pile
typedef struct caractere caractere;
struct caractere
{
    char caractere;
    caractere *suivant;
};

// structure qui manipule la pile
typedef struct pile pile;
struct pile
{
    caractere *premier;
};
