#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lib.h"
#include "lib.c"

#define DIM 15

int main () {

    int max;
    int vet[DIM];       // array di 10 elementi interi indicizzati da 0 a 9.
    int i;              // variabile tipica per lo scorrimento di un vettore.
    int tmp;
    int src;
    int sost;


    /*
    srand(time(NULL));
    // init di un vettore con valori casuali tra 1 e 10
    for(i=0; i<DIM; i++){
        printf("Indice i: %d\n", i);
        vet[i] = 1 + rand()%10;
    }

    // stampo il vettore per vedere i valori assegnati
    for(i=0; i<DIM; i++){
        printf("%3d ", vet[i]);
    }
    printf("\n");
    */

    initVettore(vet, DIM);      // chiamo la funzione di inizializzazione del vettore.
    stampaVettore(vet, DIM);    // chiamo la funzione di stampa a video del vettore.
    printf("\n\n");

    max = stampaValoreMax(vet, DIM);
    printf("\n IL valore massimo è %d \n", max);

    richiedival(vet, DIM);

    printf("\nInserisci il valore da ricercare (src): ");
    scanf("%d", &src);
    printf("Inserisci il valore sostitutivo (sost): ");
    scanf("%d", &sost);

    int numSostituzioni = ricercaSostituisci(vet, DIM, src, sost);

    printf("\nVettore aggiornato: ");
    stampaVettore(vet, DIM);

    return 0;

}