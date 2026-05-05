#include 'projet.h'
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



typedef struct{
    int numero;
}Carte


Carte* pioche(){
    Carte* paquet = malloc(sizeof(Carte) * 79);
    if (paquet == NULL){
        exit(1);
    }

    int p = 0;

    for(int i = 0; i < 13; i++){
        int nb;

        if(i == 0 || i == 1){
            nb = 1;
        } else {
            nb = i;
        }

        for(int j = 0; j < nb; j++){
            paquet[p].numero = i;
            p++;
        }
    }

    for (int i=0; i<79; i++){
        printf("%d ", paquet[i].numero);
    }
    return paquet;
}


Carte carte_pioche(){
    int pioche = pioche();
    int nv_carte;
    int i = rand()%80;

    nv_carte = pioche[i]

    return nv_carte;
}



}



void mainjoueur(){}



int decision_joueur(){
    int choix;
printf("Voulez vous continuer a jouer ?: 1-oui \n 0-non \n");
    scanf("%d", &choix);
return choix;
}

