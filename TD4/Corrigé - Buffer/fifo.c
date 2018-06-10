#include <stdio.h>
#include "fifo.h" 


int enfiler(char nv_val, char t[], int *iqueue, int *nb_elem){

  int retour;

  if(*nb_elem == TAILLE) {
    retour = ERREUR_PLEINE;
  } else {
    t[*iqueue] = nv_val;
    (*iqueue) = ((*iqueue) + 1 )%TAILLE;
    (*nb_elem)++;
    retour = OK;
  }
  return retour;
}

int defiler(char t[], int *itete, int *nb_elem, char *tete_val){

  int retour = OK;

  if(*nb_elem == 0) {
    retour = ERREUR_VIDE;
  } else {
    *tete_val = t[*itete];
    (*itete) = ((*itete) + 1 )%TAILLE;
    (*nb_elem)--;
    retour = OK;
  }

  return retour;
}

void creer_file(char t[], int *itete, int *iqueue, int *nb_elem){

  int i;

  for(i = 0 ; i < TAILLE; i++) {
    t[i] = 0;
  }

  *itete = 0;
  *iqueue = 0;
  *nb_elem = 0;

  return;
}
