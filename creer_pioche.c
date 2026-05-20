#include "Projet.h"

void creer_pioche(Carte paquet[]) {
    int p = 0;

    for (int i = 0; i < 13; i++) {
        
        int nb;
        if (i == 0 || i == 1){
            nb = 1;
        }
        else{
            nb = i;
        }

        for (int j = 0; j < nb; j++) {
            paquet[p].numero = i;
            paquet[p].bonus = 0;
            p++;
        }
    }

    // Bonus +2 à +10
    for (int val = 2; val <= 10; val += 2) {
        paquet[p].numero = 0;
        paquet[p].bonus = val;
        p++;
    }

    // x2
    paquet[p].numero = 0;
    paquet[p].bonus = -2;
    p++;
}