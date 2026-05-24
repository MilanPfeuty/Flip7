#include "Projet.h"

// Demande au joueur s'il veut continuer
int choix_joueur() {

    int choix;
    int verif;

    do {

        printf("Continuer ? (1 = oui, 0 = non) : ");

        // scanf retourne le nombre de valeurs correctement lues
        verif = scanf("%d", &choix);

        vide_buffer();

        if (verif != 1) {
            printf("Erreur : entre un nombre !\n");
        }
        else if (choix != 0 && choix != 1) {
            printf("Veuillez entrer 1 ou 0\n");
        }

        printf("\n\n\n");

    } while (verif != 1 || (choix != 0 && choix != 1));

    return choix;
}