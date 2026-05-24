#include "Projet.h"


// Initialise les joueurs (nom + valeurs de départ)
int debut(Joueur joueurs[], int *nb_joueurs) {

    for (int i = 0; i < *nb_joueurs; i++) {

        printf("Nom du joueur %d : ", i + 1);

        scanf("%s", joueurs[i].nom);

        // Initialisation des valeurs par défaut
        joueurs[i].score = 0;
        joueurs[i].actif = 1;
        joueurs[i].nb_carte = 0;
    }

    return 1;
}