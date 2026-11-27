#include <stdio.h>
#include <string.h>
#include "lib.h"

void inputshape(Shape* _x){

    int base;
    int altezza;
    char junk;

    printf("inserisci una base: ");
    scanf("%d", &base);
    junk = getchar();

    printf("inserisci un altezza: ");
    scanf("%d", &altezza);
    junk = getchar();

    (*_x).b = base;
    (*_x).h = altezza;
}

void printshape(Shape x){
    printf("base:%d, altezza:%d \n", x.b, x.h);
}