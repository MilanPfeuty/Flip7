#include "Projet.h"


int debut(Joueur joueurs[], int *nb_joueurs) {
    for (int i = 0; i < *nb_joueurs; i++) {
        printf("Nom du joueur %d : ", i + 1);
        scanf("%s", joueurs[i].nom);

        joueurs[i].score = 0;
        joueurs[i].actif = 1;
        joueurs[i].nb_carte = 0;
    }
    return 1;
}