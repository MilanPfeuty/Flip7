#include "Projet.h"

int main() {
    srand(time(NULL));

    Carte paquet[79];
    Joueur *joueurs;
    int nb_joueurs;
    int verif;

    // Saisie joueurs
    do {
        printf("Combien de joueurs ? : ");
        verif = scanf("%d", &nb_joueurs); // ✅ correction
        vide_buffer();

        if (verif != 1) {
            printf("Erreur, entrer un entier\n");
        }
    } while (verif != 1);

    joueurs = malloc(nb_joueurs * sizeof(Joueur));

    start(joueurs, &nb_joueurs);

    int continuer_partie = 1;

    // Numéro de la manche
    int manche_n = 1;

    while (continuer_partie) {

        printf("\n=== Début de la manche %d ===\n", manche_n);

        int taille_pioche = 79;
        creer_pioche(paquet);

        int joueurs_actifs = nb_joueurs;

        for (int i = 0; i < nb_joueurs; i++) {
            joueurs[i].actif = 1;
            joueurs[i].nb_carte = 0;
        }

        while (joueurs_actifs > 0) {

            for (int i = 0; i < nb_joueurs; i++) {

                if (joueurs[i].actif == 1) {

                    printf("\n=== Tour de %s ===\n", joueurs[i].nom);

                    int score_manche = 0;
                    int perdu = 0;

                    while (joueurs[i].actif == 1) {
                        tour_joueur(
                            paquet,
                            &taille_pioche,
                            joueurs[i].main,
                            &joueurs[i].nb_carte,
                            &score_manche,
                            &joueurs[i].actif,
                            &perdu
                        );
                    }

                    if (perdu) {
                        printf("%s a perdu → 0 point\n", joueurs[i].nom);
                    } else {
                        joueurs[i].score += score_manche;
                    }

                    joueurs_actifs--;
                }
            }
        }

        // ===== FIN DE MANCHE =====
        printf("\n Fin de la manche %d \n", manche_n);

        int gagnant = -1;

        for (int i = 0; i < nb_joueurs; i++) {
            printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);

            if (joueurs[i].score >= 100) {
                gagnant = i;
            }
        }

        if (gagnant != -1) {
            printf("\n🏆 %s a gagné la partie avec %d points !\n",
                joueurs[gagnant].nom,
                joueurs[gagnant].score);

            break; // stop la boucle de partie
        }

        // Numéro de la manche +1
        manche_n++;

        printf("\nContinuer la partie ? (1 = oui, 0 = non) : ");
        scanf("%d", &continuer_partie);
    }

    printf("\n=== FIN DE PARTIE ===\n");
    for (int i = 0; i < nb_joueurs; i++) {
        printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
    }

    free(joueurs);
    return 0;
}