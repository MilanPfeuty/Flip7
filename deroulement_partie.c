#include "Projet.h"

// Gère toute la logique d'une partie complète (manches, tours, fin)
void deroulement_partie(Carte paquet[], Joueur joueurs[], int nb_joueurs){

    int continuer_partie = 1;
    int manche_n = 1;

    // Réinitialisation complète de la pioche au début de chaque partie
    int taille_pioche = 85;
    creer_pioche(paquet);

    int stats_numero[13];
    int stats_bonus[6];

    for (int i = 0; i < 13; i++) {
        stats_numero[i] = 0;
    }

    for (int i = 0; i < 6; i++) {
        stats_bonus[i] = 0;
    }

    while (continuer_partie) {

        printf("\n=== Début de la manche %d ===\n", manche_n);

        int joueurs_actifs = nb_joueurs;

        // Réinitialise l'état des joueurs
        for (int i = 0; i < nb_joueurs; i++) {
            joueurs[i].actif = 1;
            joueurs[i].nb_carte = 0;
        }

        // Continue tant qu'il reste des joueurs actifs
        while (joueurs_actifs > 0) {

            for (int i = 0; i < nb_joueurs; i++) {

                if (joueurs[i].actif == 1) {

                    printf("\n=== %s, c'est à toi ! ===\n", joueurs[i].nom);

                    int score_manche = 0;
                    int perdu = 0;

                    // Le joueur continue tant qu'il choisit de piocher
                    // et qu'il n'a pas perdu
                    while (joueurs[i].actif == 1) {

                        tour_joueur(paquet, joueurs, &taille_pioche, joueurs[i].main, &joueurs[i].nb_carte, &score_manche, &joueurs[i].actif, &perdu, i, stats_numero, stats_bonus);
                    }

                    // Si le joueur n'a pas perdu,
                    // ses points sont ajoutés au score total
                    if (!perdu) {
                        joueurs[i].score += score_manche;
                    }
                    else {
                        printf("%s a perdu → 0 point\n", joueurs[i].nom);
                    }

                    joueurs_actifs--;
                }
            }
        }

        printf("\n=== Fin de la manche %d ===\n", manche_n);

        int gagnant = -1;
        int meilleur_score = 0;

        for (int i = 0; i < nb_joueurs; i++) {

            printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);

            // On cherche le joueur ayant le meilleur score parmi ceux ayant au moins 200 points
            if (joueurs[i].score >= 200 && joueurs[i].score > meilleur_score) {

                meilleur_score = joueurs[i].score;
                gagnant = i;
            }
        }

        if (gagnant != -1) {

            printf("\n%s a gagné la partie avec %d points !\n", joueurs[gagnant].nom, joueurs[gagnant].score);
            break;
        }

        manche_n++;
       
        int verif;

        do {

            printf("\nContinuer la partie ? (1 = oui, 0 = non) : ");

            verif = scanf("%d", &continuer_partie);

            vide_buffer();
           
            if (verif != 1) {
                printf("Erreur, entrer un entier\n");
            }

            printf("\n\n\n");

        } while (verif != 1);
    }

    printf("\n=== FIN DE PARTIE ===\n");

    for (int i = 0; i < nb_joueurs; i++) {
        printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
    }

    sauvegarder_scores(joueurs, nb_joueurs);
}