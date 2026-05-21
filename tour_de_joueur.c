#include "Projet.h"

void tour_joueur(Carte paquet[], Joueur joueurs[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu, int i) {

    if (*actif == 0) {
        return;
    }

    if (*taille_pioche <= 0) {
        printf("Plus de cartes !\n");
        *actif = 0;
        return;
    }

    Carte c = carte_piochee(paquet, taille_pioche);

    // Doublon
    for (int j = 0; j < *taille; j++) {
        if (c.bonus == 0 && main[j].numero == c.numero) {
            if (c.bonus == 0) {
                printf("\nCarte piochée : %d\n", c.numero);
            }
            else if (c.bonus == -2) {
                printf("\nCarte piochée : x2\n");
            }
            else {
                printf("\nCarte piochée : +%d\n", c.bonus);
            }
            printf("Doublon ! Perdu !\n");
            *actif = 0;
            *perdu = 1;
            return;
        }
    }

    

    // Ajout carte
    main[*taille] = c;
    (*taille)++;

    if (c.bonus == 0) {
        *score += c.numero;
    }
    else if (c.bonus == -2) {
        *score *= 2;
    }
    else {
        *score += c.bonus;
    }

    afficher_joueur(c, *score, joueurs, main, *taille, i);

    if (*taille == 7) {
        printf("%s a gagné la manche ! Il obtient 15 points supplémentaires !\n", joueurs[i].nom);
        *actif = 0;
        joueurs[i].score += 15;
        return;
    }

    if (choix_joueur() == 0) {
        *actif = 0;
    }
}

