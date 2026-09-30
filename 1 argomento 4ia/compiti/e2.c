#include <stdio.h>

#define DIM 5   

int diagSum(int M[][DIM], int n) {
    int i, sommaP = 0, sommaS = 0;
    for (i = 0; i < n; i++) {
        sommaP += M[i][i];        
        sommaS += M[i][n-1-i];    
    }
    return sommaP == sommaS;
}

int main(void) {
    int i, j;
    int M[DIM][DIM];

    printf("Inserisci %d elementi:\n", DIM * DIM);
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            scanf("%d", &M[i][j]);

    if (diagSum(M, DIM))
        printf("Le somme delle due diagonali sono uguali.\n");
    else
        printf("Le somme delle due diagonali sono diverse.\n");

    return 0;
}