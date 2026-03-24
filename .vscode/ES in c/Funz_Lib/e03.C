#include <stdio.h>
#include "mialib.C"


int main(){
    int num = 55;
    printf("Prossimo primo%d: %d\n", num, nextPrimo(num));
    printf("Primo precendente a %d: %d\n", num, prevPrimo(num));
    printf("I primi 10 numeri primi successivi a %d sono: ", num);
    vnp(num, 10);
    return(0);
}