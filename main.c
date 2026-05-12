#include "Projet.h"

int jeu_prs(){
    srand(time(NULL));

    Carte paquet[79];

    creer_pioche(paquet);
    affiche_pioche(paquet);
    int index = 0;
    Carte carte = carte_pioche(paquet, &index);
    printf("Carte piochée : %d\n", carte.numero);

    return 0;
}
