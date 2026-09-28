#include <stdio.h>

#define DIM 5 

int corniceValoreM(int M[][DIM], int n, int v) {
    int i;
    for (i = 0; i < n; i++) {
        if (M[0][i]   != v ||   
            M[n-1][i] != v ||   
            M[i][0]   != v ||   
            M[i][n-1] != v)     
            return 0;
    }
    return 1;
}

int main(void) {
    int i, j, v;
    int M[DIM][DIM];

    printf("Inserisci %d elementi (matrice %dx%d, per righe):\n", DIM * DIM, DIM, DIM);
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            scanf("%d", &M[i][j]);

    printf("Valore v da verificare sulla cornice: ");
    scanf("%d", &v);

    if (corniceValoreM(M, DIM, v))
        printf("Tutti gli elementi della cornice valgono %d.\n", v);
    else
        printf("Non tutti gli elementi della cornice valgono %d.\n", v);

    return 0;
}