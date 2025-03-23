#include <stdio.h>
#include <stdlib.h>
#include "moyennes.h"

int main(int argc, char *argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 2) {
        printf("Utilisation : jury nom_fichier_moyennes\n");
        return 1;
    }

    // Récupération du nom du fichier
    const char *nom_fichier = argv[1];
    printf("Nom du fichier contenant les moyennes : %s\n", nom_fichier);

    // Déclaration d'une structure pour stocker les moyennes
    moyPromo les_moyennes;
    // Lecture du fichier 
    lire_moyennes(nom_fichier, &les_moyennes);
    decisionJury(&les_moyennes);
    afficher_decisions_jury(&les_moyennes);

    //libération de la mémoire 
    freeMemory(&les_moyennes);

       
    return 0;
}
