#include <stdlib.h> 
#include <stdio.h>
#include <string.h>  

typedef struct {
    char prenom[100]; // prenom de l'étudiant avec une limite de 100 caractères
    char nom[100]; // nom de l'étudiant avec une limite de 100 caractères
    float *moyennes;  // Tableau dynamique des moyennes pour un etudiant
    int nbUEvalide; // Nombre d'UE validées
    char decision; // Décision du jury
} moyEtu;

typedef struct {
    int nb_etudiants; //correspond à 8 dans le fichier moyennesUE.txt
    int nb_UE; //correspond à 6 dans le fichier moyennesUE.txt
    moyEtu *etudiants; // Tableau dynamique des moyennes des étudiants
} moyPromo;


void lire_moyennes(const char *nom_fichier, moyPromo *les_moyennes ); // fonction qui permet de lire les moyennes dans un fichier 

void decisionJury(moyPromo *les_moyennes); // fonction qui permet de prendre une décision pour chaque étudiant

void afficher_decisions_jury(moyPromo *les_moyennes); // fonction qui permet d'afficher les décisions du jury
void freeMemory(moyPromo *les_moyennes); // fonction qui permet de libérer la mémoire allouée dynamiquement