#include 'Projet.h'

void start(Joueur joueurs, int* nb_joueurs){
    printf("Combien de joueurs ?");
    scanf("%d",nb_joueurs);
    for(int i=0;i<*nb_joueurs;i++){
        printf("Entrez votre pseudo");
        scanf("%s",joueurs);
    }
}