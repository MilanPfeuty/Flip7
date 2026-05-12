#include "Projet.h"

Carte carte_pioche(Carte paquet[], int *index) {
    return paquet[(*index)++];
}