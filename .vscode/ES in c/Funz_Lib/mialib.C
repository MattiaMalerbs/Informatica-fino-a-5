/*  Contiene il codice C delle diverse funzioni che compongono la mia libreria. */
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "mialib.h"

bool isPrimo(int _n){
    int div;    // variabile per i divisori del numero passato come parametro.
    int cnt;    // contatore per i divisori trovati del numero passato come parametro.

    cnt = 0;
    for(div=1; div<=_n; div++){
        if(_n%div == 0) // ho trovato un divisore! -> incremento il contatore
            cnt++;
    }

    if(cnt<=2)
        return(true);
    else
        return(false);
}

bool isPerfect(int _n){
    int div;
    int somma;
    
    somma = 0;
    div = 1;
    while(div <= _n){
        if(_n%div == 0){
            somma = somma + div;
        }
        div = div + 1;
    }
    
    if(somma == (_n*2))
        return(true);
    else
        return(false);    
}

bool isTernaPitagorica(int _n1, int _n2, int _n3){
    if((_n1*_n1) + (_n2+_n2) == (_n3*_n3))
        return(true);
    else
        return(false);
}

int inputValoreRange(int _min, int _max){
    int valore;

    
    return(valore);
}

int nextprimo(int _val){
    int nextP;
    /*soluzione valida 
    bool primo;
    int div;
    nextP = _val;

    do{
        nextP = nextP + 1;
        primo = true;
        for(div=2; div<nextP; div++){
            if(nextP%div == 0){
                primo = false;
                break;
            }
        }
    }while(primo == false);
    */


    nextP = _val + 1;
    while(isPrimo(nextP) == false){
        nextP = nextP + 1;
    }
    return(nextP);

}

int prevPrimo(int _val){
    int prevP;
    prevP = _val;
    do {
        prevP = prevP - 1;
    } while(!isPrimo(prevP));
    return(prevP);
}

void vnp(int _val, int _n){
    int cnt;
    cnt = 0;
    while(cnt < _n){
        _val = nextprimo(_val);
        printf("%d ", _val);
        cnt++;
    }
}

void rd (int* _n) {
    int tmp;

    tmp = *_n;
    tmp = tmp * 2;
    *_n = tmp;
}

void CAP(int _base, int _altezza, int* _area, int* _perimetro){
    int tmpArea;
    int tmpPerimetro;

    tmpArea= _base * _altezza;
    tmpPerimetro = (_base + _altezza) * 2;

    *_area = tmpArea;
    *_perimetro = tmpPerimetro;
}

bool SCA(int* _a, int* _b){


    if(*_a > *_b){

        int tmp;
        tmp = *_a;
        *_a = *_b;
        *_b = tmp;

        printf("prova1");

        return (true);
    }
    else{
        return (false);
        printf("prova2");
    }


}
