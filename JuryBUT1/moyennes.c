#include "moyennes.h"
#include <stdio.h>


void lire_moyennes(const char *nom_fichier, moyPromo *promo) {
    FILE *file = fopen(nom_fichier, "r");


    fscanf(file, "%d", &promo->nb_etudiants);
    fscanf(file, "%d", &promo->nb_UE);

    // On Alloue de la mémoire pour les étudiants
    promo->etudiants = (moyEtu *)malloc(promo->nb_etudiants * sizeof(moyEtu));
  

    for (int i = 0; i < promo->nb_etudiants; i++) {
        // on lit  le prénom et le nom de l'étudiant
        fscanf(file, "%s %s", promo->etudiants[i].prenom, promo->etudiants[i].nom);

        //  On Alloue la mémoire pour les moyennes de l'étudiant
        promo->etudiants[i].moyennes = (float *)malloc(promo->nb_UE * sizeof(float));

        for (int j = 0; j < promo->nb_UE; j++) {
            fscanf(file, "%f", &promo->etudiants[i].moyennes[j]);
        }
    }

    fclose(file);
}


