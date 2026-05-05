#include <stdio.h>
#include "lib.c"

#define DIM 8

int main(){

    int numero;     //varbeile x acquisire val da tastiera
    int bin [DIM];  //array per rappresentare un numero in binario

    char junk;

    //step 1 acquisisci val

    printf("inserisci un val intero: \n");
    scanf("%d", &numero);
    junk = getchar();

    convertiBinario(numero, bin, DIM);
    stampaBinario(bin, DIM);
    printf("\n");
    
    return (0);
}