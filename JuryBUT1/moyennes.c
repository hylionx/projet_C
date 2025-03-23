#include "moyennes.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour lire les moyennes dans un fichier
void lire_moyennes(const char *nom_fichier, moyPromo *les_moyennes) {
    FILE *file = fopen(nom_fichier, "r"); // Ouvre le fichier
    if (file == NULL) {
        printf("Le fichier %s n'a pas pu être ouvert\n", nom_fichier);
        return;  
    }

    printf("Le fichier %s existe\n", nom_fichier);
    fscanf(file, "%d", &les_moyennes->nb_etudiants); // Récupère le nombre d'étudiants
    printf("\nNombre d'étudiants : %d\n", les_moyennes->nb_etudiants);
    fscanf(file, "%d", &les_moyennes->nb_UE); // Récupère le nombre d'UE
    printf("Nombre d'UE : %d\n", les_moyennes->nb_UE);

    // Allocation mémoire pour les étudiants
    les_moyennes->etudiants = (moyEtu *)malloc(les_moyennes->nb_etudiants * sizeof(moyEtu));
    if (les_moyennes->etudiants == NULL) {
        printf("Erreur d'allocation de mémoire pour les étudiants\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < les_moyennes->nb_etudiants; i++) {
        // Lire le prénom et le nom de l'étudiant
        fscanf(file, "%s %s", les_moyennes->etudiants[i].prenom, les_moyennes->etudiants[i].nom);
        printf("\nÉtudiant %d: %s %s\n", i + 1, les_moyennes->etudiants[i].prenom, les_moyennes->etudiants[i].nom);
        printf("Moyennes : ");

        // Allocation mémoire pour les moyennes de l'étudiant
        les_moyennes->etudiants[i].moyennes = (float *)malloc(les_moyennes->nb_UE * sizeof(float));
        if (les_moyennes->etudiants[i].moyennes == NULL) {
            printf("Erreur d'allocation mémoire pour les moyennes de %s %s\n",
                   les_moyennes->etudiants[i].prenom, les_moyennes->etudiants[i].nom);
            fclose(file);
            return;
        }

        for (int j = 0; j < les_moyennes->nb_UE; j++) {
            fscanf(file, "%f", &les_moyennes->etudiants[i].moyennes[j]);
            printf("%.2f ", les_moyennes->etudiants[i].moyennes[j]);

        }
        
    }

    fclose(file);
}

// Fonction pour prendre une décision pour chaque étudiant
void decisionJury(moyPromo *les_moyennes) {
    for (int i = 0; i < les_moyennes->nb_etudiants; i++) {
        int nbUEvalides = 0;

        // Calcul du nombre d'UE validées (moyenne >= 10)
        for (int j = 0; j < les_moyennes->nb_UE; j++) {
            if (les_moyennes->etudiants[i].moyennes[j] >= 10) {
                nbUEvalides++;
            }
        }

        // Attribuer le nombre d'UE validées à l'étudiant
        les_moyennes->etudiants[i].nbUEvalide = nbUEvalides;

        // Attribuer la décision
        if (nbUEvalides >= 4) {
            // Si toutes les UE sont validées, on met 'V*'
            if (nbUEvalides == les_moyennes->nb_UE) {
                les_moyennes->etudiants[i].decision = 'V';  // 'V*' pour toutes validées
            } else {
                les_moyennes->etudiants[i].decision = 'V';  // 'V' pour une majorité validée
            }
        } else {
            les_moyennes->etudiants[i].decision = 'E';  // 'E' pour échec
        }
    }
}

// Fonction générique pour afficher ou sauvegarder les décisions
// ajout du paramètre fichier pour afficher ou sauvegarder dans un fichier pour l'etape 8
void afficher_decisions_jury(moyPromo *les_moyennes, FILE *fichier) {
    for (int i = 0; i < les_moyennes->nb_etudiants; i++) {
        fprintf(fichier, "%s %s ", les_moyennes->etudiants[i].prenom, les_moyennes->etudiants[i].nom);
        
        if (les_moyennes->etudiants[i].decision == 'V') {
            if (les_moyennes->etudiants[i].nbUEvalide == les_moyennes->nb_UE) {
                fprintf(fichier, "V*\n");  // Toutes les UE validées
            } else {
                fprintf(fichier, "V%d\n", les_moyennes->etudiants[i].nbUEvalide);
            }
        } else {
            fprintf(fichier, "E\n");  // Échec
        }
    }
}
// Fonction pour sauvegarder les décisions dans un fichier
void sauvegarder_decisions_jury(moyPromo *les_moyennes, const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    afficher_decisions_jury(les_moyennes, fichier);
    fclose(fichier);
    printf("Les résultats ont été sauvegardés dans %s\n", nom_fichier);
}

// Fonction pour libérer la mémoire allouée dynamiquement
void freeMemory(moyPromo *les_moyennes) {
    for (int i = 0; i < les_moyennes->nb_etudiants; i++) {
        free(les_moyennes->etudiants[i].moyennes);  // Libération des moyennes de chaque étudiant
    }
    free(les_moyennes->etudiants);  // Libération de la mémoire des étudiants
}