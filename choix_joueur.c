#include "Projet.h"

int choix_joueur() {
    int choix;

    do {
        printf("Continuer ? (1 = oui, 0 = non) : ");
        scanf("%d", &choix);
        vide_buffer();

        if (choix != 1 && choix != 0) {
            printf("Veuillez entrer une des 2 valeurs proposées !!\n");
        }

        for (int p=0; p<3; p++){
            printf("\n");
        }

    } while (choix != 1 && choix != 0);

    return choix;
}