#ifndef H_LANG
#define H_LANG

/**
    * @brief 
    * lang.h will content all 
    * required text data for 
    * the program
*/

char __NUMBERS[] = {
    '0', '1', '2', '3', '4', '5', '6', 
    '7', '8', '9', '\0'
};

char __SPECIAL_CARACTERES[] = {
    ' ', '.', '+', '*', '/', '-', '{', '}', 
    '(', ')', '=', '\0'
};

char __NUMBERS_CARACTERES[] = {
    ' ', '.', '+', '*', '/', '-', '{', '}', 
    '(', ')', '=', '0', '1', '2', '3', '4', '5', '6', 
    '7', '8', '9', '\0'
};

char __UNITY[][7] = {
    "zero", "un", "deux", "trois", "quatre",
    "cinq", "six", "sept", "huit", "neuf"
};

char __TWENTIES[][15] = {
    "onze", "douze", "treize", "quatorze", "quinze",
    "seize", "dix-sept", "dix-huit", "dix-neuf"
};

char __TENS[][20] = {
    "dix", "vingt", "trente", "quarante", "cinquante",
    "soixante", "soixante-dix", "quatre-vingt", "quatre-vingt-dix" 
};

char __HUNDREDS[][10] = {
    "cent", "mille", "million", "milliard"
};

char __SPECIALS[][20] = {
    "et", "virgule", "moins", "plus", "divisé par", 
    "multiplié par", "facteur de", "egal à"
};

#endif