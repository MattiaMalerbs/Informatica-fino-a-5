#include <stdio.h>

#define DIM 5

int scacchieraM(int M[][DIM], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (M[i][j] != 0 && M[i][j] != 1)
                return 0;
            if (j < n-1 && M[i][j] == M[i][j+1])
                return 0;
            if (i < n-1 && M[i][j] == M[i+1][j])
                return 0;
        }
    }
    return 1;
}

int main(void) {
    int i, j;
    int M[DIM][DIM];

    printf("Matrice:\n");
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            scanf("%d", &M[i][j]);

    if (scacchieraM(M, DIM))
        printf("Si\n");
    else
        printf("No\n");

    return 0;
}