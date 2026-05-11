#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int numero;
} Carte;

void creer_pioche(Carte paquet[]) {
    int p = 0;

    for (int i = 0; i < 13; i++) {
        int nb;

        if (i == 0 || i == 1) {
            nb = 1;
        } else {
            nb = i;
        }

        for (int j = 0; j < nb; j++) {
            paquet[p].numero = i;
            p++;
        }
    }
}

void affiche_pioche(Carte paquet[]) {
    for (int i = 0; i < 79; i++) {
        printf("%d ", paquet[i].numero);
    }
    printf("\n");
}

Carte carte_pioche(Carte paquet[], int *index) {
    return paquet[(*index)++];
}

int main() {
    srand(time(NULL));

    Carte paquet[79];
    int index = 0;

    creer_pioche(paquet);

    printf("Paquet initial :\n");
    affiche_pioche(paquet);

    printf("\nCartes piochées :\n");

    for (int i = 0; i < 5; i++) {
        Carte c = carte_pioche(paquet, &index);
        printf("%d ", c.numero);
    }

    printf("\n");

    return 0;
}