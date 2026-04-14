#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10//numero elementi quanti ne genera

int main(){
    int vet [DIM]; //array di 10 elementi interi indicizzati da 0 a 9
    int i;        //variabile tipica per lo scorrimento di un vettore
    int tmp;
    int cnt = 0;
    //init di un vettore con val casuali tra 1 e 10
    srand(time(NULL));

    for(i=0; i<DIM; i++){
        printf("indice i: %d\n", i);
        vet[i] = 1 + rand()%10;
    }

    //stampo il valore per vedere quelli assegnati
    for(i=0; i<DIM; i++){
        printf("%3d  ", vet[i]);
    }
    printf("\n");

    //raddoppio i val del vettore
    for(i=0; i<DIM; i++){
        tmp = vet[i];
        tmp = tmp * 2;
        vet[i] = tmp;
    }
    for(i=0; i<DIM; i++){
        printf("%3d  ", vet[i]);
    }
    printf("\n");

    //visualizza solo i valori pari nel vettore
    
    for(i=0; i<DIM; i++){
        if(vet [i] %2 == 0){
            printf("%d  ", vet [i]);
        }
    }
    printf("\n");

    // visualizza i valori contenuti nelle celle

    for(i=0; i<DIM; i++){
        if (i % 2 == 0){
            printf("%3d ", vet[i]);
        }
        else{
            printf("*** ");
        }
    }
    return 0;
}