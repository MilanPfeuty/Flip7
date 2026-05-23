#include "Projet.h"


void affiche_pioche(Carte* paquet) {
    for (int i = 0; i < 85; i++) {
        if (paquet[i].bonus == 0){
            printf("%d ", paquet[i].numero);
        }
        else if (paquet[i].bonus == -2){
            printf("x2 ");
        }
        else{
            printf("+%d ", paquet[i].bonus);
        }
    }
    printf("\n");
}