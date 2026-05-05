#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int numero;
} Carte;

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
    return paquet;
}

void affiche_pioche(){
    for (int i=0; i<79; i++){
        printf("%d ", pioche()[i].numero);
    }
}


Carte carte_pioche(){
    Carte* p_ioche = pioche();
    Carte nv_carte;
    int i = rand()%80;

    nv_carte = p_ioche[i];

    return nv_carte;
}


int main(){
    affiche_pioche();
    printf("%d", carte_pioche());
    return 0;
}