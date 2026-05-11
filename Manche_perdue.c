#include 'Projet.h'

int manche_perdue(Joueur j, Carte c){
    for(int i=0; i<j.nb_carte; i++){
        if(j.main[i].numero == c.numero){
            printf("Vous avez perdu...");
            retrun 1;
        }
    }
    return 0;
}