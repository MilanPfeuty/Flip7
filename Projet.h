#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct{
    char nom[100];
    int score;
    Carte main[7];
    int nb_carte;
    int actif;
}Joueur;


typedef struct{
    int numero;
} Carte;

void creer_pioche(Carte paquet[]);
Carte carte_pioche(Carte paquet[], int *index);
void afficher_joueur(int score, Carte cartes[], int taille);
int demander_choix();
