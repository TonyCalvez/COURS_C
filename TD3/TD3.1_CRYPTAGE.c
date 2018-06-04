#include <stdio.h>
#include <stdlib.h>

#define clef 0

void entreevaleur(){
	char lettre;
    printf("Entrez une lettre: ");
    scanf("%c", &lettre);  
}

void affichernbascii(char lettre){
    printf("La valeur ASCII de %c est : %d \n", lettre, lettre);
}

int c2m (char x){
	return (x = (((x-97+clef)%26)));
}

char m2c(char x){
	return (x = (((x+clef)%26)+97));
}

void testC2M2C(char lettre){
	affichernbascii(lettre);
	printf("Le charactere devient: %d \n", c2m(lettre)); 
	printf("Le charactere redevient: %c \n", m2c(c2m(lettre))); 
}

char addc(char x, char y){
	return m2c(c2m(x)+c2m(y));
}

int main(int argc, char *argv[]) {
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	for (int i=0;(alphabet[i]!='\0');i++){
		testC2M2C(alphabet[i]);
	}

	printf("%c \n", addc('a', 'b'));
    
    return 0;
}