FLIP 7 

 

 

À propos  

Flip 7 est un jeu de cartes mêlant hasard, stratégie et prise de risque. Le principe est simple : retourner des cartes pour accumuler des points sans jamais obtenir deux fois le même numéro. Plus les joueurs prennent de risques, plus ils peuvent gagner gros… ou tout perdre.  

 

Prérequis 

GCC (compilateur C) : Permet de compiler et exécuter le projet en langage C. 

Make : Outil permettant d’automatiser la compilation du projet. 

Git : Nécessaire pour cloner et gérer le dépôt du projet. 

Un terminal de commandes : Permet d’exécuter les commandes de compilation et de lancement du jeu. 

Un système compatible (Windows, Linux ou macOS) : Le projet doit être compilé sur un environnement supportant le langage C. 

 

 

Installation 

git clone https://github.com/user/flip7.git 

cd Flip7-main 

make 

./flip7 

Voici les commandes qui permettent de cloner le projet, compiler les fichiers source et lancer le jeu. 

 

Utilisation 

1) Lancement du programme : 

./flip7 

Cette commande démarre le programme. 

 

2) Déroulement d’une partie : 

Le premier joueur choisit le nombre de participants.  

À chaque tour, un joueur peut :  

tirer une nouvelle carte,  

ou arrêter son tour pour sécuriser ses points.  

Si un joueur obtient deux fois le même numéro, il perd les points du tour.  

La partie continue jusqu’à ce qu’un joueur atteigne le score de victoire. 

 

3) Nettoyer les fichiers compilés : 

make clean

Cette commande permet de supprimer les fichiers compilés ainsi que l'exécutables.






Aperçu du jeu 


<img width="598" height="450" alt="image" src="https://github.com/user-attachments/assets/372a9938-3402-43d5-b25b-7dc856337adb" />



Construit avec 

 

C (langage de programmation) 
Langage principal utilisé pour développer la logique du jeu Flip 7 (gestion des cartes, règles, affichage).  

Standard Library C (libc) 
Utilisée pour les entrées/sorties, la gestion mémoire et les fonctions de base du programme. 

 

Documentation 

C Reference (cppreference) — Référence complète du langage C (syntaxe, fonctions, comportement)  

GCC Documentation — Documentation du compilateur utilisé pour construire le projet  

GNU Make Manual — Guide pour comprendre et utiliser le Makefile 

 

 

 

Projet réalisé par : 

Damien Rouge 

Milan Pfeuty 

Jules Picard
