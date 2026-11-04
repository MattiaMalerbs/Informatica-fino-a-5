#include <stdbool.h>

/**
 * Riempie il vettore con numeri casuali compresi tra min e max (inclusi).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di elementi del vettore.
 * @param int Riferimento al vettore.
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
 * Riempie la matrice con numeri casuali compresi tra min e max (inclusi).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int Riferimento alla matrice.
 * @param int Valore minimo.
 * @param int Valore massimo.
 */
void riempiMatriceCasuale(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max);

/**
 * Stampa la matrice riga per riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int Riferimento alla matrice.
 */
void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Calcola la somma degli elementi di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int Riferimento alla matrice.
 * @param int Indice della riga.
 * @return Somma della riga.
 */
int calcolaSommaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga);

/**
 * Calcola e restituisce la somma di tutti gli elementi del vettore.
 * @param int Numero di elementi del vettore.
 * @param int Riferimento al vettore.
 * @return Somma degli elementi.
 */
int calcolaSommaVettore(int _n, int _v[_n]);

/**
 * Calcola la somma degli elementi di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int Riferimento alla matrice.
 * @param int Indice della riga.
 * @param int Numero di elementi del vettore.
 * @param int Riferimento al vettore.
 * @return Somma dei risultati.
 */

int trovaVetinMat(int _rows, int _cols, int _m[_rows][_cols], int _n, int _v[_n]);

/**
 * Calcola la somma degli elementi di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int Riferimento alla matrice.
 * @param int Indice della riga.
 * @param int Numero di elementi del vettore.
 * @param int Riferimento al vettore.
 * @return Somma di quanti sono uguali riga x riga.
 */

int trovaVetinMat_pt2(int _rows, int _cols, int _m[_rows][_cols], int _n, int _v[_n]);