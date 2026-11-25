#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

typedef struct{
    int base;
    int altezza;
}shape;

int main (){

    shape x;
    shape vectorshape[DIM];
    srand(time(NULL));

    x.altezza=10;
    x.base=5;

    if(x.altezza==x.base){
        printf("ho in mano un quadrato e la sua area è:%d \n", (x.altezza*x.base));
    }
    else{
        printf("ho in mano un rettangolo e la sua area è:%d \n", (x.altezza*x.base));
    }

    //utilizzo vettore che variabile

    for(int i = 0; i<DIM; i++){
        vectorshape[i].altezza = 1+rand()%20;
        vectorshape[i].base = 1+rand()%20;
    }

    return 0;
}