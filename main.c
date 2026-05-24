#include "Projet.h"

// Fonction principale
int main() {

    srand(time(NULL));
   
    Carte paquet[85];

    int nb_joueurs;    
    int verif;
    char extra;

    do {

        printf("Combien de joueurs ? : ");

        // Lecture sécurisée :
        // on vérifie qu'un entier ET un retour à la ligne sont saisis
        verif = scanf("%d%c", &nb_joueurs, &extra);

        if (verif == 2 && extra == '\n') {

            if(nb_joueurs > 1000){
                printf("Trop de joueurs !!\n");
                verif = 0;
            }

            if (nb_joueurs < 1) {
                printf("ERREUR ! Veuillez entrer un nombre >= 1 ou <= 2 milliards\n");
                verif = 0;
            }
           
        }else {
            printf("Erreur : entre un entier valide !\n");
            vide_buffer();
            verif = 0;
        }

    } while (verif != 2);

    Joueur *joueurs;

    // Allocation dynamique du tableau de joueurs
    joueurs = malloc(nb_joueurs * sizeof(Joueur));

    if (joueurs == NULL){
        printf("Erreur : Mémoire insuffisante");
        exit(1);
    }

    debut(joueurs, &nb_joueurs);

    printf("\n\n\n");

    deroulement_partie(paquet, joueurs, nb_joueurs);

    // Libération de la mémoire allouée dynamiquement
    free(joueurs);

    return 0;
}
