#include <stdio.h>
#include <stdlib.h>
#include "lib_verifica.h"

void riempiVettoreCasuale(int _n, int _v[_n], int _min, int _max) {
    for (int i = 0; i < _n; i++)
        _v[i] = rand() % (_max - _min + 1) + _min;   // numero tra min e max
}

void stampaVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _v[i]);
    printf("\n");
}

void riempiMatriceCasuale(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = rand() % (_max - _min + 1) + _min;
}

void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++)
            printf("%d\t", _m[i][j]);
        printf("\n");
    }
}

int calcolaSommaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    _rows;
    int somma = 0;
    for (int j = 0; j < _cols; j++)
        somma += _m[_riga][j];
    return somma;
}

int calcolaSommaVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _v[i];
    return somma;
}

int trovaVetinMat(int _rows, int _cols, int _m[_rows][_cols], int _n, int _v[_n]){

    int i,j,n;
    int cnt = 0;
    for(n=0;n<_n;n++){
        for(i=0;i<_rows;i++){
            for(j=0;j<_cols;j++){
                if(_v[n]==_m[i][j]){
                    cnt++;
                    printf("\nè uguale l'elemento: %d con quell in posizione: %d,%d\n ", _v[n], i,j);
                }
            }
        }
    }
    return cnt;
}

int trovaVetinMat_pt2(int _rows, int _cols, int _m[_rows][_cols], int _n, int _v[_n]){

    int i,j,n;
    int cnt = 0;
    for(n=0;n<_n;n++){
        for(i=0;i<_rows;i++){
            for(j=0;j<_cols;j++){
                if(_v[n]==_m[i][j]){  
                    cnt ++;
                    printf("il numero di valori uguali nella riga %d è di: %d \n", i, cnt);
                }
            }
        }
    }
    return cnt;
}