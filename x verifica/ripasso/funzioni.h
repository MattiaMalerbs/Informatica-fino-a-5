/*
 * ============================================================
 *  funzioni.h - Libreria di funzioni su VETTORI e MATRICI (C99)
 * ============================================================
 *  Convenzioni:
 *   - Vettori:  (int _n, int _v[_n])               n = numero elementi
 *   - Matrici:  (int _rows, int _cols, int _m[_rows][_cols])
 *   - Le dimensioni vengono SEMPRE prima dell'array che le usa
 *     (e' obbligatorio in C99 per gli array a lunghezza variabile).
 *   - Se una funzione modifica la dimensione, questa viene passata
 *     per puntatore (int *_n) e aggiornata dalla funzione.
 *   - Compilare con:  gcc -std=c99 -Wall main.c funzioni.c -o programma
 *
 *  INDICE
 *   1. VETTORI
 *      1.1 Input / output      1.2 Statistiche      1.3 Ricerca
 *      1.4 Ordinamento         1.5 Modifica         1.6 Tra due vettori
 *      1.7 Controlli
 *   2. MATRICI
 *      2.1 Input / output      2.2 Statistiche      2.3 Righe/colonne/diagonali
 *      2.4 Tra matrici         2.5 Trasformazioni   2.6 Controlli
 *      2.7 Determinante        2.8 Conversioni
 *   3. EXTRA
 *      3.1 Numeri e utilita'   3.2 Vettori extra   3.3 Matrici extra
 * ============================================================
 */

#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdbool.h>


/* ============================================================
 *  1. VETTORI
 * ============================================================ */

/* ---------- 1.1 INPUT / OUTPUT ---------- */

/**
 * Carica il vettore chiedendo gli elementi da tastiera.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void caricaVettore(int _n, int _v[_n]);

/**
 * Riempie il vettore con numeri casuali compresi tra min e max (inclusi).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore minimo.
 * @param int Valore massimo.
 */
void riempiVettoreCasuale(int _n, int _v[_n], int _min, int _max);

/**
 * Stampa il vettore su una riga, elementi separati da spazio.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void stampaVettore(int _n, int _v[_n]);

/**
 * Copia il vettore sorgente nel vettore destinazione.
 * @param int Numero di elementi.
 * @param int* Riferimento al vettore sorgente.
 * @param int* Riferimento al vettore destinazione.
 */
void copiaVettore(int _n, int _src[_n], int _dst[_n]);


/* ---------- 1.2 STATISTICHE ---------- */

/**
 * Calcola e restituisce la somma di tutti gli elementi del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Somma degli elementi.
 */
int calcolaSommaVettore(int _n, int _v[_n]);

/**
 * Calcola e restituisce il valor medio del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Valor medio del vettore.
 */
float calcolaMediaVettore(int _n, int _v[_n]);

/**
 * Trova il valore massimo del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Valore massimo.
 */
int trovaMassimoVettore(int _n, int _v[_n]);

/**
 * Trova il valore minimo del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Valore minimo.
 */
int trovaMinimoVettore(int _n, int _v[_n]);

/**
 * Trova la posizione del massimo (la prima se ce ne sono piu' di uno).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Indice dell'elemento massimo.
 */
int trovaPosMassimoVettore(int _n, int _v[_n]);

/**
 * Trova la posizione del minimo (la prima se ce ne sono piu' di uno).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Indice dell'elemento minimo.
 */
int trovaPosMinimoVettore(int _n, int _v[_n]);

/**
 * Conta quante volte un valore compare nel vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da contare.
 * @return Numero di occorrenze.
 */
int contaOccorrenzeVettore(int _n, int _v[_n], int _x);

/**
 * Conta gli elementi pari del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi pari.
 */
int contaPariVettore(int _n, int _v[_n]);

/**
 * Conta gli elementi dispari del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi dispari.
 */
int contaDispariVettore(int _n, int _v[_n]);

/**
 * Conta gli elementi positivi (> 0) del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi positivi.
 */
int contaPositiviVettore(int _n, int _v[_n]);

/**
 * Conta gli elementi negativi (< 0) del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi negativi.
 */
int contaNegativiVettore(int _n, int _v[_n]);

/**
 * Conta gli elementi strettamente maggiori di una soglia.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Soglia.
 * @return Numero di elementi maggiori della soglia.
 */
int contaMaggioriVettore(int _n, int _v[_n], int _soglia);

/**
 * Conta gli elementi del vettore che sono numeri primi.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi primi.
 */
int contaPrimiVettore(int _n, int _v[_n]);


/* ---------- 1.3 RICERCA ---------- */

/**
 * Ricerca lineare: cerca un valore scorrendo il vettore dall'inizio.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da cercare.
 * @return Indice della prima occorrenza, oppure -1 se non presente.
 */
int cercaInVettore(int _n, int _v[_n], int _x);

/**
 * Ricerca binaria: il vettore DEVE essere ordinato in modo crescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore (ordinato crescente).
 * @param int Valore da cercare.
 * @return Indice del valore, oppure -1 se non presente.
 */
int cercaBinariaVettore(int _n, int _v[_n], int _x);


/* ---------- 1.4 ORDINAMENTO ---------- */

/**
 * Scambia il valore di due interi.
 * @param int* Puntatore al primo intero.
 * @param int* Puntatore al secondo intero.
 */
void scambia(int *_a, int *_b);

/**
 * Ordina il vettore in modo CRESCENTE con il Bubble Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void ordinaBubbleSort(int _n, int _v[_n]);

/**
 * Ordina il vettore in modo DECRESCENTE con il Bubble Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void ordinaBubbleSortDecr(int _n, int _v[_n]);

/**
 * Ordina il vettore in modo CRESCENTE con il Selection Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void ordinaSelectionSort(int _n, int _v[_n]);

/**
 * Ordina il vettore in modo CRESCENTE con l'Insertion Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void ordinaInsertionSort(int _n, int _v[_n]);


/* ---------- 1.5 MODIFICA ---------- */

/**
 * Inverte l'ordine degli elementi (il primo diventa l'ultimo, ecc.).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void invertiVettore(int _n, int _v[_n]);

/**
 * Ruota il vettore a destra di una posizione (l'ultimo diventa il primo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void ruotaDestraVettore(int _n, int _v[_n]);

/**
 * Ruota il vettore a sinistra di una posizione (il primo diventa l'ultimo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void ruotaSinistraVettore(int _n, int _v[_n]);

/**
 * Ruota il vettore a destra di k posizioni.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero di posizioni di cui ruotare.
 */
void ruotaDestraKVettore(int _n, int _v[_n], int _k);

/**
 * Inserisce un valore in una posizione, spostando a destra gli altri elementi.
 * @param int* Puntatore al numero di elementi (viene aumentato di 1).
 * @param int Capacita' massima del vettore.
 * @param int* Riferimento al vettore.
 * @param int Posizione in cui inserire (da 0 a n compreso).
 * @param int Valore da inserire.
 * @return true se l'inserimento e' riuscito, false se posizione non valida o vettore pieno.
 */
bool inserisciInVettore(int *_n, int _capacita, int _v[], int _pos, int _x);

/**
 * Elimina l'elemento in una posizione, spostando a sinistra gli altri.
 * @param int* Puntatore al numero di elementi (viene diminuito di 1).
 * @param int* Riferimento al vettore.
 * @param int Posizione dell'elemento da eliminare.
 * @return true se l'eliminazione e' riuscita, false se la posizione non e' valida.
 */
bool eliminaDaVettore(int *_n, int _v[], int _pos);

/**
 * Elimina TUTTE le occorrenze di un valore dal vettore.
 * @param int* Puntatore al numero di elementi (viene aggiornato).
 * @param int* Riferimento al vettore.
 * @param int Valore da eliminare.
 */
void eliminaValoreVettore(int *_n, int _v[], int _x);

/**
 * Elimina i duplicati, lasciando solo la prima occorrenza di ogni valore.
 * @param int* Puntatore al numero di elementi (viene aggiornato).
 * @param int* Riferimento al vettore.
 */
void eliminaDuplicatiVettore(int *_n, int _v[]);

/**
 * Sostituisce ogni occorrenza di un valore con un altro.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da sostituire.
 * @param int Nuovo valore.
 */
void sostituisciInVettore(int _n, int _v[_n], int _vecchio, int _nuovo);


/* ---------- 1.6 OPERAZIONI TRA DUE VETTORI ---------- */

/**
 * Somma due vettori elemento per elemento: ris[i] = a[i] + b[i].
 * @param int Numero di elementi dei vettori.
 * @param int* Primo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato.
 */
void sommaVettori(int _n, int _a[_n], int _b[_n], int _ris[_n]);

/**
 * Sottrae due vettori elemento per elemento: ris[i] = a[i] - b[i].
 * @param int Numero di elementi dei vettori.
 * @param int* Primo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato.
 */
void differenzaVettori(int _n, int _a[_n], int _b[_n], int _ris[_n]);

/**
 * Calcola il prodotto scalare: a[0]*b[0] + a[1]*b[1] + ...
 * @param int Numero di elementi dei vettori.
 * @param int* Primo vettore.
 * @param int* Secondo vettore.
 * @return Prodotto scalare.
 */
int calcolaProdottoScalare(int _n, int _a[_n], int _b[_n]);

/**
 * Moltiplica ogni elemento del vettore per un numero.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero per cui moltiplicare.
 */
void moltiplicaVettoreScalare(int _n, int _v[_n], int _k);

/**
 * Verifica se due vettori sono uguali (stessa lunghezza e stessi elementi).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @return true se uguali, false altrimenti.
 */
bool verificaVettoriUguali(int _na, int _a[_na], int _nb, int _b[_nb]);

/**
 * Fonde due vettori GIA' ORDINATI in un terzo vettore ordinato (merge).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore (ordinato).
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore (ordinato).
 * @param int* Vettore risultato (deve contenere almeno na + nb elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 */
void fondiVettoriOrdinati(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc);

/**
 * Concatena due vettori: il risultato contiene prima a e poi b.
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato (deve contenere almeno na + nb elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 */
void concatenaVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc);

/**
 * Calcola l'intersezione: elementi presenti sia in a sia in b, senza ripetizioni.
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato (deve contenere almeno na elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 */
void intersezioneVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc);


/* ---------- 1.7 CONTROLLI ---------- */

/**
 * Verifica se il vettore e' ordinato in modo crescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se ordinato crescente, false altrimenti.
 */
bool verificaVettoreCrescente(int _n, int _v[_n]);

/**
 * Verifica se il vettore e' ordinato in modo decrescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se ordinato decrescente, false altrimenti.
 */
bool verificaVettoreDecrescente(int _n, int _v[_n]);

/**
 * Verifica se il vettore e' palindromo (si legge uguale in entrambi i versi).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se palindromo, false altrimenti.
 */
bool verificaVettorePalindromo(int _n, int _v[_n]);

/**
 * Verifica se il vettore contiene elementi ripetuti.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se esiste almeno un duplicato, false altrimenti.
 */
bool verificaVettoreHaDuplicati(int _n, int _v[_n]);

/**
 * Verifica se tutti gli elementi del vettore sono uguali.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se tutti uguali, false altrimenti.
 */
bool verificaVettoreTuttiUguali(int _n, int _v[_n]);

/**
 * Verifica se un numero e' primo.
 * @param int Numero da controllare.
 * @return true se il numero e' primo, false altrimenti.
 */
bool verificaPrimo(int _x);


/* ============================================================
 *  2. MATRICI
 *  (rows = numero di righe, cols = numero di colonne)
 * ============================================================ */

/* ---------- 2.1 INPUT / OUTPUT ---------- */

/**
 * Carica la matrice chiedendo gli elementi da tastiera.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void caricaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Riempie la matrice con numeri casuali compresi tra min e max (inclusi).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore minimo.
 * @param int Valore massimo.
 */
void riempiMatriceCasuale(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max);

/**
 * Stampa la matrice riga per riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Copia la matrice sorgente nella matrice destinazione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice sorgente.
 * @param int* Riferimento alla matrice destinazione.
 */
void copiaMatrice(int _rows, int _cols, int _src[_rows][_cols], int _dst[_rows][_cols]);

/**
 * Riempie tutta la matrice con lo stesso valore (ad esempio 0).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore con cui riempire.
 */
void riempiMatriceCon(int _rows, int _cols, int _m[_rows][_cols], int _valore);

/**
 * Crea la matrice identita' (1 sulla diagonale principale, 0 altrove).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 */
void creaMatriceIdentita(int _n, int _m[_n][_n]);


/* ---------- 2.2 STATISTICHE ---------- */

/**
 * Calcola e restituisce la somma di tutti gli elementi della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi.
 */
int calcolaSommaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Calcola e restituisce il valor medio della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Valor medio della matrice.
 */
float calcolaMediaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Trova il massimo della matrice e la sua posizione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Puntatore dove salvare la riga del massimo.
 * @param int* Puntatore dove salvare la colonna del massimo.
 * @return Valore massimo.
 */
int trovaMassimoMatrice(int _rows, int _cols, int _m[_rows][_cols], int *_riga, int *_col);

/**
 * Trova il minimo della matrice e la sua posizione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Puntatore dove salvare la riga del minimo.
 * @param int* Puntatore dove salvare la colonna del minimo.
 * @return Valore minimo.
 */
int trovaMinimoMatrice(int _rows, int _cols, int _m[_rows][_cols], int *_riga, int *_col);

/**
 * Conta quante volte un valore compare nella matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore da contare.
 * @return Numero di occorrenze.
 */
int contaOccorrenzeMatrice(int _rows, int _cols, int _m[_rows][_cols], int _x);

/**
 * Conta gli elementi pari della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Numero di elementi pari.
 */
int contaPariMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Cerca un valore nella matrice e ne restituisce la posizione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore da cercare.
 * @param int* Puntatore dove salvare la riga trovata.
 * @param int* Puntatore dove salvare la colonna trovata.
 * @return true se il valore e' presente, false altrimenti.
 */
bool cercaInMatrice(int _rows, int _cols, int _m[_rows][_cols], int _x, int *_riga, int *_col);


/* ---------- 2.3 RIGHE, COLONNE, DIAGONALI ---------- */

/**
 * Calcola la somma degli elementi di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga.
 * @return Somma della riga.
 */
int calcolaSommaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga);

/**
 * Calcola la somma degli elementi di una colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna.
 * @return Somma della colonna.
 */
int calcolaSommaColonna(int _rows, int _cols, int _m[_rows][_cols], int _col);

/**
 * Salva in un vettore la somma di ogni riga (out[i] = somma della riga i).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (rows elementi).
 */
void calcolaSommeRighe(int _rows, int _cols, int _m[_rows][_cols], int _out[_rows]);

/**
 * Salva in un vettore la somma di ogni colonna (out[j] = somma della colonna j).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (cols elementi).
 */
void calcolaSommeColonne(int _rows, int _cols, int _m[_rows][_cols], int _out[_cols]);

/**
 * Trova l'indice della riga con somma massima.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Indice della riga con somma massima.
 */
int trovaRigaSommaMax(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Trova l'indice della colonna con somma massima.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Indice della colonna con somma massima.
 */
int trovaColonnaSommaMax(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Trova il valore massimo di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga.
 * @return Massimo della riga.
 */
int trovaMassimoRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga);

/**
 * Trova il valore massimo di una colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna.
 * @return Massimo della colonna.
 */
int trovaMassimoColonna(int _rows, int _cols, int _m[_rows][_cols], int _col);

/**
 * Calcola la somma della diagonale principale (alto-sinistra -> basso-destra).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma della diagonale principale.
 */
int calcolaSommaDiagonalePrincipale(int _n, int _m[_n][_n]);

/**
 * Calcola la somma della diagonale secondaria (alto-destra -> basso-sinistra).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma della diagonale secondaria.
 */
int calcolaSommaDiagonaleSecondaria(int _n, int _m[_n][_n]);

/**
 * Calcola la somma degli elementi sopra la diagonale principale (j > i).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi sopra la diagonale.
 */
int calcolaSommaSopraDiagonale(int _n, int _m[_n][_n]);

/**
 * Calcola la somma degli elementi sotto la diagonale principale (j < i).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi sotto la diagonale.
 */
int calcolaSommaSottoDiagonale(int _n, int _m[_n][_n]);

/**
 * Calcola la somma degli elementi del perimetro (prima/ultima riga e colonna).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi del perimetro.
 */
int calcolaSommaPerimetro(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Stampa su una riga gli elementi della diagonale principale.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 */
void stampaDiagonalePrincipale(int _n, int _m[_n][_n]);


/* ---------- 2.4 OPERAZIONI TRA MATRICI ---------- */

/**
 * Somma due matrici: ris = a + b.
 * @param int Numero di righe delle matrici.
 * @param int Numero di colonne delle matrici.
 * @param int* Prima matrice.
 * @param int* Seconda matrice.
 * @param int* Matrice risultato.
 */
void sommaMatrici(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols], int _ris[_rows][_cols]);

/**
 * Sottrae due matrici: ris = a - b.
 * @param int Numero di righe delle matrici.
 * @param int Numero di colonne delle matrici.
 * @param int* Prima matrice.
 * @param int* Seconda matrice.
 * @param int* Matrice risultato.
 */
void differenzaMatrici(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols], int _ris[_rows][_cols]);

/**
 * Moltiplica ogni elemento della matrice per un numero.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Numero per cui moltiplicare.
 */
void moltiplicaMatriceScalare(int _rows, int _cols, int _m[_rows][_cols], int _k);

/**
 * Prodotto righe per colonne: A (r1 x c1) * B (c1 x c2) = ris (r1 x c2).
 * Il numero di colonne di A deve coincidere con il numero di righe di B.
 * @param int Numero di righe di A.
 * @param int Numero di colonne di A (= righe di B).
 * @param int Numero di colonne di B.
 * @param int* Matrice A.
 * @param int* Matrice B.
 * @param int* Matrice risultato (r1 x c2).
 */
void prodottoMatrici(int _r1, int _c1, int _c2, int _a[_r1][_c1], int _b[_c1][_c2], int _ris[_r1][_c2]);

/**
 * Prodotto matrice per vettore: ris[i] = somma(m[i][j] * v[j]).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore (cols elementi).
 * @param int* Vettore risultato (rows elementi).
 */
void prodottoMatriceVettore(int _rows, int _cols, int _m[_rows][_cols], int _v[_cols], int _ris[_rows]);

/**
 * Elevamento a potenza di una matrice quadrata: ris = m^k (k >= 0).
 * La matrice m e la matrice ris devono essere DIVERSE.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param int Esponente.
 * @param int* Matrice risultato.
 */
void potenzaMatrice(int _n, int _m[_n][_n], int _k, int _ris[_n][_n]);

/**
 * Verifica se due matrici sono uguali.
 * @param int Numero di righe delle matrici.
 * @param int Numero di colonne delle matrici.
 * @param int* Prima matrice.
 * @param int* Seconda matrice.
 * @return true se uguali, false altrimenti.
 */
bool verificaMatriciUguali(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols]);


/* ---------- 2.5 TRASFORMAZIONI ---------- */

/**
 * Calcola la trasposta: ris[j][i] = m[i][j] (righe e colonne si scambiano).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (cols x rows).
 */
void calcolaTrasposta(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]);

/**
 * Trasposta "sul posto" di una matrice quadrata (modifica la matrice stessa).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 */
void traspostaSulPosto(int _n, int _m[_n][_n]);

/**
 * Scambia due righe della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della prima riga.
 * @param int Indice della seconda riga.
 */
void scambiaRigheMatrice(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _r2);

/**
 * Scambia due colonne della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della prima colonna.
 * @param int Indice della seconda colonna.
 */
void scambiaColonneMatrice(int _rows, int _cols, int _m[_rows][_cols], int _c1, int _c2);

/**
 * Ruota la matrice di 90 gradi in senso orario.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (cols x rows).
 */
void ruotaMatrice90Orario(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]);

/**
 * Specchia la matrice in orizzontale (inverte l'ordine delle colonne).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void specchiaMatriceOrizzontale(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Specchia la matrice in verticale (inverte l'ordine delle righe).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void specchiaMatriceVerticale(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Ordina in modo crescente gli elementi di una singola riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga da ordinare.
 */
void ordinaRigaMatrice(int _rows, int _cols, int _m[_rows][_cols], int _riga);

/**
 * Copia la matrice in un'altra togliendo una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga da togliere.
 * @param int* Matrice risultato ((rows - 1) x cols).
 */
void copiaMatriceSenzaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga, int _out[_rows - 1][_cols]);

/**
 * Copia la matrice in un'altra togliendo una colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna da togliere.
 * @param int* Matrice risultato (rows x (cols - 1)).
 */
void copiaMatriceSenzaColonna(int _rows, int _cols, int _m[_rows][_cols], int _col, int _out[_rows][_cols - 1]);


/* ---------- 2.6 CONTROLLI SUL TIPO DI MATRICE ---------- */

/**
 * Verifica se la matrice quadrata e' simmetrica (m[i][j] == m[j][i]).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se simmetrica, false altrimenti.
 */
bool verificaMatriceSimmetrica(int _n, int _m[_n][_n]);

/**
 * Verifica se la matrice quadrata e' diagonale (0 fuori dalla diagonale principale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se diagonale, false altrimenti.
 */
bool verificaMatriceDiagonale(int _n, int _m[_n][_n]);

/**
 * Verifica se la matrice quadrata e' la matrice identita'.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se identita', false altrimenti.
 */
bool verificaMatriceIdentita(int _n, int _m[_n][_n]);

/**
 * Verifica se la matrice quadrata e' triangolare superiore (0 sotto la diagonale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se triangolare superiore, false altrimenti.
 */
bool verificaMatriceTriangolareSup(int _n, int _m[_n][_n]);

/**
 * Verifica se la matrice quadrata e' triangolare inferiore (0 sopra la diagonale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se triangolare inferiore, false altrimenti.
 */
bool verificaMatriceTriangolareInf(int _n, int _m[_n][_n]);

/**
 * Verifica se la matrice e' nulla (tutti gli elementi uguali a 0).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return true se nulla, false altrimenti.
 */
bool verificaMatriceNulla(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Verifica se la matrice quadrata e' un quadrato magico
 * (righe, colonne e le due diagonali hanno tutte la stessa somma).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se quadrato magico, false altrimenti.
 */
bool verificaQuadratoMagico(int _n, int _m[_n][_n]);

/**
 * Verifica se tutti gli elementi della matrice sono diversi tra loro.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return true se tutti diversi, false se esiste almeno un duplicato.
 */
bool verificaMatriceElementiDiversi(int _rows, int _cols, int _m[_rows][_cols]);


/* ---------- 2.7 DETERMINANTE ---------- */

/**
 * Calcola il determinante di una matrice quadrata (sviluppo di Laplace
 * sulla prima riga, ricorsivo).
 * @param int Dimensione della matrice quadrata (>= 1).
 * @param int* Riferimento alla matrice.
 * @return Determinante della matrice.
 */
long long calcolaDeterminante(int _n, int _m[_n][_n]);


/* ---------- 2.8 CONVERSIONI VETTORE <-> MATRICE ---------- */

/**
 * Copia la matrice in un vettore, riga dopo riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (rows * cols elementi).
 */
void matriceInVettore(int _rows, int _cols, int _m[_rows][_cols], int _v[_rows * _cols]);

/**
 * Riempie la matrice con gli elementi del vettore, riga dopo riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Vettore sorgente (rows * cols elementi).
 * @param int* Matrice risultato.
 */
void vettoreInMatrice(int _rows, int _cols, int _v[_rows * _cols], int _m[_rows][_cols]);

/* ============================================================
 *  3. FUNZIONI EXTRA
 *     3.1 Numeri e utilita'   3.2 Vettori extra   3.3 Matrici extra
 * ============================================================ */

/* ---------- 3.1 NUMERI E UTILITA' ---------- */

/**
 * Calcola il Massimo Comun Divisore con l'algoritmo di Euclide.
 * @param int Primo numero.
 * @param int Secondo numero.
 * @return MCD dei due numeri.
 */
int calcolaMCD(int _a, int _b);

/**
 * Calcola il minimo comune multiplo.
 * @param int Primo numero.
 * @param int Secondo numero.
 * @return mcm dei due numeri.
 */
int calcolaMCM(int _a, int _b);

/**
 * Calcola il MCD di tutti gli elementi di un vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return MCD di tutti gli elementi.
 */
int calcolaMCDVettore(int _n, int _v[_n]);

/**
 * Calcola il fattoriale di un numero (n!).
 * @param int Numero (>= 0, al massimo 20 per non andare in overflow).
 * @return Fattoriale del numero.
 */
long long calcolaFattoriale(int _x);

/**
 * Conta le cifre di un numero (il segno viene ignorato; lo 0 ha 1 cifra).
 * @param int Numero.
 * @return Numero di cifre.
 */
int contaCifre(int _x);

/**
 * Calcola la somma delle cifre di un numero (il segno viene ignorato).
 * @param int Numero.
 * @return Somma delle cifre.
 */
int calcolaSommaCifre(int _x);

/**
 * Inverte le cifre di un numero (es. 123 -> 321, -45 -> -54).
 * @param int Numero.
 * @return Numero con le cifre invertite.
 */
int invertiNumero(int _x);

/**
 * Verifica se un numero e' palindromo (es. 12321).
 * @param int Numero.
 * @return true se palindromo, false altrimenti.
 */
bool verificaNumeroPalindromo(int _x);

/**
 * Scompone un numero nel vettore delle sue cifre (la prima e' la piu' significativa).
 * @param int Numero (il segno viene ignorato).
 * @param int* Vettore risultato (almeno 10 elementi).
 * @param int* Puntatore dove salvare il numero di cifre.
 */
void numeroInVettoreCifre(int _x, int _v[], int *_n);

/**
 * Ricostruisce un numero a partire dal vettore delle cifre (operazione inversa).
 * @param int Numero di cifre.
 * @param int* Riferimento al vettore delle cifre.
 * @return Numero ricostruito.
 */
long long vettoreCifreInNumero(int _n, int _v[_n]);

/**
 * Converte un numero in una base (2..16) salvando le cifre in un vettore.
 * La prima cifra del vettore e' la piu' significativa (es. 10 in base 2 -> 1 0 1 0).
 * @param int Numero da convertire (>= 0).
 * @param int Base di arrivo.
 * @param int* Vettore risultato (almeno 32 elementi).
 * @param int* Puntatore dove salvare il numero di cifre.
 */
void convertiNumeroInBase(int _x, int _base, int _v[], int *_n);

/**
 * Riempie il vettore con i primi n numeri di Fibonacci (0 1 1 2 3 5 ...).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void generaFibonacciVettore(int _n, int _v[_n]);

/**
 * Riempie il vettore con i primi n numeri primi (2 3 5 7 11 ...).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void generaPrimiVettore(int _n, int _v[_n]);


/* ---------- 3.2 VETTORI EXTRA ---------- */

/**
 * Riempie il vettore con numeri casuali TUTTI DIVERSI tra min e max (inclusi).
 * Attenzione: deve valere (max - min + 1) >= n, altrimenti non termina.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore minimo.
 * @param int Valore massimo.
 */
void riempiVettoreCasualeUnici(int _n, int _v[_n], int _min, int _max);

/**
 * Stampa il vettore partendo dall'ultimo elemento (senza modificarlo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void stampaVettoreInverso(int _n, int _v[_n]);

/**
 * Trova il secondo valore piu' grande (strettamente minore del massimo).
 * Se tutti gli elementi sono uguali restituisce il massimo.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Secondo massimo.
 */
int trovaSecondoMassimoVettore(int _n, int _v[_n]);

/**
 * Calcola la moda: il valore che compare piu' volte (a parita', il primo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Moda del vettore.
 */
int calcolaModaVettore(int _n, int _v[_n]);

/**
 * Calcola la mediana (non modifica il vettore, lavora su una copia).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Mediana del vettore.
 */
float calcolaMedianaVettore(int _n, int _v[_n]);

/**
 * Calcola la differenza tra il massimo e il minimo (escursione).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Massimo - minimo.
 */
int calcolaDifferenzaMaxMin(int _n, int _v[_n]);

/**
 * Somma gli elementi nelle posizioni (indici) pari: v[0] + v[2] + v[4] + ...
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Somma degli elementi in posizione pari.
 */
int calcolaSommaPosizioniPariVettore(int _n, int _v[_n]);

/**
 * Somma gli elementi nelle posizioni (indici) dispari: v[1] + v[3] + v[5] + ...
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Somma degli elementi in posizione dispari.
 */
int calcolaSommaPosizioniDispariVettore(int _n, int _v[_n]);

/**
 * Calcola le somme cumulative: out[i] = v[0] + v[1] + ... + v[i].
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int* Vettore risultato.
 */
void calcolaSommeCumulativeVettore(int _n, int _v[_n], int _out[_n]);

/**
 * Trova la lunghezza della piu' lunga sequenza consecutiva strettamente crescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Lunghezza massima trovata.
 */
int trovaLunghezzaSequenzaCrescenteMax(int _n, int _v[_n]);

/**
 * Cerca un sottovettore (sequenza consecutiva) dentro un vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero di elementi del sottovettore.
 * @param int* Riferimento al sottovettore.
 * @return Indice di inizio della prima occorrenza, oppure -1.
 */
int cercaSottovettore(int _n, int _v[_n], int _m, int _sub[_m]);

/**
 * Verifica se un vettore e' una permutazione dell'altro (stessi elementi, ordine diverso).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @return true se sono permutazione l'uno dell'altro, false altrimenti.
 */
bool verificaVettoriPermutazione(int _na, int _a[_na], int _nb, int _b[_nb]);

/**
 * Calcola l'unione: tutti gli elementi di a e di b, senza ripetizioni.
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato (deve contenere almeno na + nb elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 */
void unioneVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc);

/**
 * Separa gli elementi pari da quelli dispari in due vettori (mantenendo l'ordine).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int* Vettore dei pari (almeno n elementi).
 * @param int* Puntatore al numero di pari (viene calcolato).
 * @param int* Vettore dei dispari (almeno n elementi).
 * @param int* Puntatore al numero di dispari (viene calcolato).
 */
void separaPariDispari(int _n, int _v[_n], int _pari[], int *_np, int _dispari[], int *_nd);

/**
 * Sposta tutti gli 0 in fondo al vettore, mantenendo l'ordine degli altri elementi.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 */
void spostaZeriInFondoVettore(int _n, int _v[_n]);

/**
 * Inserisce un valore in un vettore GIA' ORDINATO crescente, mantenendolo ordinato.
 * @param int* Puntatore al numero di elementi (viene aumentato di 1).
 * @param int Capacita' massima del vettore.
 * @param int* Riferimento al vettore (ordinato crescente).
 * @param int Valore da inserire.
 * @return true se l'inserimento e' riuscito, false se il vettore e' pieno.
 */
bool inserisciOrdinatoVettore(int *_n, int _capacita, int _v[], int _x);


/* ---------- 3.3 MATRICI EXTRA ---------- */

/**
 * Calcola la traccia di una matrice quadrata (somma della diagonale principale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Traccia della matrice.
 */
int calcolaTraccia(int _n, int _m[_n][_n]);

/**
 * Salva in un vettore il massimo di ogni riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (rows elementi).
 */
void calcolaMassimiRighe(int _rows, int _cols, int _m[_rows][_cols], int _out[_rows]);

/**
 * Salva in un vettore il massimo di ogni colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (cols elementi).
 */
void calcolaMassimiColonne(int _rows, int _cols, int _m[_rows][_cols], int _out[_cols]);

/**
 * Salva in un vettore la media di ogni riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param float* Vettore risultato (rows elementi).
 */
void calcolaMedieRighe(int _rows, int _cols, int _m[_rows][_cols], float _out[_rows]);

/**
 * Salva in un vettore la media di ogni colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param float* Vettore risultato (cols elementi).
 */
void calcolaMedieColonne(int _rows, int _cols, int _m[_rows][_cols], float _out[_cols]);

/**
 * Stampa su una riga gli elementi della diagonale secondaria.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 */
void stampaDiagonaleSecondaria(int _n, int _m[_n][_n]);

/**
 * Stampa gli elementi della matrice "a spirale" (verso orario, dall'angolo in alto a sinistra).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void stampaMatriceSpirale(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Riempie la matrice con i numeri 1, 2, 3, ... disposti a spirale (verso orario).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void riempiMatriceSpirale(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Crea il triangolo di Pascal (coefficienti binomiali) in una matrice n x n.
 * Gli elementi sopra la diagonale vengono messi a 0.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 */
void creaTriangoloPascal(int _n, int _m[_n][_n]);

/**
 * Ordina TUTTI gli elementi della matrice in modo crescente (riga per riga).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void ordinaMatriceCrescente(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Ordina in modo crescente ogni riga della matrice (separatamente).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 */
void ordinaRigheMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Ordina in modo crescente gli elementi di una singola colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna da ordinare.
 */
void ordinaColonnaMatrice(int _rows, int _cols, int _m[_rows][_cols], int _col);

/**
 * Calcola il minore (determinante della sottomatrice senza la riga e la colonna indicate).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga da togliere.
 * @param int Indice della colonna da togliere.
 * @return Valore del minore.
 */
long long calcolaMinore(int _n, int _m[_n][_n], int _riga, int _col);

/**
 * Calcola il complemento algebrico (cofattore): minore con segno (-1)^(riga+colonna).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga.
 * @param int Indice della colonna.
 * @return Valore del cofattore.
 */
long long calcolaCofattore(int _n, int _m[_n][_n], int _riga, int _col);

/**
 * Verifica se la matrice e' invertibile (determinante diverso da 0).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se invertibile, false altrimenti.
 */
bool verificaMatriceInvertibile(int _n, int _m[_n][_n]);

/**
 * Calcola la matrice inversa: (1 / det) * trasposta della matrice dei cofattori.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param float* Matrice risultato (n x n, di float).
 * @return true se l'inversa esiste, false se il determinante e' 0.
 */
bool calcolaMatriceInversa(int _n, int _m[_n][_n], float _ris[_n][_n]);

/**
 * Cerca un punto di sella: elemento minimo della propria riga e massimo della propria colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Puntatore dove salvare la riga trovata.
 * @param int* Puntatore dove salvare la colonna trovata.
 * @return true se esiste un punto di sella, false altrimenti.
 */
bool trovaPuntoSella(int _rows, int _cols, int _m[_rows][_cols], int *_riga, int *_col);

/**
 * Calcola la somma degli elementi "vicini" (fino a 8, quelli adiacenti anche in diagonale),
 * escluso l'elemento stesso. Gestisce correttamente bordi e angoli.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Riga dell'elemento.
 * @param int Colonna dell'elemento.
 * @return Somma dei vicini.
 */
int calcolaSommaVicini(int _rows, int _cols, int _m[_rows][_cols], int _riga, int _col);

/**
 * Ruota la matrice di 90 gradi in senso ANTIORARIO.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (cols x rows).
 */
void ruotaMatrice90Antiorario(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]);

/**
 * Calcola la somma degli elementi di una sottomatrice rettangolare
 * (estremi inclusi: dall'angolo (r1,c1) all'angolo (r2,c2)).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Riga dell'angolo in alto a sinistra.
 * @param int Colonna dell'angolo in alto a sinistra.
 * @param int Riga dell'angolo in basso a destra.
 * @param int Colonna dell'angolo in basso a destra.
 * @return Somma degli elementi della sottomatrice.
 */
int calcolaSommaSottomatrice(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _c1, int _r2, int _c2);

/**
 * Sostituisce ogni occorrenza di un valore con un altro.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore da sostituire.
 * @param int Nuovo valore.
 */
void sostituisciInMatrice(int _rows, int _cols, int _m[_rows][_cols], int _vecchio, int _nuovo);

/**
 * Conta gli elementi della matrice che sono numeri primi.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Numero di elementi primi.
 */
int contaPrimiMatrice(int _rows, int _cols, int _m[_rows][_cols]);

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//altro
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/* ============================================================
 *  UTILITY VETTORI
 * ============================================================ */

/**
 * @brief Stampa il vettore in formato colonna.
 * @details Itera da 0 a _n-1 stampando l'indice tra parentesi e il rispettivo valore a capo.
 */
void stampaVettoreColonna(int _n, int _v[_n]);

/**
 * @brief Stampa gli indici in cui compare un determinato valore.
 * @return Restituisce il numero totale di occorrenze trovate.
 */
int stampaPosizioniValore(int _n, int _v[_n], int _valore);

/**
 * @brief Restituisce il valore presente in una specifica posizione con controllo limiti.
 * @return Il valore trovato, oppure -1 se la posizione non è valida.
 */
int valoreInPosizione(int _n, int _v[_n], int _posizione);

/**
 * @brief Stampa solo una porzione (sottovettore) del vettore principale.
 * @details Verifica che gli indici di inizio e fine siano validi e compresi tra 0 e _n-1.
 */
bool stampaSottoVettore(int _n, int _v[_n], int _inizio, int _fine);


/* ============================================================
 *  UTILITY MATRICI
 * ============================================================ */

/**
 * @brief Riempie la matrice seguendo uno schema a scacchiera (pari/dispari).
 * @details Ogni cella alternata deve contenere un numero con la stessa parità dell'indice della cella.
 */
void caricaMatriceScacchiera(int _rows, int _cols, int _m[_rows][_cols]);


/* ============================================================
 *  MINIGIOCO: CATCH THE PIN
 * ============================================================ */

/** @brief Genera il codice segreto casuale (cifre da 0 a 9). */
void creaCodiceSegreto(int segreto[], int dim);

/** @brief Chiede all'utente di inserire una combinazione cifra per cifra con validazione. */
void richiediCodiceUtente(int utente[], int dim);

/** 
 * @brief Verifica la combinazione dell'utente rispetto a quella segreta.
 * @details Stampa il numero se è corretto nella posizione giusta, altrimenti un punto interrogativo '?'.
 * @return true se il codice è interamente indovinato, false altrimenti.
 */
bool verificaCodice(int segreto[], int utente[], int dim);


/* ============================================================
 *  MINIGIOCO: BATTAGLIA NAVALE
 * ============================================================ */

 // --- COSTANTI PER LA BATTAGLIA NAVALE ---
#define LATO 10    // Dimensione della griglia di gioco (10x10)
#define NUM_NAVI 4 // Numero totale di navi da posizionare

/** @brief Inizializza l'intera griglia di gioco ponendo tutto a 0 (acqua). */
void preparaCampo(int campo[LATO][LATO]);

/** 
 * @brief Posiziona casualmente le navi sulla griglia evitando sovrapposizioni e fuoriguida.
 * @details Gestisce navi di lunghezza variabile (es. 4, 3, 3, 2) in verticale o orizzontale.
 */
int piazzaNavi(int campo[LATO][LATO]);

/** 
 * @brief Stampa a schermo la griglia di gioco.
 * @details Traduce i numeri interni in caratteri visivi (~ acqua, o acqua colpita, X nave colpita, # nave).
 */
void stampaCampo(int campo[LATO][LATO], bool mostraNavi);

/** @brief Chiede all'utente le coordinate (riga e colonna) in cui sparare, convertendole da 1-based a 0-based. */
void chiediColpo(int *riga, int *colonna);

/** 
 * @brief Elabora il colpo sparato dall'utente.
 * @return 0 se è acqua, 1 se ha colpito una nave (aggiornando a 3), 2 se aveva già sparato lì.
 */
int controllaColpo(int campo[LATO][LATO], int riga, int colonna);

#endif /* FUNZIONI_H */