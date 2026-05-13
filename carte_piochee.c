#include "Projet.h"

Carte carte_piochee(Carte paquet[], int *index){
    return paquet[(*index)++];
}
