#include "Projet.h"

int main(){
    srand(time(NULL));

    Carte paquet[79];

    start();

    creer_pioche(paquet);
    affiche_pioche(paquet);



    int index = 0;
    Carte carte = carte_piochee(paquet, &index);
    printf("Carte piochée : %d\n", carte.numero);



    return 0;
}
