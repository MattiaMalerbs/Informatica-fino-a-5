#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lib_mat.h"

/////

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

/////

void caricaVettore(int _v[], int _dim, int _min, int _max){
    int i;
    srand(time(NULL));
    
    for(i = 0; i< _dim; i++){
        _v[i] = _min + rand()%(_max - _min + 1);
    }
}

/////

void stampaVettore(int _v[], int _dim){
    int i;
    for(i=0;i<_dim;i++){
        printf("%d  ", _v[i]);
    }
}

/////

float mediaVettore(int _v[], int _dim){
    int totale;
    int i;
    for(i=0;i<_dim;i++){
        totale = totale + _v[i];
    }
    return ((float) totale)/_dim;
}