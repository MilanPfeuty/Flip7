#include "Projet.h"

int main(){
    srand(time(NULL));

    Carte paquet[79];
    Joueur *joueurs;

    if (joueurs == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(1);
    }
    
    int nb_joueurs;

    int verif = 0;

    do {
        printf("Combien de joueurs ? : ");
        verif = scanf("%d", &nb_joueurs);
        vide_buffer();

        if (verif != 1) {
            printf("Erreur, entrer un entier\n");
        }
    } while (verif != 1);

    joueurs = malloc(nb_joueurs * sizeof(Joueur));

    // Initialisation joueurs
    start(joueurs, &nb_joueurs);

    int continuer_partie = 1;
    int manche_n = 1;

    // ===== BOUCLE DE PARTIE =====
    while (continuer_partie) {

        printf("\n Début de la manche %d \n", manche_n);

        int taille_pioche = 79;
        creer_pioche(paquet);
        int joueurs_actifs = nb_joueurs;

        // Reset joueurs pour la manche
        for (int i = 0; i < nb_joueurs; i++) {
            joueurs[i].actif = 1;
            joueurs[i].nb_carte = 0;
        }

        // ===== BOUCLE DE MANCHE =====
        while (joueurs_actifs > 0) {

            for (int i = 0; i < nb_joueurs; i++) {

                if (joueurs[i].actif == 1) {

                    printf("\n=== Tour de %s ===\n", joueurs[i].nom);

                    int score_manche = 0;
                    int perdu = 0;

                    // Tour du joueur
                    while (joueurs[i].actif == 1) {
                        tour_joueur(paquet, &taille_pioche, joueurs[i].main, &joueurs[i].nb_carte, &score_manche, &joueurs[i].actif, &perdu);
                    }

                    // Attribution des points
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
        for (int i = 0; i < nb_joueurs; i++) {
            printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
        }

        manche_n ++;
        // Continuer ?
        printf("\nContinuer la partie ? (1 = oui, 0 = non) : ");
        scanf("%d", &continuer_partie);
    }

    // ===== FIN DE PARTIE =====
    printf("\n=== FIN DE PARTIE ===\n");
    for (int i = 0; i < nb_joueurs; i++) {
        printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
    }

    free(joueurs);
    return 0;
}

