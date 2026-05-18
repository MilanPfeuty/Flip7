#ifndef PROJET_H
#define PROJET_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


typedef struct{
    int numero;
} Carte;


typedef struct{
    char nom[100];
    int score;
    Carte main[7];
    int nb_carte;
    int actif;
}Joueur;


void vide_buffer();
int start(Joueur joueurs[], int *nb_joueurs);
void afficher_joueur(int score, Carte cartes[], int taille);
void affiche_pioche(Carte* paquet);
void afficher_main(Joueur j);
void calcul_score(Joueur *j);
Carte carte_piochee(Carte paquet[], int *index);
void creer_pioche(Carte paquet[]);
int choix_joueur();
void init_joueur(Joueur *j, char nom[]);
int manche_perdue(Joueur j, Carte c);
void restitution_nb_cartes(Joueur* j);
void restitution_score(Joueur* j);
void tour_joueur(Carte paquet[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu);

int main_joueurs();

#endif