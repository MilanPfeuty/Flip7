#include 'Projet.h'

void tour_joueur(Carte paquet[], int *index, int main[], int *taille, int *score, int *actif) {

    if (*actif == 0) return;

    // Piocher
    Carte c = paquet[(*index)++];

    printf("\nCarte piochée : %d\n", c.numero);

    // Vérifier doublon
    for (int i = 0; i < *taille; i++) {
        if (main[i] == c.numero) {
            printf("💀 Doublon ! Perdu !\n");
            *actif = 0;
            return;
        }
    }

    // Ajouter à la main
    main[*taille] = c.numero;
    (*taille)++;

    // Ajouter au score
    *score += c.numero;

    // Affichage
    afficher_joueur(*score, main, *taille);

    // Victoire
    if (*taille == 7) {
        printf("🎉 Victoire !\n");
        *actif = 0;
        return;
    }

    // Choix joueur
    if (demander_choix() == 0) {
        *actif = 0;
    }
}