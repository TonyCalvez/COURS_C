#include <stdio.h>
#include <stdlib.h>

int chlong(char ch[]){
	int i=0;
	while (ch[i] != '\0'){
		i++;
	}
return i;
}

char *chdup(char ch[]){
int i = 0;
int j = 0;
char motvide[20]={'\0'};
for (i=0; ch[i]==' '; i++);
for (i=0; i==19; i++){
		motvide[j]=ch[i];	
		j++;
	} 
return motvide;
}

int main(int argc, char *argv[]) {
	int nbcarac = 0;
    char mot[] = "  Joyeux Noel!";
    char motsansesp[20]={'\0'};
    nbcarac = chlong(mot);
    printf("Taille de la chaine : %d\n", nbcarac);
    motsansesp = chdup(mot)
    printf("%s\n", motsansesp);
    return 0;
}

