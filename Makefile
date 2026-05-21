all: exec

main.o: main.c
	gcc -c main.c

affiche_joueur.o: affiche_joueur.c
	gcc -c affiche_joueur.c

afficher_main.o: afficher_main.c
	gcc -c afficher_main.c

calcul_score.o: calcul_score.c
	gcc -c calcul_score.c

carte_piochee.o: carte_piochee.c
	gcc -c carte_piochee.c

choix_joueur.o: choix_joueur.c
	gcc -c choix_joueur.c

creer_pioche.o: creer_pioche.c
	gcc -c creer_pioche.c

deroulement_partie.o: deroulement_partie.c
	gcc -c deroulement_partie.c

start.o: start.c
	gcc -c start.c

tour_de_joueur.o: tour_de_joueur.c
	gcc -c tour_de_joueur.c

sauvegarde_joueurs.o: sauvegarde_joueurs.c
	gcc -c sauvegarde_joueurs.c

outils.o: outils.c
	gcc -c outils.c

exec: main.o affiche_joueur.o afficher_main.o calcul_score.o carte_piochee.o choix_joueur.o creer_pioche.o deroulement_partie.o start.o tour_de_joueur.o sauvegarde_joueurs.o outils.o
	gcc main.o affiche_joueur.o afficher_main.o calcul_score.o carte_piochee.o choix_joueur.o creer_pioche.o deroulement_partie.o start.o tour_de_joueur.o sauvegarde_joueurs.o outils.o -o Flip7

clean:
	rm -f *.o
	rm -f Flip7