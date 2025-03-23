#include <stdlib.h> 
#include <stdio.h>
#include <string.h>  

typedef struct {
    char prenom[100];
    char nom[100];
    float *moyennes;  // Tableau dynamique des moyennes
} moyEtu;

typedef struct {
    int nb_etudiants;
    int nb_UE;         
    moyEtu *etudiants; // Tableau dynamique des étudiants
} moyPromo;


void lire_moyennes_allocDyn(FILE *nom_fichier, moyPromo *les_moyennes );
