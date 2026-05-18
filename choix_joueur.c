#include "Projet.h"

int choix_joueur() {
    int choix;
    printf("Continuer ? (1 = oui, 0 = non) : ");
    scanf("%d", &choix);
    vide_buffer();
    return choix;
}
