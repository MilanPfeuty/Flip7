#include "Projet.h"

void afficher_joueur(int score, Carte cartes[], int taille) {
    printf("\n--- JOUEUR ---\n");

    printf("Main : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", cartes[i].numero);
    }

    printf("\nScore : %d\n", score);
}
