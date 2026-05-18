#include "Projet.h"

Carte carte_piochee(Carte paquet[], int *taille) {
    int alea = rand() % (*taille);
    Carte c = paquet[alea];

    paquet[alea] = paquet[*taille - 1];
    (*taille)--;

    return c;
}