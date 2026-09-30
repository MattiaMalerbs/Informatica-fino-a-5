#include <stdio.h>
#include "lib_mat.c"

#define DIM 100

int main() {
    int vett[DIM];

    caricaVettore(vett, DIM, 1, 100000);
    stampaVettore(vett, DIM);
    printf("\n");
    printf("valore medio: %.2f\n", mediaVettore(vett, DIM));
    

    return 0;
}