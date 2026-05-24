#include "Projet.h"

void afficher_stats(int stats_numero[], int stats_bonus[]) {

    printf("\n=== CARTES DEJA PIOCHEES ===\n");

    // Affiche uniquement les cartes normales déjà été picohés
    for (int i = 0; i < 13; i++) {

        if (stats_numero[i] > 0) {

            printf("Carte %d : %d piochée(s)\n", i, stats_numero[i]);
        }
    }

    // Affiche les bonus seulement s'ils sont déjà été piochés
    if (stats_bonus[0] > 0) {
        printf("+2 : %d\n", stats_bonus[0]);
    }

    if (stats_bonus[1] > 0) {
        printf("+4 : %d\n", stats_bonus[1]);
    }

    if (stats_bonus[2] > 0) {
        printf("+6 : %d\n", stats_bonus[2]);
    }

    if (stats_bonus[3] > 0) {
        printf("+8 : %d\n", stats_bonus[3]);
    }

    if (stats_bonus[4] > 0) {
        printf("+10 : %d\n", stats_bonus[4]);
    }

    if (stats_bonus[5] > 0) {
        printf("x2 : %d\n", stats_bonus[5]);
    }
}
