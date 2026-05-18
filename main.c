#include "Projet.h"

int main(){
    srand(time(NULL));

    Carte paquet[79];
    creer_pioche(paquet);

    Joueur *joueurs;
    int nb_joueurs;

    printf("Combien de joueurs ? : ");
    scanf("%d", &nb_joueurs);

    joueurs = malloc(nb_joueurs * sizeof(Joueur));
    
    if(joueurs == NULL){
        printf("erreur d'allocation");
        exit(1);
    }

    start(joueurs, &nb_joueurs);

    int index = 0;
    int joueurs_actifs = nb_joueurs;

    while (joueurs_actifs > 0) {

        for (int i = 0; i < nb_joueurs; i++) {

            if (joueurs[i].actif == 1) {

                printf("\n=== Tour de %s ===\n", joueurs[i].nom);

                tour_joueur(paquet, &index, joueurs[i].main, &joueurs[i].nb_carte, &joueurs[i].score, &joueurs[i].actif);

                if (joueurs[i].actif == 0) {
                    joueurs_actifs--;
                }
            }
        }
    }

    printf("\n=== FIN DE PARTIE ===\n");

    for (int i = 0; i < nb_joueurs; i++) {
        printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
    }

    free(joueurs); // très important

    return 0;
}