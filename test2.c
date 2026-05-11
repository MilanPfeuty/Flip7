#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    int numero;
} Carte;

void creer_pioche(Carte paquet[]){
    int p = 0;

    for(int i = 0; i < 13; i++){
        int nb;.0

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
}

void affiche_pioche(Carte paquet[]){
    for (int i = 0; i < 79; i++){
        printf("%d ", paquet[i].numero);
    }
    printf("\n");
}

Carte carte_pioche(Carte paquet[]){
    int i = rand() % 79;
    return paquet[i];
}

int main(){
    srand(time(NULL));

    Carte paquet[79];

    creer_pioche(paquet);   
    affiche_pioche(paquet); 
    Carte c = carte_pioche(paquet);
    printf("Carte piochée : %d\n", c.numero);

    return 0;
}

https://chatgpt.com/gg/v/69eb9e1c536c819f8659a893cb4cb96d?token=wndHod3SwHn4uZOz0RF2_g
