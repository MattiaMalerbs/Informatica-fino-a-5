#include <stdio.h>
#include "lib_mat.c"

#define DIM 10

int main() {
    int vett[DIM];
    int i;
    int tmp;

    caricaVettore(vett, DIM, 1, 100);
    stampaVettore(vett, DIM);
    printf("\n");
    printf("valore medio: %.2f\n", mediaVettore(vett, DIM));

    i = 7;
    tmp = getValoreAt(vett, DIM, i);
    if(tmp != -1)  
        printf("valore alla cella di indice %d: %d\n", i, tmp);
    else
        printf("sbagliato \n");

    if(stampaSubArray(vett, DIM, 5, 8)){
        printf("bravo");
    }
    else{
        printf("non ci siamo");
    }
    

    return 0;
}