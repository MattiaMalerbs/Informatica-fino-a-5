#include <stdio.h>
#include "lib_mat.c"

#define DIM 10
#define RIGHE 5
#define COLONNE 5

int main (){
    int matrix[RIGHE][COLONNE];


    caricaMatrice(RIGHE, COLONNE, matrix);
    stampaMatrice(RIGHE, COLONNE, matrix);


    return 0;
}