#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib_verifica.c"

#define rows 5  
#define cols 5
#define dim 5

int main(void) {

    //int n = 5;
    int v[dim];                                        
    riempiVettoreCasuale(dim, v, 1, 20);

    printf("Vettore:   ");  stampaVettore(dim, v);

    //int rows = 5;
    //int cols = 5;
    int m[rows][cols];
    int riga = 0;
    int somvet = 0;
    int somrig = 0;
    int cnt = 0;
    int vetinmat = 0;
    int vetinmat_2 = 0;
    riempiMatriceCasuale(rows, cols, m, 1, 20);
    somvet = calcolaSommaVettore(dim,v);

    printf("Matrice:\n");
    stampaMatrice(rows, cols, m);
    
    //printf("Somma:     %d\n", calcolaSommaVettore(n, v));
    for(riga = 0; riga<rows; riga++){

        somrig = calcolaSommaRiga(rows, cols, m, riga);
        if(somrig > somvet){
            cnt++;
            somrig = 0;
        }
        else{
            somrig = 0;
        }
    }
    printf("le righe maggiori sono: %d   \n", cnt);

    vetinmat =trovaVetinMat(rows,cols, m, dim, v);

    printf("\n %d \n", vetinmat);
    printf("\n\n\n");

    vetinmat_2 =trovaVetinMat_pt2(rows,cols, m, dim, v);

    printf("\n numero di quanti valori sono uguali nel vettore e matrice per riga: %d \n", vetinmat_2);

    return 0;
}