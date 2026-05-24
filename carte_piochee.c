#include "Projet.h"

// Pioche une carte aléatoire et la retire du paquet
Carte carte_piochee(Carte paquet[], int *taille) {

    // Génère un indice aléatoire dans le paquet
    int alea = rand() % (*taille);

    // Sauvegarde la carte choisie
    Carte c = paquet[alea];

    // On remplace la carte piochée par la dernière carte du paquet
    paquet[alea] = paquet[*taille - 1];

    // Puis on réduit la taille du paquet pour supprimer la carte piochée
    (*taille)--;

    return c;
}