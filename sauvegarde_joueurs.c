#include "Projet.h"

// Sauvegarde les scores dans un fichier texte
void sauvegarder_scores(Joueur joueurs[], int nb_joueurs) {

    int choix;
    char nom_fichier[100];

    printf("\nVoulez-vous sauvegarder les scores ? (1 = oui, 0 = non) : ");

    scanf("%d", &choix);

    vide_buffer();

    if (choix == 1) {

        printf("Nom du fichier : ");

        scanf("%s", nom_fichier);

        // Ouverture du fichier en mode écriture
        FILE *fichier = fopen(nom_fichier, "w");

        if (fichier == NULL) {
            printf("Erreur lors de l'ouverture du fichier\n");
            return;
        }

        fprintf(fichier, "=== RESULTATS DE LA PARTIE ===\n\n");

        for (int i = 0; i < nb_joueurs; i++) {
            fprintf(fichier, "%s : %d points\n", joueurs[i].nom, joueurs[i].score);
        }

        fclose(fichier);

        printf("Scores sauvegardés dans %s\n", nom_fichier);
    }
}