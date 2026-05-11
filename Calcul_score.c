#include 'projet.h'

void calcul_score(Joueur j){
    
    j.score = 0;
    for(int i=0; i<j.nb_carte; i++){
        j.score += j.main[i].numero;
    }
    return score;
}