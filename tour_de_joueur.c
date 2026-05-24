#include "Projet.h"

// Gère un tour de joueur (piocher, vérifier s'il y a un doublon, score, fin)
void tour_joueur(Carte paquet[], Joueur joueurs[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu, int i, int stats_numero[], int stats_bonus[], int nb_joueurs) {

    // Si le joueur n'est plus actif, on quitte immédiatement la fonction
    if (*actif == 0) {
        return;
    }

    // Vérifie qu'il reste des cartes dans la pioche
    if (*taille_pioche <= 0) {

        printf("Plus de cartes !\n");
        *actif = 0;
        return;
    }

    // Pioche d'une nouvelle carte
    Carte c = carte_piochee(paquet, taille_pioche);

    if (c.bonus == 0) {

    // Carte normale
    stats_numero[c.numero]++;
    }
    else {
        if (c.bonus == -2) {
            stats_bonus[5]++;
        }
        else {
            stats_bonus[(c.bonus / 2) - 1]++;
        }
    }

    // Vérification des doublons : si une carte normale existe déjà dans la main alors le joueur perd immédiatement
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

    // Ajoute la carte dans la main du joueur
    main[*taille] = c;

    // Incrémente le nombre de cartes
    (*taille)++;

    // Recalcule le score complet après le tirage
    *score = calcul_score(main, *taille);

    afficher_joueur(c, *score, joueurs, main, *taille, i);
    if (nb_joueurs >= 11){
        afficher_stats(stats_numero, stats_bonus);
        printf("\n\n\n");
    }

    // Si le joueur atteint 7 cartes sans perdre,
    // il gagne la manche et obtient un bonus
    if (*taille == 7) {

        printf(
            "%s a gagné la manche ! Il obtient 15 points supplémentaires !\n",
            joueurs[i].nom
        );

        *actif = 0;
        joueurs[i].score += 15;

        return;
    }

    // Demande au joueur s'il souhaite continuer
    if (choix_joueur() == 0) {
        *actif = 0;
    }
}
