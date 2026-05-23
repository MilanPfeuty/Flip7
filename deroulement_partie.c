#include "Projet.h"

void deroulement_partie(Carte paquet[], Joueur joueurs[], int nb_joueurs){

    int continuer_partie = 1;
    int manche_n = 1;

    while (continuer_partie) {

        printf("\n=== Début de la manche %d ===\n", manche_n);

        int taille_pioche = 85;
        creer_pioche(paquet);

        int joueurs_actifs = nb_joueurs;

        for (int i = 0; i < nb_joueurs; i++) {
            joueurs[i].actif = 1;
            joueurs[i].nb_carte = 0;
        }

        while (joueurs_actifs > 0) {

            for (int i = 0; i < nb_joueurs; i++) {

                if (joueurs[i].actif == 1) {

                    printf("\n=== %s, c'est à toi ! ===\n", joueurs[i].nom);

                    int score_manche = 0;
                    int perdu = 0;

                    while (joueurs[i].actif == 1) {
                        tour_joueur(paquet, joueurs, &taille_pioche, joueurs[i].main, &joueurs[i].nb_carte, &score_manche, &joueurs[i].actif, &perdu, i);
                    }

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

        // ===== FIN DE MANCHE =====
        printf("\n=== Fin de la manche %d ===\n", manche_n);

        int gagnant = -1;

        for (int i = 0; i < nb_joueurs; i++) {
            printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);

            if (joueurs[i].score >= 200 && gagnant == -1) {
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