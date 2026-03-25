#include <stdio.h>
#include <stdbool.h>
#include "mialib.C"

int main(){

    int a = 10;
    int b = 5;

    if(SCA(&a, &b)==true){
        printf("boh bravo");
    }
    else{
        printf("nonono");
    }

    return 0;

}