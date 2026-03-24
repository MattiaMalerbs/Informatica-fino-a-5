#include <stdio.h>
#include "mialib.C"

int main(){

    int a;
    a = 7;
    printf("A: %d\n",a);
    rd(&a);
    printf("A: %d\n",a);


    printf("\n\n\n\n");

    int b = 5;
    int h = 8;
    int ar;
    int p;
    CAP(b, h, &ar, &p);

    printf(" %d %d, area %d, perimetro %d \n", b, h, ar, p);
    return 0;
}
