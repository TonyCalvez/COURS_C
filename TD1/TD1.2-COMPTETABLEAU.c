#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int i = 0; 
	char mot[] = "Joyeux Noel";
	for (i=0; mot[i]!='\0'; i++); 
	printf("Les nombre de caractère est de %d\n",i);
}

