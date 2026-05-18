#include "Projet.h"

void tour_joueur(Carte paquet[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu) {

    if (*actif == 0) return;

    if (*taille_pioche <= 0) {
        printf("Plus de cartes !\n");
        *actif = 0;
        return;
    }

    Carte c = carte_piochee(paquet, taille_pioche);
    printf("\nCarte piochée : %d\n", c.numero);

    // Doublon
    for (int i = 0; i < *taille; i++) {
        if (main[i].numero == c.numero) {
            printf("Doublon ! Perdu !\n");
            *actif = 0;
            *perdu = 1;
            return;
        }
    }

    // Ajout carte
    main[*taille] = c;
    (*taille)++;

    *score += c.numero;

    afficher_joueur(*score, main, *taille);

    if (*taille == 7) {
        printf("Victoire !\n");
        *actif = 0;
        return;
    }

    if (choix_joueur() == 0) {
        *actif = 0;
    }
}