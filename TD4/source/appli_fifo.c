#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

/*---------------------------------------------------------------- 
  Implantation du TAD FILE à l'aide d'un tableau : gestion
  circulaire du tableau à l'aide de deux indices, un indice
  de lecture et un indice d'écriture.
  On peut placer dans la file au plus DIM élements 
  ----------------------------------------------------------------*/

int main() {

  
  char tab[TAILLE];
  int curseur_lecture;   /* la prochaine case a lire (0 a TAILLE-1)   */
  int curseur_ecriture;  /* la prochaine case a écrire (0 a TAILLE-1) */
  int nb;  /* nombre d'elements dans la file */
  char val; /* valeur extraite en defilant */

  int retour_operation; /* retour des appels des fonctions de manipulation de file*/
  int operation = 0; /* operation choisie par l'utilisateur */
  int retour_scan; 

  creer_file(tab, &curseur_lecture, &curseur_ecriture, &nb);

  do {
    printf("\nterminer    (0) \n");
    printf("initialiser (1) \n");
    printf("enfiler     (2) \n");
    printf("défiler     (3) \n");
    printf("afficher    (4) \n");

    /* boucle de saisie de l'opération à effectuer */
    do {
      printf("\nopération ? \n");
      retour_scan = scanf("%d", &operation);
      while( getchar() != '\n' ) /* empty */;
    } while ( retour_scan != 1 );
   
    printf("opération choisie : %d\n",operation);

    /* traitement de l'opération choisie */
    switch (operation) { 
    case 0 :
      /* Completer */
    case 1 :
      /* Completer */
    case 2 :
      /* Completer */
      /* lecture de la valeur (saisie par l'utilisateur */
    case 3 :
      /* Completer */
    case 4 :
      /* Completer */
    default : printf(" \n\n%d: Opération non conforme\n", operation);
      break; 
    }
  } while (operation != 0);

  return EXIT_SUCCESS;
}
