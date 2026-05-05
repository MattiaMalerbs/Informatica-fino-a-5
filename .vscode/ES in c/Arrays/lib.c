#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initvettore(int _vet[], int _dim){
    int i;
    for(i=0; i < _dim; i++) {
        _vet [i]= 1+ rand()%10;
    }

}

void stampavettore(int _vet[], int _dim){
    int i;
    for(i=0; i < _dim; i++) {
        printf("%3d ", _vet[i]);
    }
}

// funzioni e03.c

 int convertiBinario(int _n, int _v[], int _dim){

    int i;
    if(_n<pow(2, _dim)){

        for(i=0;i<_dim;i++){
        _v[i]=_n%2;     //salvo il resto della divisione x 2
        _n=_n/2;        //divido il num restante x 2 x seguire la scomposizione
    }
    return 1;
    }

    else{
        return 0;
    } 

 }

  void stampaBinario(int _v[], int _dim){
    int i;
    for(i=_dim -1; i>=0; i--){      //visualizzo il vettore dei bit binari partendo dall'ultima cella fino alla prima
        printf("%d   ", _v[i]);
    }

  }