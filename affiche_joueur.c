#include "Projet.h"

// Affiche les infos du joueur (carte tirée, main, score)
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

    // Parcourt toutes les cartes déjà piochées par le joueur afin d'afficher sa main complète
    for (int j = 0; j < taille; j++) {

        // bonus == 0 : carte classique
        if (cartes[j].bonus == 0) {
            printf("%d ", cartes[j].numero);
        }

        // bonus == -2 : carte multiplicateur x2
        else if (cartes[j].bonus == -2) {
            printf("x2 ");
        }

        // sinon : carte bonus (+2, +4, etc.)
        else {
            printf("+%d ", cartes[j].bonus);
        }
    }

    printf("\nScore de la manche : %d\n", score);

    // Affiche le score total du joueur : score général déjà acquis + score actuel de la manche
    printf("\nScore général : %d\n", joueurs[i].score + score);
    printf("\n");
}