#include <stdio.h>
#include "lib.stringa.c"

#define DIM 20

int main(){
    char parola[DIM];
    int i;

    initStringa(DIM,parola);
    printf("ins par     ");
    scanf("%s", parola);
    printf("\n");
    printf("paralcont       ");
    stampaContrario(parola);

    printf("\n\n");
    printf("lettera 'a' presente:%d\n", contaCarattere(parola, 'a'));
    printf("\n\n");
    contaInteroAlfabeto(parola);

    return 0;
}