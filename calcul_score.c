#include "Projet.h"

int calcul_score(Carte main[], int taille) {
    int score = 0;

    for (int i = 0; i < taille; i++) {

        if (main[i].bonus == 0) {
            score += main[i].numero;
        }
        else if (main[i].bonus == -2) {
            score *= 2;
        }
        else {
            score += main[i].bonus;
        }
    }

    return score;
}