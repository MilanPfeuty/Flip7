#ifndef PROJET_H
#define PROJET_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



typedef struct{
    int numero;
    int bonus;
} Carte;


typedef struct{
    char nom[100];
    int score;
    Carte main[7];
    int nb_carte;
    int actif;
}Joueur;


// Prototypes
void vide_buffer();

void afficher_joueur(Carte c, int score, Joueur joueurs[], Carte cartes[], int taille , int i);
void afficher_stats(int stats_numero[], int stats_bonus[]);

int calcul_score(Carte main[], int taille);
Carte carte_piochee(Carte paquet[], int *taille);

int choix_joueur();

void creer_pioche(Carte paquet[]);

void deroulement_partie(Carte paquet[], Joueur joueurs[], int nb_joueurs);

void sauvegarder_scores(Joueur joueurs[], int nb_joueurs);

int debut(Joueur joueurs[], int *nb_joueurs);

void tour_joueur(Carte paquet[], Joueur joueurs[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu, int i, int stats_numero[], int stats_bonus[]);


int main();

#endif