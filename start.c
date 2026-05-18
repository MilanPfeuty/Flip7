#include "Projet.h"


int start(Joueur joueurs[], int *nb_joueurs) {

    int verif = 0;

    do {
        printf("Combien de joueurs ? : ");
        verif = scanf("%d", nb_joueurs);
        vide_buffer();

        if (verif != 1) {
            printf("Erreur, entrer un entier\n");
        }
    } while (verif != 1);

    for (int i = 0; i < *nb_joueurs; i++) {
        printf("Nom du joueur %d : ", i + 1);
        scanf("%s", joueurs[i].nom);

        joueurs[i].score = 0;
        joueurs[i].actif = 1;
        joueurs[i].nb_carte = 0;
    }

    return 1;
}
