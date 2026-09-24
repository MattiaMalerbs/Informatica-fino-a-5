#include <stdio.h>
#include "lib_mat.c"
#define DIM 3
int main(void){
    int m[DIM][DIM] = { // bracket inizalization
        {0,1,2},
        {10,11,12},
        {20,21,22}
    };
    printMatrix(DIM, DIM, m);
}