#include <stdlib.h>
#include <stdio.h>
//#include "chaines.h"
#define MAXCHAR 100

/* Equivalent dans string.h : strdup */
char * chdup(char chSrc[]) {
  char *chDup = malloc(sizeof(char)*MAXCHAR);
  int i = 0, j = 0;
  while (chSrc[i] == ' ') i++;
  while (chSrc[i] != '\0') {
    chDup[j] = chSrc[i];
    j++; i++;
  }
  chDup[j] = '\0';
  return chDup;
}

char * chconcat(char chHello[], char ch2[]) {

  char * chConc = malloc(sizeof(char)*MAXCHAR);
  int i = 0, j = 0; 
  while (chHello[i] != '\0') {
    chConc[i] = chHello[i];
    i++;
  }
  
  while (ch2[j] != '\0') {
    chConc[i] = ch2[j];
    i++; j++;
  }
  chConc[i] = '\0';
  return chConc;
}

int chmotif(char chAbra[], char chMotif[]) {

  int nbmotifs = 0;
  int i = 0, j=0, m = 0;
  int start = 0;
  while (chAbra[i] != '\0') {
    m = 0; 
    /* Stocker le debut de la chaine d'ou on commence la recherche*/
    start = i;
    while (chMotif[m] != '\0' && chAbra[i] == chMotif[m]) {
      i++;
      m++;
    }
    /* Soit on a trouve le motif */
    if (chMotif[m] == '\0') {
      nbmotifs++;
    }
    /* Soit on l'a pas trouve, on revient au depart + 1 */
    else {
      i = start+1;
    }
  }
  return nbmotifs;
}

