#include <stdio.h>
#include <stdlib.h>
#include "source/fifo.h"

int main(int argc, char *argv[]) {
	char tab[5]={'\0'};
	unsigned int itete = 0;
	unsigned int iqueue = 0;
	unsigned int nb_elem = 5;

	creer_file(&tab, itete, iqueue, nb_elem);

    return 0;
}

void creer_file(char *itab[], unsigned int itete, unsigned int iqueue, unsigned int nb_elem){

	**itab = malloc ((nb_elem * sizeof(int)));

	for (unsigned int i=0; i<nb_elem; i++){
		*itab[i]=0;
	}
}

