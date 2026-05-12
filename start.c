#include "Projet.h"

void start(Joueur *joueurs, int* nb_joueurs){
    printf("Combien de joueurs ?");
    scanf("%d",nb_joueurs);
    for(int i=0;i<*nb_joueurs;i++){
        printf("Entrez le nom du joueur %d", i+1);
        scanf("%s",joueurs[i].nom);

        joueurs[i].score=0;
        joueurs[i].actif=1;
    }
}
