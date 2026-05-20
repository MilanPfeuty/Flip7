#include "Projet.h"

void afficher_joueur(Carte c, int score, Joueur joueurs[], Carte cartes[], int taille , int i) {
    
    printf("\n--- JOUEUR %s ---\n", joueurs[i].nom);

    if (c.bonus == 0) {
        printf("\nCarte piochée : %d\n", c.numero);
    }
    else if (c.bonus == -2) {
        printf("\nCarte piochée : x2\n");
    }
    else {
        printf("\nCarte piochée : +%d\n", c.bonus);
    }

    printf("Main de %s : ", joueurs[i].nom);
    for (int i = 0; i < taille; i++) {
        if (cartes[i].bonus == 0) {
            printf("%d ", cartes[i].numero);
        }
        else if (cartes[i].bonus == -2) {
            printf("x2 ");
        }
        else {
            printf("+%d ", cartes[i].bonus);
        }
    }
    printf("\nScore : %d\n", score);
}