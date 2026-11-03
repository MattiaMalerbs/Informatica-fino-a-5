/*
 * main.c - Esempio d'uso della libreria funzioni.h
 * Compilare con:  gcc -std=c99 -Wall main.c funzioni.c -o programma
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main(void) {
    srand(time(0));                                  // una sola volta, all'inizio

    /* ----- VETTORI ----- */
    int n = 8;
    int v[n];                                        // array a lunghezza variabile (C99)
    riempiVettoreCasuale(n, v, 1, 20);

    printf("Vettore:   ");  stampaVettore(n, v);
    printf("Somma:     %d\n", calcolaSommaVettore(n, v));
    printf("Media:     %.2f\n", calcolaMediaVettore(n, v));
    printf("Massimo:   %d (pos %d)\n", trovaMassimoVettore(n, v), trovaPosMassimoVettore(n, v));

    ordinaBubbleSort(n, v);
    printf("Ordinato:  ");  stampaVettore(n, v);

    /* ----- MATRICI ----- */
    int rows = 3, cols = 3;
    int m[rows][cols];
    riempiMatriceCasuale(rows, cols, m, 1, 9);

    printf("\nMatrice:\n");
    stampaMatrice(rows, cols, m);
    printf("Media:           %.2f\n", calcolaMediaMatrice(rows, cols, m));
    printf("Diag. principale: %d\n", calcolaSommaDiagonalePrincipale(rows, m));
    printf("Diag. secondaria: %d\n", calcolaSommaDiagonaleSecondaria(rows, m));
    printf("Determinante:     %lld\n", calcolaDeterminante(rows, m));

    int t[cols][rows];                               // la trasposta ha dimensioni scambiate
    calcolaTrasposta(rows, cols, m, t);
    printf("Trasposta:\n");
    stampaMatrice(cols, rows, t);

    /* ----- FUNZIONI EXTRA: NUMERI ----- */
    printf("\nMCD(12,18) = %d   mcm(12,18) = %d\n", calcolaMCD(12, 18), calcolaMCM(12, 18));
    printf("10! = %lld\n", calcolaFattoriale(10));
    printf("Somma cifre di 4075: %d   Inverso: %d\n", calcolaSommaCifre(4075), invertiNumero(4075));

    int cifre[32], nCifre;
    convertiNumeroInBase(10, 2, cifre, &nCifre);     // 10 in binario
    printf("10 in binario: ");
    stampaVettore(nCifre, cifre);

    /* ----- FUNZIONI EXTRA: VETTORI ----- */
    int u[6] = {1, 2, 2, 3, 3, 3};
    printf("\nModa di 1 2 2 3 3 3:      %d\n", calcolaModaVettore(6, u));
    printf("Mediana di 1 2 2 3 3 3:   %.1f\n", calcolaMedianaVettore(6, u));
    printf("Secondo massimo:          %d\n", trovaSecondoMassimoVettore(6, u));

    int ord[10] = {1, 3, 5, 7}, nOrd = 4;
    inserisciOrdinatoVettore(&nOrd, 10, ord, 4);     // resta ordinato
    printf("Inserimento ordinato del 4: ");
    stampaVettore(nOrd, ord);

    /* ----- FUNZIONI EXTRA: MATRICI ----- */
    int sp[3][4];
    riempiMatriceSpirale(3, 4, sp);
    printf("\nMatrice a spirale:\n");
    stampaMatrice(3, 4, sp);
    printf("Lettura a spirale: ");
    stampaMatriceSpirale(3, 4, sp);

    int pascal[5][5];
    creaTriangoloPascal(5, pascal);
    printf("\nTriangolo di Pascal:\n");
    stampaMatrice(5, 5, pascal);

    int a2[2][2] = {{1, 2}, {3, 4}};
    float inv[2][2];
    if (calcolaMatriceInversa(2, a2, inv))
        printf("\nInversa di {{1,2},{3,4}}: [%.1f %.1f; %.1f %.1f]\n", inv[0][0], inv[0][1], inv[1][0], inv[1][1]);


    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    //altro
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////


    /* ----- TEST FUNZIONI AGGIUNTIVE: VETTORI ----- */
    printf("\n--- Test Utility Vettori ---\n");
    printf("Stampa in colonna:\n");
    stampaVettoreColonna(n, v);

    printf("Il valore alla posizione 2: %d\n", valoreInPosizione(n, v, 2));
    
    printf("Sotto-vettore (dall'indice 1 al 3): ");
    stampaSottoVettore(n, v, 1, 3);

    /* ----- TEST FUNZIONI AGGIUNTIVE: MATRICI ----- */
    printf("\n--- Test Matrice a Scacchiera (3x3) ---\n");
    int mScacchiera[3][3];
    caricaMatriceScacchiera(3, 3, mScacchiera);
    stampaMatrice(3, 3, mScacchiera);

    /* ----- TEST MINIGIOCHI (Commentati per evitare blocchi da input da tastiera) ----- */
    /*
    // Catch the Pin
    int codice[3], utente[3];
    creaCodiceSegreto(codice, 3);
    printf("\n[Catch the Pin] Codice segreto generato!\n");
    // richiediCodiceUtente(utente, 3);
    // verificaCodice(codice, utente, 3);

    // Battaglia Navale
    int campoBattaglia[LATO][LATO];
    preparaCampo(campoBattaglia);
    piazzaNavi(campoBattaglia);
    printf("\n[Battaglia Navale] Campo preparato (navi visibili):\n");
    stampaCampo(campoBattaglia, true);
    */

    return 0;
}