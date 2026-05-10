void init_joueur(Joueur *j, char nom[]){
    strcpy(j->nom, nom);   // faudra mettre string.h
    j -> score = 0;
    j -> nb_carte;
}