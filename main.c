#include "Projet.h"

int main() {
    srand(time(NULL));
    
    Carte paquet[85];
    int nb_joueurs;
    int verif;

    // Saisie nombre de joueurs
    do {
        printf("Combien de joueurs ? : ");
        verif = scanf("%d", &nb_joueurs);
        vide_buffer();

        if (nb_joueurs < 1){
            printf("ERREUR ! Veuillez entrer un nombre de joueurs supérieur ou égale à 1\n");
            return main();
        }
        if (verif != 1) {
            printf("Erreur, entrer un entier\n");
        }
    } while (verif != 1);

    Joueur *joueurs;
    joueurs = malloc(nb_joueurs * sizeof(Joueur));

    start(joueurs, &nb_joueurs);

    deroulement_partie(paquet, joueurs, nb_joueurs);

    free(joueurs);
    return 0;
}