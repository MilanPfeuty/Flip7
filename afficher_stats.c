#include "Projet.h"

void afficher_stats(int stats_numero[], int stats_bonus[]) {

    printf("\n=== STATISTIQUES DES CARTES ===\n");

    for (int i = 0; i < 13; i++) {

        printf("Carte %d : %d piochée(s)\n",
               i,
               stats_numero[i]);
    }

    printf("+2 : %d\n", stats_bonus[0]);
    printf("+4 : %d\n", stats_bonus[1]);
    printf("+6 : %d\n", stats_bonus[2]);
    printf("+8 : %d\n", stats_bonus[3]);
    printf("+10 : %d\n", stats_bonus[4]);
    printf("x2 : %d\n", stats_bonus[5]);
}