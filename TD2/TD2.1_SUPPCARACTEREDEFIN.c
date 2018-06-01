#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int nbcarac = 0;
    char mot[] = "  Joyeux Noel!";
    nbcarac = chlong(mot);
    printf("Taille de la chaine : %d\n", nbcarac);
    return 0;
}

int chlong(char ch[]){
	int i=0;
	while (ch[i] != '\0'){
		i++;
	}
return i;
}