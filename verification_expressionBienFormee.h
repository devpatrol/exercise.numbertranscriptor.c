
#include "variables.h"

int expressionBienFormee()
{
    printf("Saisissez votre expression:\t");
    scanf("%s", expression);
    nombreCaracteres = strlen(expression);

    /*tant que l'expression saisie ne respecte pas les criteres donnes, le programme redemande de saisir une bonne expression*/
    while (!expressionValide(expression, nombreCaracteres))
    {
        printf("\n\t\tVous devez saisir une expression valide constituee uniquement de chiffres et/ou des caracteres : {'/', '+', '-', '*', '(', ')', '=', '.'}");
        system("clear");
        printf("\n\n\t\tSaisissez votre expression:\t");
        scanf("%s", expression);
    }

    /*Arrivee ici, on est sur que l'expression saisie n'est constituee que de chiffres et des caracteres {'/', '+', '-', '*', '(', ')', '=', '.'}*/

    /*cette condition verifie et s'execute si l'expression ne comporte que des chiffres*/
    if (expressionSimple(expression, nombreCaracteres))
    {
        return 1;
    }

    /*Dans le cas ou l'expression renferme les caracteres {'/', '+', '-', '*', '(', ')', '=', '.'}, on entre dans la condition else*/
    else
    {
        /*appel et/ou recuperation des contenus des fonctions*/
        modul = modulo(expression, nombreCaracteres);
        parentheses(expression, nombreCaracteres, &erreurParentheseOuvrante, &erreurParentheseFermante);
        verifiacationCaractereDebut_Fin(expression, nombreCaracteres, &caractereDebut, &caractereFin, &erreurDebut, &erreurFin);
        excesEgalite = excedantEgalite(expression, nombreCaracteres);
        pile_valeur_erreur_a_cote = positionCaractere(expression, nombreCaracteres, &erreurPoint, &erreur);
        caractere *maPile = pile_valeur_erreur_a_cote->premier;

        /*********************************************CAS OU IL N'Y A PAS D'ERREUR SUR LES PARENTHESES*******************************************/
        if (!erreurParentheseOuvrante && !erreurParentheseFermante)
        {
            if (!modul)
            {
                if (!excesEgalite)
                {
                    if (maPile->caractere == '0')
                    {
                        if (!erreurDebut)
                        {
                            if (!erreurFin)
                            {
                                if (!erreurPoint) // erreurPoint=0, modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=0 et erreurFin=0
                                {
                                    return 1;
                                }
                                else // erreurPoint=1, modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=0 et erreurFin=0
                                {
                                    printf("\nMal forme: %c\n", '.');
                                    return 0;
                                }
                            }
                            else if (!erreurPoint) // erreurPoint=0, modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=0 et erreurFin=1
                            {
                                printf("\nMal forme: %c\n", caractereFin);
                                return 0;
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=0, erreurFin=1 et erreurPoint=1
                            {
                                printf("\nMal forme: %c %c\n", '.', caractereFin);
                                return 0;
                            }
                        }
                        else if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=0
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=0 et erreurPoint=0
                            {
                                printf("\nMal forme: %c\n", caractereDebut);
                                return 0;
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=0 et erreurPoint=1
                            {
                                printf("\nMal forme: %c %c\n", '.', caractereDebut);
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=1 et erreurPoint=0
                        {
                            printf("\nMal forme: %c %C\n", caractereDebut, caractereFin);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=1 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c %c\n", '.', caractereDebut, caractereFin);
                            return 0;
                        }
                    }
                    else if (!erreurDebut) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=0
                    {
                        if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=0, erreurFin=0
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=0, erreurFin=0 et erreurPoint=0
                            {
                                printf("\nMal forme:");
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else // modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=0, erreurFin=0 et erreurPoint=1
                            {
                                printf("\nMal forme: %c", '.');
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=0, erreurFin=1 et erreurPoint=0
                        {
                            printf("\nMal forme: %c", caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=0, erreurFin=1 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c", '.', caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=1, erreurFin=0
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=1, erreurFin=0 et erreurPoint=0
                        {
                            printf("\nMal forme: %c", caractereDebut);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=1, erreurFin=0 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c", '.', caractereDebut);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=1, erreurFin=1 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c", caractereDebut, caractereFin);
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=0, excesEgalite=0, maPile->caractere != '0',erreurDebut=1, erreurFin=1 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c", '.', caractereDebut, caractereFin);
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (maPile->caractere == '0') //  modul=0, excesEgalite=1, maPile->caractere == '0'
                {
                    if (!erreurDebut) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=0
                    {
                        if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=0, erreurFin=0
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=0, erreurFin=0 et erreurPoint=0
                            {
                                printf("\nMal forme: %c\n", '=');
                                return 0;
                            }
                            else //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=0, erreurFin=0 et erreurPoint=1
                            {
                                printf("\nMal forme: %c %c\n", '.', '=');
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=0, erreurFin=1 et erreurPoint=0
                        {
                            printf("\nMal forme: %c %c\n", caractereFin, '=');
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=0, erreurFin=1 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c %c\n", '.', caractereFin, '=');
                            return 0;
                        }
                    }
                    else if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=1, erreurFin=0
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=1, erreurFin=0 et erreurPoint=0
                        {
                            printf("\nMal forme: %c %c\n", caractereDebut, '=');
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=1, erreurFin=0 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c %c\n", '.', caractereDebut, '=');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=1, erreurFin=1 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c %c\n", caractereDebut, caractereFin, '=');
                        return 0;
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere == '0',erreurDebut=1, erreurFin=1 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, caractereFin, '=');
                        return 0;
                    }
                }
                else if (!erreurDebut) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=0
                {
                    if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=0, erreurFin=0
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=0, erreurFin=0 et erreurPoint=0
                        {
                            printf("\nMal forme: %c", '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=0, erreurFin=0 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c", '.', '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=0, erreurFin=1 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c", caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=0, erreurFin=1 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c", '.', caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=1, erreurFin=0
                {
                    if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=1, erreurFin=0 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c", caractereDebut, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=1, erreurFin=0 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c", '.', caractereDebut, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=1, erreurFin=1 et erreurPoint=0
                {
                    printf("\nMal forme: %c %c %c", caractereDebut, caractereFin, '=');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else //  modul=0, excesEgalite=1, maPile->caractere != '0',erreurDebut=1, erreurFin=1 et erreurPoint=1
                {
                    printf("\nMal forme: %c %c %c %c", '.', caractereDebut, caractereFin, '=');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else if (!excesEgalite) //  modul=1, excesEgalite=0
            {
                if (maPile->caractere == '0') //  modul=1, excesEgalite=0, maPile->caractere == '0'
                {
                    if (!erreurDebut) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=0
                    {
                        if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=0, erreurFin=0
                        {
                            if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=0, erreurFin=0 et erreurPoint=0
                            {
                                printf("\nMal forme: %c\n", '%');
                                return 0;
                            }
                            else //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=0, erreurFin=0 et erreurPoint=1
                            {
                                printf("\nMal forme: %c %c\n", '.', '%');
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=0, erreurFin=1 et erreurPoint=0
                        {
                            printf("\nMal forme: %c %c\n", caractereFin, '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=0, erreurFin=1 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c %c\n", '.', caractereFin, '%');
                            return 0;
                        }
                    }
                    else if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=0
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=0 et erreurPoint=0
                        {
                            printf("\nMal forme: %c %c\n", caractereDebut, '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=0 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c %c\n", '.', caractereDebut, '%');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=1 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c %c\n", caractereDebut, caractereFin, '%');
                        return 0;
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere == '0',erreurDebut=1, erreurFin=1 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, caractereFin, '%');
                        return 0;
                    }
                }
                else if (!erreurDebut) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0
                {
                    if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et erreurPoint=0
                        {
                            printf("\nMal forme: %c", '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c", '.', '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c", caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c", '.', caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c", caractereDebut, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c", '.', caractereDebut, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1 et erreurPoint=0
                {
                    printf("\nMal forme: %c %c %c", caractereDebut, caractereFin, '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1 et erreurPoint=1
                {
                    printf("\nMal forme: %c %c %c %c", '.', caractereDebut, caractereFin, '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else if (maPile->caractere == '0') //  modul=1, excesEgalite=1, maPile->caractere == '0'
            {
                if (!erreurDebut) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0
                {
                    if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et erreurPoint=0
                        {
                            printf("\nMal forme: %c %c\n", '=', '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et erreurPoint=1
                        {
                            printf("\nMal forme: %c %c %c\n", '.', '=', '%');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c %c\n", caractereFin, '=', '%');
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c %c\n", '.', caractereFin, '=', '%');
                        return 0;
                    }
                }
                else if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c %c\n", caractereDebut, '=', '%');
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, '=', '%');
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1 et erreurPoint=0
                {
                    printf("\nMal forme: %c %c %c %c\n", caractereDebut, caractereFin, '=', '%');
                    return 0;
                }
                else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1 et erreurPoint=1
                {
                    printf("\nMal forme: %c %c %c %c %c\n", '.', caractereDebut, caractereFin, '=', '%');
                    return 0;
                }
            }
            else if (!erreurDebut) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0
            {
                if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et erreurPoint=0
                    {
                        printf("\nMal forme: %c %c", '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et erreurPoint=1
                    {
                        printf("\nMal forme: %c %c %c", '.', '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1 et erreurPoint=0
                {
                    printf("\nMal forme: %c %c %c", caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1 et erreurPoint=1
                {
                    printf("\nMal forme: %c %c %c %c", '.', caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0
            {
                if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et erreurPoint=0
                {
                    printf("\nMal forme: %c %c %c", caractereDebut, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et erreurPoint=1
                {
                    printf("\nMal forme: %c %c %c %c", '.', caractereDebut, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1 et erreurPoint=0
            {
                printf("\nMal forme: %c %c %c %c", caractereDebut, caractereFin, '=', '%');
                afficherPile(pile_valeur_erreur_a_cote);
                return 0;
            }
            else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1 et erreurPoint=1
            {
                printf("\nMal forme: %c %c %c %c %c", '.', caractereDebut, caractereFin, '=', '%');
                afficherPile(pile_valeur_erreur_a_cote);
                return 0;
            }
        }
        /*******************************************************CAS OU L'ERREUR EST SUR LA PARENTHESE OUVRANTE*****************************************************/
        else if (erreurParentheseOuvrante && !erreurParentheseFermante)
        {
            if (!modul) //  modul=0, la parenthese ouvrante est en exces
            {
                if (!excesEgalite) //  modul=0, excesEgalite=0 et la parenthese ouvrante est en exces
                {
                    if (maPile->caractere == '0') //  modul=0, excesEgalite=0, maPile->caractere == '0' et la parenthese ouvrante est en exces
                    {
                        if (!erreurDebut) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0 et la parenthese ouvrante est en exces
                        {
                            if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                            {
                                if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                                {
                                    printf("\nMal forme: %c\n", '(');
                                    return 0;
                                }
                                else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                                {
                                    printf("\nMal forme: %c %c\n", '.', '(');
                                    return 0;
                                }
                            }
                            else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                            {
                                if (caractereFin == '(')
                                {
                                    printf("\nMal forme: %c\n", caractereFin);
                                    return 0;
                                }
                                else
                                {
                                    printf("\nMal forme: %c %c\n", caractereFin, '(');
                                    return 0;
                                }
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                            {
                                if (caractereFin == '(')
                                {
                                    printf("\nMal forme: %c %c\n", '.', caractereFin);
                                    return 0;
                                }
                                else
                                {
                                    printf("\nMal forme: %c %c %c\n", '.', caractereFin, '(');
                                    return 0;
                                }
                            }
                        }
                        else if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: %c\n", caractereDebut);
                                return 0;
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: %c %c\n", '.', caractereDebut);
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c %c\n", caractereFin, caractereDebut);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c %c\n", caractereFin, caractereDebut);
                                return 0;
                            }
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: . %c %c\n", caractereFin, caractereDebut);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( . %c %c\n", caractereFin, caractereDebut);
                                return 0;
                            }
                        }
                    }
                    else if (!erreurDebut) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: (");
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: ( %c", '.');
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c", caractereFin);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c", caractereFin);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c %c", '.', caractereFin);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c %c", '.', caractereFin);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                    }
                    else if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c", caractereDebut);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c", '.', caractereDebut);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: ( %c", caractereDebut);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: %c %c", caractereDebut, caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: . %c %c", caractereFin, caractereDebut);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( . %c %c", caractereDebut, caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                }
                else if (maPile->caractere == '0') //  modul=0, excesEgalite=1, maPile->caractere == '0' et la parenthese ouvrante est en exces
                {
                    if (!erreurDebut)
                    {
                        if (!erreurFin)
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: ( %c\n", '=');
                                return 0;
                            }
                            else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: ( %c %c\n", '.', '=');
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c %c\n", caractereFin, '=');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c %c\n", caractereFin, '=');
                                return 0;
                            }
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c %c %c\n", '.', caractereFin, '=');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c %c %c\n", '.', caractereFin, '=');
                                return 0;
                            }
                        }
                    }
                    else if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c\n", caractereDebut, '=');
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                        {

                            printf("\nMal forme: ( %c %c %c\n", '.', caractereDebut, '=');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: ( %c %c\n", caractereDebut, '=');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c\n", caractereDebut, caractereFin, '=');
                            return 0;
                        }
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: . %c %c %c\n", caractereFin, caractereDebut, '=');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( . %c %c %c\n", caractereDebut, caractereFin, '=');
                            return 0;
                        }
                    }
                }
                else if (!erreurDebut) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c", '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c", '.', '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c", caractereFin, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c", caractereFin, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c %c", '.', caractereFin, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c", '.', caractereFin, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                }
                else if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c", caractereDebut, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c %c", '.', caractereDebut, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c", caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c", caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c %c", '.', caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c %c", '.', caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
            }
            else if (!excesEgalite) //  modul=1, excesEgalite=0 et la parenthese ouvrante est en exces
            {
                if (maPile->caractere == '0') //  modul=1, excesEgalite=0, maPile->caractere == '0' et la parenthese ouvrante est en exces
                {
                    if (!erreurDebut) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                        {
                            if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: ( %c\n", '%');
                                return 0;
                            }
                            else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                            {
                                printf("\nMal forme: ( %c %c\n", '.', '%');
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c %c\n", caractereFin, '%');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c %c\n", caractereFin, '%');
                                return 0;
                            }
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            if (caractereFin == '(')
                            {
                                printf("\nMal forme: %c %c %c\n", '.', caractereFin, '%');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ( %c %c %c\n", '.', caractereFin, '%');
                                return 0;
                            }
                        }
                    }
                    else if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c\n", caractereDebut, '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c %c\n", '.', caractereDebut, '%');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c %c\n", caractereDebut, caractereFin, '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c\n", caractereDebut, caractereFin, '%');
                            return 0;
                        }
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, caractereFin, '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c %c\n", '.', caractereDebut, caractereFin, '%');
                            return 0;
                        }
                    }
                }
                else if (!erreurDebut) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c", '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c", '.', '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c", caractereFin, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c", caractereFin, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c %c", '.', caractereFin, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c", '.', caractereFin, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                }
                else if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c", caractereDebut, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c %c", '.', caractereDebut, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c", caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c", caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c %c", '.', caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c %c", '.', caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
            }
            else if (maPile->caractere == '0') //  modul=1, excesEgalite=1, maPile->caractere == '0' et la parenthese ouvrante est en exces
            {
                if (!erreurDebut) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c\n", '=', '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                        {
                            printf("\nMal forme: ( %c %c %c\n", '.', '=', '%');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c %c\n", caractereFin, '=', '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c\n", caractereFin, '=', '%');
                            return 0;
                        }
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        if (caractereFin == '(')
                        {
                            printf("\nMal forme: %c %c %c %c\n", '.', caractereFin, '=', '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ( %c %c %c %c\n", '.', caractereFin, '=', '%');
                            return 0;
                        }
                    }
                }
                else if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c %c\n", caractereDebut, '=', '%');
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c %c %c\n", '.', caractereDebut, '=', '%');
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c %c\n", caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c %c\n", caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                }
                else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c %c %c\n", '.', caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c %c %c\n", '.', caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                }
            }
            else if (!erreurDebut) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0 et la parenthese ouvrante est en exces
            {
                if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese ouvrante est en exces
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c", '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                    {
                        printf("\nMal forme: ( %c %c %c", '.', '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c", caractereFin, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c", caractereFin, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
                {
                    if (caractereFin == '(')
                    {
                        printf("\nMal forme: %c %c %c %c", '.', caractereFin, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ( %c %c %c %c", '.', caractereFin, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
            }
            else if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese ouvrante est en exces
            {
                if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese ouvrante est en exces
                {
                    printf("\nMal forme: ( %c %c %c", caractereDebut, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese ouvrante est en exces
                {
                    printf("\nMal forme: ( %c %c %c %c", '.', caractereDebut, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese ouvrante est en exces
            {
                if (caractereFin == '(')
                {
                    printf("\nMal forme: %c %c %c %c", caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else
                {
                    printf("\nMal forme: ( %c %c %c %c", caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese ouvrante est en exces
            {
                if (caractereFin == '(')
                {
                    printf("\nMal forme: %c %c %c %c %c", '.', caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else
                {
                    printf("\nMal forme: ( %c %c %c %c %c", '.', caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            /**************************************************************CAS OU IL Y'A ERREUR SUR LA PARENTHESE FERMANTE UNIQUEMENT*************************************************/
        }
        else if (erreurParentheseFermante && !erreurParentheseOuvrante)
        {

            if (!modul) //  modul=0 et la parenthese fermante est en exces ou mal placé
            {
                if (!excesEgalite) //  modul=0, excesEgalite=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (maPile->caractere == '0') //  modul=0, excesEgalite=0, maPile->caractere == '0' et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurDebut) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                            {
                                if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                                {
                                    printf("\nMal forme: %c\n", ')');
                                    return 0;
                                }
                                else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                                {
                                    printf("\nMal forme: ) %c\n", '.');
                                    return 0;
                                }
                            }
                            else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c\n", caractereFin);
                                return 0;
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c %c\n", '.', caractereFin);
                                return 0;
                            }
                        }
                        else if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                            {
                                if (caractereDebut == ')')
                                {
                                    printf("\nMal forme: %c\n", caractereDebut);
                                    return 0;
                                }
                                else
                                {
                                    printf("\nMal forme: ) %c\n", caractereDebut);
                                    return 0;
                                }
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                            {
                                if (caractereDebut == ')')
                                {
                                    printf("\nMal forme: %c %c\n", '.', caractereDebut);
                                    return 0;
                                }
                                else
                                {
                                    printf("\nMal forme: ) %c %c\n", '.', caractereDebut);
                                    return 0;
                                }
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %C\n", caractereDebut, caractereFin);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %C\n", caractereDebut, caractereFin);
                                return 0;
                            }
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %c %c\n", '.', caractereDebut, caractereFin);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %c %c\n", '.', caractereDebut, caractereFin);
                                return 0;
                            }
                        }
                    }
                    else if (!erreurDebut) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: )");
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c", '.');
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c", caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c", '.', caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurFin) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c", caractereDebut);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c", caractereDebut);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                        else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %c", '.', caractereDebut);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %c", '.', caractereDebut);
                                afficherPile(pile_valeur_erreur_a_cote);
                                return 0;
                            }
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c", caractereDebut, caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c", caractereDebut, caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else //  modul=0, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c", '.', caractereDebut, caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c", '.', caractereDebut, caractereFin);
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                }
                else if (maPile->caractere == '0') //  modul=0, excesEgalite=1, maPile->caractere == '0' et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurDebut) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c\n", '=');
                                return 0;
                            }
                            else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c %c\n", '.', '=');
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c\n", caractereFin, '=');
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c %c\n", '.', caractereFin, '=');
                            return 0;
                        }
                    }
                    else if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %c\n", caractereDebut, '=');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %c\n", caractereDebut, '=');
                                return 0;
                            }
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %c %c\n", '.', caractereDebut, '=');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %c %c\n", '.', caractereDebut, '=');
                                return 0;
                            }
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c\n", caractereDebut, caractereFin, '=');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c\n", caractereDebut, caractereFin, '=');
                            return 0;
                        }
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, caractereFin, '=');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c %c\n", '.', caractereDebut, caractereFin, '=');
                            return 0;
                        }
                    }
                }
                else if (!erreurDebut) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c", '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c", '.', '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c", caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c %c", '.', caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurFin) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c", caractereDebut, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c", caractereDebut, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c", '.', caractereDebut, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c", '.', caractereDebut, '=');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                }
                else if (!erreurPoint) //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c", caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c", caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else //  modul=0, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c %c", '.', caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c %c", '.', caractereDebut, caractereFin, '=');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
            }
            else if (!excesEgalite) //  modul=1, excesEgalite=0 et la parenthese fermante est en exces ou mal placé
            {
                if (maPile->caractere == '0') //  modul=1, excesEgalite=0, maPile->caractere == '0' et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurDebut) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c\n", '%');
                                return 0;
                            }
                            else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                            {
                                printf("\nMal forme: ) %c %c\n", '.', '%');
                                return 0;
                            }
                        }
                        else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c\n", caractereFin, '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c %c\n", '.', caractereFin, '%');
                            return 0;
                        }
                    }
                    else if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %c\n", caractereDebut, '%');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %c\n", caractereDebut, '%');
                                return 0;
                            }
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            if (caractereDebut == ')')
                            {
                                printf("\nMal forme: %c %c %c\n", '.', caractereDebut, '%');
                                return 0;
                            }
                            else
                            {
                                printf("\nMal forme: ) %c %c %c\n", '.', caractereDebut, '%');
                                return 0;
                            }
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c\n", caractereDebut, caractereFin, '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c\n", caractereDebut, caractereFin, '%');
                            return 0;
                        }
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, caractereFin, '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c %c\n", '.', caractereDebut, caractereFin, '%');
                            return 0;
                        }
                    }
                }
                else if (!erreurDebut) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c", '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c", '.', '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c", caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c %c", '.', caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurFin) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c", caractereDebut, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c", caractereDebut, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                    else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c", '.', caractereDebut, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c", '.', caractereDebut, '%');
                            afficherPile(pile_valeur_erreur_a_cote);
                            return 0;
                        }
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c", caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c", caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else //  modul=1, excesEgalite=0, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c %c", '.', caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c %c", '.', caractereDebut, caractereFin, '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
            }
            else if (maPile->caractere == '0') //  modul=1, excesEgalite=1, maPile->caractere == '0' et la parenthese fermante est en exces ou mal placé
            {
                if (!erreurDebut) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c\n", '=', '%');
                            return 0;
                        }
                        else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                        {
                            printf("\nMal forme: ) %c %c %c\n", '.', '=', '%');
                            return 0;
                        }
                    }
                    else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c %c\n", caractereFin, '=', '%');
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c %c %c\n", '.', caractereFin, '=', '%');
                        return 0;
                    }
                }
                else if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c\n", caractereDebut, '=', '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c\n", caractereDebut, '=', '%');
                            return 0;
                        }
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        if (caractereDebut == ')')
                        {
                            printf("\nMal forme: %c %c %c %c\n", '.', caractereDebut, '=', '%');
                            return 0;
                        }
                        else
                        {
                            printf("\nMal forme: ) %c %c %c %c\n", '.', caractereDebut, '=', '%');
                            return 0;
                        }
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c %c\n", caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c %c\n", caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                }
                else //  modul=1, excesEgalite=1, maPile->caractere == '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c %c %c\n", '.', caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c %c %c\n", '.', caractereDebut, caractereFin, '=', '%');
                        return 0;
                    }
                }
            }
            else if (!erreurDebut) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0 et la parenthese fermante est en exces ou mal placé
            {
                if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c", '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                    {
                        printf("\nMal forme: ) %c %c %c", '.', '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                {
                    printf("\nMal forme: ) %c %c %c", caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=0, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                {
                    printf("\nMal forme: ) %c %c %c %c", '.', caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else if (!erreurFin) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0 et la parenthese fermante est en exces ou mal placé
            {
                if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c", caractereDebut, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c", caractereDebut, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
                else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=0, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
                {
                    if (caractereDebut == ')')
                    {
                        printf("\nMal forme: %c %c %c %c", '.', caractereDebut, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                    else
                    {
                        printf("\nMal forme: ) %c %c %c %c", '.', caractereDebut, '=', '%');
                        afficherPile(pile_valeur_erreur_a_cote);
                        return 0;
                    }
                }
            }
            else if (!erreurPoint) //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=0 et la parenthese fermante est en exces ou mal placé
            {
                if (caractereDebut == ')')
                {
                    printf("\nMal forme: %c %c %c %c", caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else
                {
                    printf("\nMal forme: ) %c %c %c %c", caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
            else //  modul=1, excesEgalite=1, maPile->caractere != '0', erreurDebut=1, erreurFin=1, erreurPoint=1 et la parenthese fermante est en exces ou mal placé
            {
                if (caractereDebut == ')')
                {
                    printf("\nMal forme: %c %c %c %c %c", '.', caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
                else
                {
                    printf("\nMal forme: ) %c %c %c %c %c", '.', caractereDebut, caractereFin, '=', '%');
                    afficherPile(pile_valeur_erreur_a_cote);
                    return 0;
                }
            }
        }
    }
}

/*

modul=0                        -----> il n'y a pas de modulo dans l'expression

excesEgalite=0                 -----> le nombre de symbole '=' est inferieur ou egal a 1

 maPile->caractere == '0'      -----> la pile contenant les caracteres {'-', '=', '+', '/', '*'} est vide. C-a-d que chacun de
                                      ces caracteres (s'il est present dans l'expression) est entre deux chiffres

erreurDebut=0                  -----> le caractere de debut est soit un chiffre soit '('

 erreurFin=0                   -----> le caractere de fin est soit un chiffre soit ')'

 erreurPoint=0                 -----> le point est placé entre deux chiffres

*/

/*

modul=1                        -----> il y'a un ou plusieurs modulo dans l'expression

excesEgalite=1                 -----> le nombre de symbole '=' est superieur a 1

 maPile->caractere != '0'      -----> la pile contient un ou plusieurs des caracteres {'-', '=', '+', '/', '*', '.', '(', ')'}. C-a-d qu'un de
                                      ces caracteres (s'il est present dans l'expression) est pres d'un autre

erreurDebut=1                  -----> le caractere de debut est un de caracteres {'-', '=', '+', '/', '*', '.', ')'}

 erreurFin=1                   -----> le caractere de fin est un de caracteres {'-', '=', '+', '/', '*', '.', '('}

 erreurPoint=1                 -----> le point est placé pres d'un des caractere {'-', '=', '+', '/', '*', '.', '(', ')'}
*/