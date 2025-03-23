#include <stdio.h>
#include <stdlib.h>
#include "moyennes.h"

int main(int argc, char *argv[]) {

    //pour l étape 1 
    /**
     // Vérification du nombre d'arguments
        if (argc != 2) {
            printf("Utilisation : jury nom_fichier_moyennes\n");
            EXIT_FAILURE;
        }
    */
    if (argc < 2 || argc > 3) {
        printf("Utilisation : %s nom_fichier_moyennes [nom_fichier_resultats]\n", argv[0]);
        return 1;
    }

    const char *nom_fichier = argv[1];
    printf("Nom du fichier contenant les moyennes : %s\n", nom_fichier);

    moyPromo les_moyennes; // Structure pour stocker les moyennes
    lire_moyennes(nom_fichier, &les_moyennes); // Lecture des moyennes
    decisionJury(&les_moyennes); // Prise de décision pour chaque étudiant

    // Si un fichier est précisé, on sauvegarde dedans, sinon on affiche à l'écran
    if (argc == 3) {
        sauvegarder_decisions_jury(&les_moyennes, argv[2]);
    } else {
        afficher_decisions_jury(&les_moyennes, stdout);
    }

    freeMemory(&les_moyennes);// Libération de la mémoire allouée dynamiquement 
    EXIT_SUCCESS;
}
