#include "Projet.h"

// Initialise la pioche
void creer_pioche(Carte paquet[]) {

    int p = 0;

    // Création des cartes normales
    for (int i = 0; i < 13; i++) {
       
        int nb;

        // Les cartes 0 et 1 existent en double
        if (i == 0 || i == 1){
            nb = 1;
        }
        else{
            nb = i;
        }

        // Ajoute plusieurs exemplaires d'une même carte
        // Exemple :
        // 5 → 5 cartes "5"
        // 10 → 10 cartes "10"
        for (int j = 0; j < nb; j++) {

            paquet[p].numero = i;
            paquet[p].bonus = 0;
            p++;
        }
    }

    // Ajout des cartes bonus (+2, +4, +6, +8, +10)
    for (int val = 2; val <= 10; val += 2) {

        paquet[p].numero = 0;
        paquet[p].bonus = val;
        p++;
    }

    // Ajout de la carte spéciale x2
    paquet[p].numero = 0;
    paquet[p].bonus = -2;
    p++;
}