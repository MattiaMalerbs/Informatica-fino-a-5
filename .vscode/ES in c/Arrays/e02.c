#include <stdio.h>
#include "lib.c"

#define DIM 10

int main(){
    int vettore[DIM]; // vettore di dim elementi
    int i;

    srand(time(NULL));

    initvettore(vettore, DIM);      //chiama funzioni
    stampavettore(vettore, DIM);

    return 0;
}