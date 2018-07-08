// Variable C -> Affichage: %C et Pointeur de la Variable / Adresse de la Variable : &C -> Stockage dans char * ptr -> Affichage: %p
// Scanf / Printf -> %s (string) : tab ; %d (digit) : int ; %c (char) : char
// Scanf scanf("%s", &p.nom);

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *p_fichier; /* pointeur sur fichier*/
    char nom_fichier[20], nom_personne[20];
     int  i, nbr_enregistrements;
     /* 1ère étape : Création et remplissage du fichier */
     printf("Quel est le nom du fichier à créer ? ");
     scanf("%s", nom_fichier);

     /* w: write   r: read    a: append*/
     p_fichier = fopen(nom_fichier, "w");
     if (p_fichier == NULL) {
        printf("Erreur de création du fichier \n");
        exit(-1);  // Abandonner le programme
     }

     printf("Nombre de personnes à stocker ? : ");
     scanf("%d", &nbr_enregistrements);

     for (i = 0; i<nbr_enregistrements; i++) {
        printf("Entrez le nom de la personne : ");
        scanf("%s", nom_personne);
        fprintf(p_fichier, "%s\n", nom_personne);
     }
     fclose(p_fichier);

     /* 2ème étape : Lecture et affichage du fichier */
     p_fichier = fopen(nom_fichier,"r"); /* read */
     if (p_fichier == NULL) {
        printf("\aErreur d'ouverture sur le fichier \n");
        exit(-2); // Abandonner le programme
     }

     while (!feof(p_fichier)) {
        fscanf(p_fichier, "%s ", nom_personne);
        printf("Nom : %s\n", nom_personne);
     }
     fclose(p_fichier);

     return 0;
}
