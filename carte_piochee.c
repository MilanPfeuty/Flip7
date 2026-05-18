#include "Projet.h"

Carte carte_piochee(Carte paquet[], int *taille) {
    int c_aléa = rand() % (*taille);

    Carte c = paquet[c_aléa];

    // remplacer la carte tirée par la dernière
    paquet[c_aléa] = paquet[*taille - 1];

    (*taille)--;

    return c;
}