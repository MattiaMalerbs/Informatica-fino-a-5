#include <stdio.h>
#include "lib.c"

#define DIM 3

int main(){
    Shape figura;
    Shape vectorShape[DIM];

    //inputshape(&figura);
    //printf("base:%d, altezza:%d \n", figura.b, figura.h);
    //printshape(figura);

    for(int i = 0; i<DIM; i++){
        inputshape(&figura);
    }
    for(int i = 0; i<DIM; i++){
        printshape(figura);
    }


}