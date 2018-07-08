#include <stdio.h>
#include <stdlib.h>

#define VALUEMAX 5

typedef struct Stockcode{
    int entree[];
    int secret[];
    int final[];
    int rang;

} stockcode;

int traitementpile (int valeurdentree, int nb) {
    stockcode code;

    if (code.rang == VALUEMAX){
        return 1;
    }

    else {
        code.entree[nb] = valeurdentree;

        code.secret[nb] = code.rang;

        code.final[nb]= valeurdentree + code.rang;

        return 0;
    }

}


int main(){
    int d;
    for(int i=0; i<5; i++ ){
        printf("Entrez un nombre:");
        scanf("%d", &d);
        traitementpile (d, i);
        printf()
    }

    return 0;
}

