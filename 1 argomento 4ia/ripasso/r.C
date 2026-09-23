#include <stdio.h>

#define DIM 5
int main (){
    int altezza[DIM];

    for(int i = 0; i < DIM; i++){
        altezza [i] = 0;
    }

    for (int i = 0; i < DIM; i++){
        printf("\ninserisci il valore \n");
        scanf("%d \n", & altezza[i]);
        printf("[%d]= %d \n", i, altezza[i]);
    }

}