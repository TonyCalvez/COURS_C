#include <stdio.h>
#include <stdlib.h>

void agedepapa (int *pointeur_age_dans_le_main){
    *pointeur_age_dans_le_main = 45 ;
}


int main(){
    int age = 21;
    int *p_age = NULL;
    printf("mon age est de: %d \n", age); // age->Valeur dans la variable
    printf("l'adresse de mon age est: %p \n", &age); //&a -> Désigne l'adresse de la variable
    p_age=&age;
    printf("l'adresse de mon age est: %d \n", p_age); //&a -> Désigne la variable p_age qui contient l'adresse de la variable
    printf("mon age est de: %d \n", *p_age); // age->Valeur dans la variable

    printf("Age de mon pere stockait dans la variable age : \n");
    agedepapa(&age);
    printf("l'age de mon père est de: %d \n", age); // age->Valeur dans la variable

    return 0;
}

