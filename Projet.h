#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


typedef struct{
    char nom[100];
    int score;
    Carte main[7];
    int nb_carte;
}Joueur;


typedef struct{
    int numero;
} Carte;