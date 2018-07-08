#include <stdio.h>
#include <stdlib.h>

#define VALUEMAX 100

typedef struct Pile{
    int limite;
    int *tab[];
} pile;

int traitementpile (int valeurdentree) {
    pile p;

    if (p.limite ==VALUEMAX){
        return 1;
    }
    else {
        p.tab[p.limite]=valeurdentree;
        p.limite = p.limite + 1;
        return 0;
    }

}

int main(){
    while(1){
        int d;
        scanf("%d", &d);
        traitementpile(d);
        printf("La pile est de: %d", d);
        printf("Appuyer sur entrée pour continuer");
        getchar();
    }
    return 0;
}

