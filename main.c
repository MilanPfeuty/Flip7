#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
    srand(time(NULL));

    Carte paquet[79];

    creer_pioche(paquet);   
    affiche_pioche(paquet); 
    Carte c = carte_pioche(paquet);
    printf("Carte piochée : %d\n", c.numero);

    return 0;
}