#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int i = 0; 
	int j = 0;
	char mot[] = "    Joyeux Noel";
	char motvide[20];
	for (i=0; mot[i]==' '; i++);
	for (i=0; i==19; i++){
		motvide[j]=mot[i];	
		j++;
	}  
	printf("%s", motvide[]);
	return 0;
}

