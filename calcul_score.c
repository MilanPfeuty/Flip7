#include "Projet.h"

// Calcule le score du joueur lors de son tour après chaque tirage
int calcul_score(Carte main[], int taille) {

    int score = 0;

    for (int i = 0; i < taille; i++) {

        // Carte normale : on ajoute simplement sa valeur
        if (main[i].bonus == 0) {
            score += main[i].numero;
        }

        // Carte spéciale x2 : Multiplie le score actuel par 2
        else if (main[i].bonus == -2) {
            score *= 2;
        }

        // Carte bonus : ajoute un bonus fixe au score
        else {
            score += main[i].bonus;
        }
    }

    return score;
}