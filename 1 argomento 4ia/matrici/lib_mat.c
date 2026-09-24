#include <stdio.h>
void printMatrix(int rows, int cols, int m [rows][cols]){
    for(int i = 0; i <rows; i++){
        for(int j=0; j<rows; j++){
            if(j==0)
                printf("[");
            printf("%3d ", m[i][j]);
            if(j==cols-1)
                printf("]");
        }
        printf("\n");
    }
}