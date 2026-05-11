#include 'Projet.h'

int demander_choix() {
    int choix;

    printf("Continuer ? (1 = oui, 0 = non) : ");
    scanf("%d", &choix);

    return choix;
}