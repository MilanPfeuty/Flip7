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
    for (int j = 0; j < taille; j++) {
        if (cartes[j].bonus == 0) {
            printf("%d ", cartes[j].numero);
        }
        else if (cartes[j].bonus == -2) {
            printf("x2 ");
        }
        else {
            printf("+%d ", cartes[j].bonus);
        }
    }
    printf("\nScore de la manche : %d\n", score);
    printf("\nScore général : %d\n", joueurs[i].score+score);
    printf("\n");
}