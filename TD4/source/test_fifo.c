#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#define TESTOK 0
#define TESTERR 1


int testOK_enfiler() {
  /* Variables definissant la file */
  char t[TAILLE];
  int tete, queue, nb_elem;
  /* Initialisation file */
  creer_file(t, &tete, &queue, &nb_elem);

  enfiler('y', t, &queue, &nb_elem);
  enfiler('z', t, &queue, &nb_elem);
  
  /* Appel de test */
  if (nb_elem == 2 && queue == 2 && tete == 0)
    return TESTOK;
  else {
    printf("*** [testOK_enfiler] indice de queue, de tete, et/ou nb_elem incorrect!\n");
    printf("attendu: queue == 2, tete == 0, nb_elem == 2\n");
    printf("recu: queue == %d, tete == %d, nb_elem == %d\n\n", queue, tete, nb_elem);
    return TESTERR;
  }
}

int testERR_enfiler() {
  /* Variables definissant la file */
  int retour_enfiler;
  int i = 0;
  char t[TAILLE];
  int tete, queue, nb_elem;
  /* Initialisation file */
  creer_file(t, &tete, &queue, &nb_elem);
  for (i = 0; i < TAILLE; i ++) {
    enfiler(i+'a', t, &queue, &nb_elem);
  }

  /* Appel de test */
  retour_enfiler = enfiler('z', t, &queue, &nb_elem);
  if (retour_enfiler == ERREUR_PLEINE && tete == queue && nb_elem == TAILLE)
    return TESTOK;
  else 
    return TESTERR;
}

int testOK_circulaire() {
  /* Variables definissant la file */
  int i = 0;
  char t[TAILLE];
  int tete, queue, nb_elem;
  char tete_val;
  /* Initialisation file */
  creer_file(t, &tete, &queue, &nb_elem);
  for (i = 0; i < TAILLE; i ++) {
    enfiler((i+'a'), t, &queue, &nb_elem);
  }
  /* Appel de test */
  defiler(t, &tete, &nb_elem, &tete_val);
  defiler(t, &tete, &nb_elem, &tete_val);
  enfiler('Y', t, &tete, &nb_elem);
  enfiler('Z', t, &tete, &nb_elem);  
  /* Test s'il n'y a pas depassement de borne de tableau */
  if (queue < TAILLE) {
    return TESTOK;
  }
  else
    return TESTERR;
}

int testOK_defiler() {
  char t[TAILLE];
  int tete, queue, nb_elem;
  char tete_val;
  /* Initialisation file */
  creer_file(t, &tete, &queue, &nb_elem);
  enfiler('a', t, &queue, &nb_elem);
  enfiler('b', t, &queue, &nb_elem);
  enfiler('c', t, &queue, &nb_elem);
  enfiler('d', t, &queue, &nb_elem);
  
  /* Appel de test */
  defiler(t, &tete, &nb_elem, &tete_val);
  defiler(t, &tete, &nb_elem, &tete_val);
  if (tete == 2 && queue == 4 && nb_elem == 2 && tete_val == 'b')
    return TESTOK;
  else {
    printf("*** [testOK_defiler] indice de queue, de tete, et/ou nb_elem incorrect!\n");
    printf("attendu: queue == 4, tete == 2, nb_elem == 2, tete_val = 'b'\n");
    printf("recu: queue == %d, tete == %d, nb_elem == %d, tete_val = '%c'\n\n", queue, tete, nb_elem, tete_val);
    return TESTERR;
  }

}

int testERR_defiler() {
  int retour_defiler;
  char t[TAILLE];
  int tete, queue, nb_elem;
  char tete_val;

  /* Initialisation file */
  creer_file(t, &tete, &queue, &nb_elem);

  /* Appel de test */
  retour_defiler = defiler(t, &tete, &nb_elem, &tete_val);
  if (retour_defiler == ERREUR_VIDE && tete == 0 && queue == 0 && nb_elem == 0)
    return TESTOK;
  else
    return TESTERR;
     
}

/*

int testOK_la_tete() {
  int retour_tete;
  char t[TAILLE];
  int tete, queue, nb_elem;
  char tete_val;
  // Initialisation file 
  creer_file(t, &tete, &queue, &nb_elem);
  enfiler('a', t, &queue, &nb_elem);
  enfiler('b', t, &queue, &nb_elem);
  enfiler('c', t, &queue, &nb_elem);
  
  // Appel de test 
  retour_tete = la_tete(t, tete, nb_elem, &tete_val);
  if (tete == 0 && queue == 3 && nb_elem == 3 && tete_val == 'a')
    return TESTOK;
  else
    return TESTERR;
}


int testERR_la_tete() {
  int retour_tete;
  char t[TAILLE];
  int tete, queue, nb_elem;
  char tete_val;
  // Initialisation file 
  creer_file(t, &tete, &queue, &nb_elem);
  
  // Appel de test 
  retour_tete = la_tete(t, tete, nb_elem, &tete_val);
  if (retour_tete == ERREUR_VIDE)
    return TESTOK;
  else
    return TESTERR;

}
*/


int main() {
  int nb_tests_reussis = 0;
  int nb_tests_totaux = 5;
  if (testOK_enfiler() == TESTOK) {
    printf("TestOK enfiler                : reussite\n");
    nb_tests_reussis += 1;
  }
  else  {
    printf("TestOK enfiler                : echec\n");
  }

  if (testERR_enfiler() == TESTOK) {
    printf("TestERR enfiler (file pleine) : reussite\n");
    nb_tests_reussis += 1;
  }
  else  {
    printf("TestERR enfiler (file pleine) : echec\n");
  }
  
  if (testOK_defiler() == TESTOK) {   
    printf("TestOK defiler                : reussite\n");
    nb_tests_reussis += 1;
  }
  else  {
    printf("TestOK defiler                : echec\n");
  }

  if (testERR_defiler() == TESTOK) {
    printf("TestERR defiler (file vide)   : reussite\n");
    nb_tests_reussis += 1;
  }
  else  {
    printf("TestERR defiler (file vide)   : echec\n");
  }

  if (testOK_circulaire() == TESTOK) {
    printf("Test circulaire (queue<TAILLE) : reussite \n");
    nb_tests_reussis += 1;        

  }
  else  {
    printf("Test circulaire (queue<TAILLE) : echec \n");
  }

  printf("-------------------------------------\n");
  printf("\nNombre de tests reussis : %d sur %d\n", nb_tests_reussis, nb_tests_totaux);
  return 0;
}
