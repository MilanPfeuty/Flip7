
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


typedef struct{
    int numero;
} Carte;


typedef struct{
    char nom[100];
    int score;
    Carte main[7];
    int nb_carte;
    int actif;
}Joueur;


int start(Joueur joueurs[], int *nb_joueurs);
void afficher_joueur(int score, Carte cartes[], int taille);
void affiche_pioche(Carte* paquet);
void afficher_main(Joueur j);
void calcul_score(Joueur j);
Carte carte_piochee(Carte paquet[], int *index);
void creer_pioche(Carte paquet[]);
int choix_joueur();
void init_joueur(Joueur *j, char nom[]);
int manche_perdue(Joueur j, Carte c);
void restitution_nb_cartes(Joueur* j);
void restitution_score(Joueur* j);
void tour_joueur(Carte paquet[], int *index, Carte main[], int *taille, int *score, int *actif);




void afficher_joueur(int score, Carte cartes[], int taille){
    printf("\n--- JOUEUR ---\n");

    printf("Main : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", cartes[i].numero);
    }

    printf("\nScore : %d\n", score);
}

void affiche_pioche(Carte* paquet){
    for (int i=0; i<79; i++){
        printf("%d ", paquet[i].numero);
    }
    printf("\n");
}


void afficher_main(Joueur j){
    printf("Main de %s: ", j.nom);

    for(int i=0; i<j.nb_carte; i++){
        printf("[%d]", j.main[i].numero);
    }
    
    printf("\n");
}


void calcul_score(Joueur j){
    
    j.score = 0;
    for(int i=0; i<j.nb_carte; i++){
        j.score += j.main[i].numero;
    }
}



Carte carte_piochee(Carte paquet[], int *index){
    return paquet[(*index)++];
}



int choix_joueur(){
    int choix;

    printf("Continuer ? (1 = oui, 0 = non) : ");
    scanf("%d", &choix);

    return choix;
}




void creer_pioche(Carte paquet[]){
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



void init_joueur(Joueur *j, char nom[]){
    strcpy(j->nom, nom);   // faudra mettre string.h
    j -> score = 0;
    j -> nb_carte = 0;
}




int manche_perdue(Joueur j, Carte c){
    for(int i=0; i<j.nb_carte; i++){
        if(j.main[i].numero == c.numero){
            printf("Vous avez perdu...");
            return 1;
        }
    }
    return 0;
}



void restitution_nb_cartes(Joueur* j){
    j-> nb_carte = 0;
}




void restitution_score(Joueur* j){
    j-> score = 0;
}



int start(){
    int nb_joueurs[10];
    Joueur *joueurs;

    printf("Combien de joueurs ? : ");
    scanf("%d",nb_joueurs);
    for(int i = 0 ;i < *nb_joueurs ; i++){
        printf("Entrez le nom/pseudo du joueur %d : ", i+1);
        scanf("%s",joueurs[i].nom);

        joueurs[i].score = 0;
        joueurs[i].actif = 1;
        joueurs[i].nb_cartes = 0;
    }
    return 0;
}



void tour_joueur(Carte paquet[], int *index, Carte main[], int *taille, int *score, int *actif){

    if (*actif == 0) return;

    if (*index >= 79) {
        printf("Plus de cartes !\n");
        *actif = 0;
        return;
    }

    // Piocher
    Carte c = paquet[(*index)++];

    printf("\nCarte piochée : %d\n", c.numero);

    // Vérifier doublon
    for (int i = 0; i < *taille; i++) {
        if (main[i].numero == c.numero) {
            printf("💀 Doublon ! Perdu !\n");
            *actif = 0;
            return;
        }
    }

    // Ajouter à la main
    main[*taille] = c;
    (*taille)++;

    // Ajouter au score
    *score += c.numero;

    // Affichage
    afficher_joueur(*score, main, *taille);

    // Victoire
    if (*taille == 7) {
        printf("🎉 Victoire !\n");
        *actif = 0;
        return;
    }

    // Choix joueur
    if (choix_joueur() == 0) {
        *actif = 0;
    }
}





int main(){
    srand(time(NULL));

    Carte paquet[79];

    Joueur joueurs[10];
    int nb_joueurs;

    start(joueurs, &nb_joueurs);

    creer_pioche(paquet);
    affiche_pioche(paquet);



    int index = 0;
    Carte carte = carte_piochee(paquet, &index);
    printf("Carte piochée : %d\n", carte.numero);



    return 0;
}
