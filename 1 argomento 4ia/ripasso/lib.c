#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lib.h"

void initVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _vet[i] = 1 + rand()%15;
    }
}

void stampaVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d ", _vet[i]);
    }
}

int stampaValoreMax(int _vet[], int _dim){
    int i;
    int max = 0;
    for(i = 0; i < _dim; i++){
        //max = _vet[i];
        if (max < _vet[i]){
            max = _vet[i];
        }
    }
    return max;
}

void richiedival(int vet[], int dim){

    printf("prova");

    int k = 0;
    int n = 0;
    int i;
    int cnt = 0;

    while(k < 1){
        printf("inserici un val tra 25 e 0 \n");
        scanf("%d", &n);

        if(n <= 25 && n >=0){
            k = 10;
            for(i = 0; i < dim; i++){
                if(n == vet[i]){
                    cnt ++;
                }
            }
            printf("apparso; %d \n", cnt);
            
        }
        else {
            printf("riprova ancora \n");
        }
    }
}


int ricercaSostituisci(int v[], int dim, int src, int sost) {
    int contatore = 0;
    for (int i = 0; i < dim; i++) {
        if (v[i] == src) {
            v[i] = sost;   
            contatore++;   
        }
    }
    return contatore;
} 