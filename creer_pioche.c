#include "Projet.h"

void creer_pioche(Carte paquet[]) {
    int p = 0;

    for (int i = 0; i < 13; i++) {
        int nb = (i == 0 || i == 1) ? 1 : i;

        for (int j = 0; j < nb; j++) {
            paquet[p].numero = i;
            p++;
        }
    }
}