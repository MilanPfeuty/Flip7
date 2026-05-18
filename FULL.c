
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
void calcul_score(Joueur *j);
Carte carte_piochee(Carte paquet[], int *index);
void creer_pioche(Carte paquet[]);
int choix_joueur();
void init_joueur(Joueur *j, char nom[]);
int manche_perdue(Joueur j, Carte c);
void restitution_nb_cartes(Joueur* j);
void restitution_score(Joueur* j);
void tour_joueur(Carte paquet[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu);




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


void calcul_score(Joueur *j){
    
    j-> score = 0;
    for(int i=0; i<j-> nb_carte; i++){
        j-> score += j-> main[i].numero;
    }
}



Carte carte_piochee(Carte paquet[], int *taille) {
    int c_aléa = rand() % (*taille);

    Carte c = paquet[c_aléa];

    // remplacer la carte tirée par la dernière
    paquet[c_aléa] = paquet[*taille - 1];

    (*taille)--;

    return c;
}



int choix_joueur(){
    int choix;

    printf("Continuer ? (1 = oui, 0 = non) : ");
    scanf(" %d", &choix);

    while (getchar() != '\n');

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



int start(Joueur joueurs[], int *nb_joueurs){

    for(int i = 0 ;i < *nb_joueurs ; i++){
        printf("Entrez le nom/pseudo du joueur %d : ", i+1);
        scanf("%s",joueurs[i].nom);

        joueurs[i].score = 0;
        joueurs[i].actif = 1;
        joueurs[i].nb_carte = 0;
    }
    return 0;
}



void tour_joueur(Carte paquet[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu){

    if (*actif == 0) return;
    
    if (*taille_pioche <= 0) {
        printf("Plus de cartes !\n");
        *actif = 0;
        return;
    }

    Carte c = carte_piochee(paquet, taille_pioche);
    printf("\nCarte piochée : %d\n", c.numero);

    // Vérifier doublon
    for (int i = 0; i < *taille; i++) {
        if (main[i].numero == c.numero) {
            printf("Doublon ! Perdu !\n");
            *actif = 0;
            *perdu = 1;
            return;
        }
    }

    // Ajouter carte
    main[*taille] = c;
    (*taille)++;

    // Ajouter score
    *score += c.numero;

    afficher_joueur(*score, main, *taille);

    if (*taille == 7) {
        printf(" Victoire !\n");
        *actif = 0;
        return;
    }

    if (choix_joueur() == 0) {
        *actif = 0;
    }
}



int main(){
    srand(time(NULL));

    Carte paquet[79];
    Joueur *joueurs;
    int nb_joueurs;

    // Nombre de joueurs
    printf("Combien de joueurs ? : ");
    scanf("%d", &nb_joueurs);

    joueurs = malloc(nb_joueurs * sizeof(Joueur));

    // Initialisation joueurs
    start(joueurs, &nb_joueurs);

    int continuer_partie = 1;
    int manche_n = 1;

    // ===== BOUCLE DE PARTIE =====
    while (continuer_partie) {

        printf("\n Début de la manche %d \n", manche_n);

        int taille_pioche = 79;
        creer_pioche(paquet);
        int joueurs_actifs = nb_joueurs;

        // Reset joueurs pour la manche
        for (int i = 0; i < nb_joueurs; i++) {
            joueurs[i].actif = 1;
            joueurs[i].nb_carte = 0;
        }

        // ===== BOUCLE DE MANCHE =====
        while (joueurs_actifs > 0) {

            for (int i = 0; i < nb_joueurs; i++) {

                if (joueurs[i].actif == 1) {

                    printf("\n=== Tour de %s ===\n", joueurs[i].nom);

                    int score_manche = 0;
                    int perdu = 0;

                    // Tour du joueur
                    while (joueurs[i].actif == 1) {
                        tour_joueur(paquet, &taille_pioche, joueurs[i].main, &joueurs[i].nb_carte, &score_manche, &joueurs[i].actif, &perdu);
                    }

                    // Vérifier doublon
                    for (int j = 0; j < joueurs[i].nb_carte - 1; j++) {
                        if (joueurs[i].main[j].numero == joueurs[i].main[joueurs[i].nb_carte - 1].numero) {
                            perdu = 1;
                        }
                    }

                    // Attribution des points
                    if (perdu) {
                        printf("%s a perdu → 0 point\n", joueurs[i].nom);
                    } else {
                        joueurs[i].score += score_manche;
                    }

                    joueurs_actifs--;
                }
            }
        }

        // ===== FIN DE MANCHE =====
        printf("\n Fin de la manche %d \n", manche_n);
        for (int i = 0; i < nb_joueurs; i++) {
            printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
        }

        manche_n ++;
        // Continuer ?
        printf("\nContinuer la partie ? (1 = oui, 0 = non) : ");
        scanf("%d", &continuer_partie);
    }

    // ===== FIN DE PARTIE =====
    printf("\n=== FIN DE PARTIE ===\n");
    for (int i = 0; i < nb_joueurs; i++) {
        printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
    }

    free(joueurs);
    return 0;
}