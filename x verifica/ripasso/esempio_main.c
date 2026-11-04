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


    /* ===== FUNZIONI AGGIUNTE: NUMERI ===== */
    printf("\n2^10 = %lld   radice intera di 50 = %d\n", calcolaPotenza(2, 10), calcolaRadiceIntera(50));
    printf("Divisori di 36: %d\n", contaDivisori(36));
    printf("28 e' perfetto? %s   153 e' di Armstrong? %s\n",
           verificaNumeroPerfetto(28) ? "si" : "no", verificaNumeroArmstrong(153) ? "si" : "no");
    int fattori[32], nFattori;
    scomponiInFattoriPrimi(360, fattori, &nFattori);
    printf("360 = ");
    stampaVettore(nFattori, fattori);
    printf("C(5,2) = %lld\n", calcolaBinomiale(5, 2));
    int cifreBin[4] = {1, 0, 1, 0};
    printf("1010 in base 2 = %lld in decimale\n", convertiDaBaseInDecimale(4, cifreBin, 2));

    /* ===== FUNZIONI AGGIUNTE: VETTORI ===== */
    int kad[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("\nSomma massima di un tratto consecutivo: %d\n", trovaSommaSottovettoreMax(9, kad));
    int c5[5] = {1, 2, 3, 4, 5};
    printf("Coppie con somma 6: %d\n", contaCoppieSommaVettore(5, c5, 6));

    int senzaPari[6] = {1, 2, 3, 4, 5, 6}, nSenzaPari = 6;
    eliminaPariVettore(&nSenzaPari, senzaPari);
    printf("Senza i pari:             ");
    stampaVettore(nSenzaPari, senzaPari);

    int rot[5] = {1, 2, 3, 4, 5};
    ruotaSinistraKVettore(5, rot, 2);
    printf("Ruotato a sinistra di 2:  ");
    stampaVettore(5, rot);
    invertiParteVettore(5, rot, 1, 3);
    printf("Invertiti gli elementi 1..3: ");
    stampaVettore(5, rot);
    mescolaVettore(5, rot);
    printf("Mescolato:                ");
    stampaVettore(5, rot);
    ordinaQuickSort(5, rot);
    printf("Quick sort:               ");
    stampaVettore(5, rot);

    int dati[7] = {0, 1, 1, 3, 5, 5, 5}, freq[6];
    calcolaIstogrammaVettore(7, dati, 5, freq);
    printf("Frequenze dei valori 0..5: ");
    stampaVettore(6, freq);

    /* ===== FUNZIONI AGGIUNTE: MATRICI ===== */
    int scacchiera[4][4];
    riempiMatriceScacchiera(4, 4, scacchiera);
    printf("\nScacchiera:\n");
    stampaMatrice(4, 4, scacchiera);

    int tabellina[4][5];
    riempiMatriceTabellina(4, 5, tabellina);
    printf("Tabellina allineata:\n");
    stampaMatriceAllineata(4, 5, tabellina, 4);

    int quadrata[3][3];
    riempiMatriceProgressiva(3, 3, quadrata, 1);
    ruotaMatriceQuadrata90OrarioSulPosto(3, quadrata);
    printf("Matrice 1..9 ruotata di 90 gradi in senso orario:\n");
    stampaMatrice(3, 3, quadrata);

    int segni[2][3] = {{1, -2, 0}, {3, 0, -4}};
    printf("Positivi: %d   Negativi: %d\n", contaPositiviMatrice(2, 3, segni), contaNegativiMatrice(2, 3, segni));
    
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