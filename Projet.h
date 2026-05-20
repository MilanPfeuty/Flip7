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
void affiche_pioche(Carte* paquet);
void afficher_main(Joueur j);

void calcul_score(Joueur *j);
Carte carte_piochee(Carte paquet[], int *taille);

int choix_joueur();

void creer_pioche(Carte paquet[]);

void deroulement_partie(Carte paquet[], Joueur joueurs[], int nb_joueurs);

int start(Joueur joueurs[], int *nb_joueurs);

void tour_joueur(Carte paquet[], Joueur joueurs[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu, int i);


int main_joueurs();

#endif