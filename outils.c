#include "Projet.h"

// Vide le buffer clavier pour éviter les erreurs de saisie
void vide_buffer() {
    while (getchar() != '\n');
}