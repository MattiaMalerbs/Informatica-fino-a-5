#include <stdbool.h>

void caricaVettore(int _v[], int _dim, int _min, int _max);
//carica un vet con val compresi tra min e max

///

//stampa vet
void stampaVettore(int _v[], int _dim);

///

//media vet
float mediaVettore(int _v[], int _dim);

///

//restituisci il val nella posizione indicata

int getValoreAt(int _v[], int _dim, int _index);

///

//sanpa a video il sotto array identifivato tra index1 e index2

bool stampaSubArray(int _v[], int _dim, int _index1, int _index2);

///

//carica matrice con val random

void caricaMatrice(int row, int cols, int m[row][cols]);

///

//stampa matrice

void stampaMatrice(int row, int cols, int m[row][cols]);

///

//Ordina un vettore in modo crescente o decrescente a scelta dell'utente

void ordinaVettore(int _v[], int _dim, int _mode);

///

//Carica una matrice con 0/1 alternati

void caricaMatriceScacchiera(int _rows, int _cols, int _m[_rows][_cols]);