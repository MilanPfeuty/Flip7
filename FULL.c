/*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    int numero;
    int bonus;
} Carte;

typedef struct {
    char nom[100];
    int score;
    Carte main[7];
    int nb_carte;
    int actif;
} Joueur;

// Prototypes
void vide_buffer();

void afficher_joueur(Carte c, int score, Joueur joueurs[], Carte cartes[], int taille , int i);
void affiche_pioche(Carte* paquet);
void afficher_main(Joueur j);

void calcul_score(Joueur *j);
Carte carte_piochee(Carte paquet[], int *taille);

int choix_joueur();

void creer_pioche(Carte paquet[]);

void deroulement_partie(Carte paquet[], Joueur joueurs[], int nb_joueurs);

int start(Joueur joueurs[], int *nb_joueurs);

void tour_joueur(Carte paquet[], Joueur joueurs[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu, int i);


int main_joueurs();


// ================= FONCTIONS =================

void vide_buffer() {
    while (getchar() != '\n');
}

void afficher_joueur(Carte c, int score, Joueur joueurs[], Carte cartes[], int taille , int i) {
    
    printf("\n--- JOUEUR %s ---\n", joueurs[i].nom);

    if (c.bonus == 0) {
        printf("\nCarte piochée : %d\n", c.numero);
    }
    else if (c.bonus == -2) {
        printf("\nCarte piochée : x2\n");
    }
    else {
        printf("\nCarte piochée : +%d\n", c.bonus);
    }

    printf("Main de %s : ", joueurs[i].nom);
    for (int i = 0; i < taille; i++) {
        if (cartes[i].bonus == 0) {
            printf("%d ", cartes[i].numero);
        }
        else if (cartes[i].bonus == -2) {
            printf("x2 ");
        }
        else {
            printf("+%d ", cartes[i].bonus);
        }
    }
    printf("\nScore de la manche : %d\n", score);
    printf("\nScore général : %d\n", joueurs[i].score+score);
    printf("\n");
}

void affiche_pioche(Carte* paquet) {
    for (int i = 0; i < 85; i++) {
        if (paquet[i].bonus == 0){
            printf("%d ", paquet[i].numero);
        }
        else if (paquet[i].bonus == -2){
            printf("x2 ");
        }
        else{
            printf("+%d ", paquet[i].bonus);
        }
    }
    printf("\n");
}

void afficher_main(Joueur j) {
    printf("Main de %s: ", j.nom);
    for (int i = 0; i < j.nb_carte; i++) {
        printf("[%d]", j.main[i].numero);
    }
    printf("\n");
}


void calcul_score(Joueur *j) {
    j->score = 0;
    for (int i = 0; i < j->nb_carte; i++) {
        j->score += j->main[i].numero;
    }
}


Carte carte_piochee(Carte paquet[], int *taille) {
    int alea = rand() % (*taille);
    Carte c = paquet[alea];

    paquet[alea] = paquet[*taille - 1];
    (*taille)--;

    return c;
}

int choix_joueur() {
    int choix;

    do {
        printf("Continuer ? (1 = oui, 0 = non) : ");
        scanf("%d", &choix);
        vide_buffer();

        if (choix != 1 && choix != 0) {
            printf("Veuillez entrer une des 2 valeurs proposées !!\n");
        }

    } while (choix != 1 && choix != 0);

    return choix;
}


void creer_pioche(Carte paquet[]) {
    int p = 0;

    for (int i = 0; i < 13; i++) {
        
        int nb;
        if (i == 0 || i == 1){
            nb = 1;
        }
        else{
            nb = i;
        }

        for (int j = 0; j < nb; j++) {
            paquet[p].numero = i;
            paquet[p].bonus = 0;
            p++;
        }
    }

    // Bonus +2 à +10
    for (int val = 2; val <= 10; val += 2) {
        paquet[p].numero = 0;
        paquet[p].bonus = val;
        p++;
    }

    // x2
    paquet[p].numero = 0;
    paquet[p].bonus = -2;
    p++;
}


void deroulement_partie(Carte paquet[], Joueur joueurs[], int nb_joueurs){

    int continuer_partie = 1;
    int manche_n = 1;

    while (continuer_partie) {

        printf("\n=== Début de la manche %d ===\n", manche_n);

        int taille_pioche = 85;
        creer_pioche(paquet);

        int joueurs_actifs = nb_joueurs;

        for (int i = 0; i < nb_joueurs; i++) {
            joueurs[i].actif = 1;
            joueurs[i].nb_carte = 0;
        }

        while (joueurs_actifs > 0) {

            for (int i = 0; i < nb_joueurs; i++) {

                if (joueurs[i].actif == 1) {

                    printf("\n=== %s, c'est à toi ! ===\n", joueurs[i].nom);

                    int score_manche = 0;
                    int perdu = 0;

                    while (joueurs[i].actif == 1) {
                        tour_joueur(paquet, joueurs, &taille_pioche, joueurs[i].main, &joueurs[i].nb_carte, &score_manche, &joueurs[i].actif, &perdu, i);
                    }

                    if (!perdu) {
                        joueurs[i].score += score_manche;
                    }
                    else {
                        printf("%s a perdu → 0 point\n", joueurs[i].nom);
                    }

                    joueurs_actifs--;
                }
            }
        }

        // ===== FIN DE MANCHE =====
        printf("\n=== Fin de la manche %d ===\n", manche_n);

        int gagnant = -1;

        for (int i = 0; i < nb_joueurs; i++) {
            printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);

            if (joueurs[i].score >= 200 && gagnant == -1) {
                gagnant = i;
            }
        }

        if (gagnant != -1) {
            printf("\n%s a gagné la partie avec %d points !\n", joueurs[gagnant].nom, joueurs[gagnant].score);
            break;
        }

        manche_n++;
        
        int verif;

        do {
            printf("\nContinuer la partie ? (1 = oui, 0 = non) : ");
            verif = scanf("%d", &continuer_partie);
            vide_buffer();

            if (verif != 1) {
                printf("Erreur, entrer un entier\n");
            }
        } while (verif != 1);
    }

    printf("\n=== FIN DE PARTIE ===\n");
    for (int i = 0; i < nb_joueurs; i++) {
        printf("%s : %d points\n", joueurs[i].nom, joueurs[i].score);
    }
}



int start(Joueur joueurs[], int *nb_joueurs) {
    for (int i = 0; i < *nb_joueurs; i++) {
        printf("Nom du joueur %d : ", i + 1);
        scanf("%s", joueurs[i].nom);

        joueurs[i].score = 0;
        joueurs[i].actif = 1;
        joueurs[i].nb_carte = 0;
    }
    return 1;
}


void tour_joueur(Carte paquet[], Joueur joueurs[], int *taille_pioche, Carte main[], int *taille, int *score, int *actif, int *perdu, int i) {

    if (*actif == 0) return;

    if (*taille_pioche <= 0) {
        printf("Plus de cartes !\n");
        *actif = 0;
        return;
    }

    Carte c = carte_piochee(paquet, taille_pioche);

    // Doublon
    for (int j = 0; j < *taille; j++) {
        if (c.bonus == 0 && main[j].numero == c.numero) {
            printf("Doublon ! Perdu !\n");
            *actif = 0;
            *perdu = 1;
            return;
        }
    }

    

    // Ajout carte
    main[*taille] = c;
    (*taille)++;

    if (c.bonus == 0) {
        *score += c.numero;
    }
    else if (c.bonus == -2) {
        *score *= 2;
    }
    else {
        *score += c.bonus;
    }

    afficher_joueur(c, *score, joueurs, main, *taille, i);

    if (*taille == 7) {
        printf("%s a gagné la manche ! Il obtient 15 points supplémentaires !\n", joueurs[i].nom);
        *actif = 0;
        joueurs[i].score += 15;
        return;
    }

    if (choix_joueur() == 0) {
        *actif = 0;
    }
}



// ================= MAIN =================

int main() {
    srand(time(NULL));
    
    Carte paquet[85];

    // Saisie nombre de joueurs
    int nb_joueurs;
    int verif;
    char extra;

    do {
        printf("Combien de joueurs ? : ");
        verif = scanf("%d%c", &nb_joueurs, &extra);

        if (verif == 2 && extra == '\n') {

            if (nb_joueurs < 1) {
                printf("ERREUR ! Veuillez entrer un nombre >= 1\n");
                verif = 0;
            }

        } else {
            printf("Erreur : entre un entier valide !\n");
            vide_buffer();
            verif = 0;
        }

    } while (verif != 2);

    Joueur *joueurs;
    joueurs = malloc(nb_joueurs * sizeof(Joueur));

    start(joueurs, &nb_joueurs);

    deroulement_partie(paquet, joueurs, nb_joueurs);

    free(joueurs);
    return 0;
}

*/