#include "Projet.h"

void creer_pioche(Carte paquet[]) {
    int p = 0;

    for (int i = 0; i < 13; i++) {
        int nb;

        if (i == 0 || i == 1) {
            nb = 1;
        } else {
            nb = i;
        }

        for (int j = 0; j < nb; j++) {
            paquet[p].numero = i;
            p++;
        }
    }
}