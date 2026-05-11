#include 'Projet.h'

void afficher_joueur(int score, int cartes[], int taille) {
    printf("\n--- JOUEUR ---\n");

    printf("Main : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", cartes[i]);
    }

    printf("\nScore : %d\n", score);
}