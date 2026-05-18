#include "Projet.h"

void afficher_main(Joueur j) {
    printf("Main de %s: ", j.nom);
    for (int i = 0; i < j.nb_carte; i++) {
        printf("[%d]", j.main[i].numero);
    }
    printf("\n");
}