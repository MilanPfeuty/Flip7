#include "Projet.h"


void affiche_pioche(Carte* paquet){
    for (int i=0; i<79; i++){
        printf("%d ", paquet[i].numero);
    }
    printf("\n");
}