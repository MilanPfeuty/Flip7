#include "Projet.h"

int main(){
    srand(time(NULL));

    Carte paquet[79];

    Joueur joueurs[10];
    int nb_joueurs;

    start(joueurs, &nb_joueurs);

    creer_pioche(paquet);
    affiche_pioche(paquet);



    int index = 0;
    Carte carte = carte_piochee(paquet, &index);
    printf("Carte piochée : %d\n", carte.numero);



    return 0;
}
