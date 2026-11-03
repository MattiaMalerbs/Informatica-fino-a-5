/*
 * funzioni.c - Implementazione delle funzioni dichiarate in funzioni.h
 * Compilare con:  gcc -std=c99 -Wall main.c funzioni.c -o programma
 */

#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"


/* ============================================================
 *  1. VETTORI
 * ============================================================ */

/* ---------- 1.1 INPUT / OUTPUT ---------- */

void caricaVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &_v[i]);
    }
}

void riempiVettoreCasuale(int _n, int _v[_n], int _min, int _max) {
    for (int i = 0; i < _n; i++)
        _v[i] = rand() % (_max - _min + 1) + _min;   // numero tra min e max
}

void stampaVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _v[i]);
    printf("\n");
}

void copiaVettore(int _n, int _src[_n], int _dst[_n]) {
    for (int i = 0; i < _n; i++)
        _dst[i] = _src[i];
}


/* ---------- 1.2 STATISTICHE ---------- */

int calcolaSommaVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _v[i];
    return somma;
}

float calcolaMediaVettore(int _n, int _v[_n]) {
    return (float) calcolaSommaVettore(_n, _v) / _n;   // cast a float: niente divisione intera
}

int trovaMassimoVettore(int _n, int _v[_n]) {
    int max = _v[0];
    for (int i = 1; i < _n; i++)
        if (_v[i] > max) max = _v[i];
    return max;
}

int trovaMinimoVettore(int _n, int _v[_n]) {
    int min = _v[0];
    for (int i = 1; i < _n; i++)
        if (_v[i] < min) min = _v[i];
    return min;
}

int trovaPosMassimoVettore(int _n, int _v[_n]) {
    int pos = 0;
    for (int i = 1; i < _n; i++)
        if (_v[i] > _v[pos]) pos = i;
    return pos;
}

int trovaPosMinimoVettore(int _n, int _v[_n]) {
    int pos = 0;
    for (int i = 1; i < _n; i++)
        if (_v[i] < _v[pos]) pos = i;
    return pos;
}

int contaOccorrenzeVettore(int _n, int _v[_n], int _x) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] == _x) cont++;
    return cont;
}

int contaPariVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] % 2 == 0) cont++;
    return cont;
}

int contaDispariVettore(int _n, int _v[_n]) {
    return _n - contaPariVettore(_n, _v);
}

int contaPositiviVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] > 0) cont++;
    return cont;
}

int contaNegativiVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] < 0) cont++;
    return cont;
}

int contaMaggioriVettore(int _n, int _v[_n], int _soglia) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] > _soglia) cont++;
    return cont;
}

int contaPrimiVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (verificaPrimo(_v[i])) cont++;
    return cont;
}


/* ---------- 1.3 RICERCA ---------- */

int cercaInVettore(int _n, int _v[_n], int _x) {
    for (int i = 0; i < _n; i++)
        if (_v[i] == _x) return i;
    return -1;
}

int cercaBinariaVettore(int _n, int _v[_n], int _x) {
    int inizio = 0, fine = _n - 1;
    while (inizio <= fine) {
        int centro = (inizio + fine) / 2;
        if (_v[centro] == _x) return centro;
        else if (_v[centro] < _x) inizio = centro + 1;   // cerco a destra
        else fine = centro - 1;                          // cerco a sinistra
    }
    return -1;
}


/* ---------- 1.4 ORDINAMENTO ---------- */

void scambia(int *_a, int *_b) {
    int temp = *_a;
    *_a = *_b;
    *_b = temp;
}

void ordinaBubbleSort(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        for (int j = 0; j < _n - 1 - i; j++)
            if (_v[j] > _v[j + 1])
                scambia(&_v[j], &_v[j + 1]);
}

void ordinaBubbleSortDecr(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        for (int j = 0; j < _n - 1 - i; j++)
            if (_v[j] < _v[j + 1])
                scambia(&_v[j], &_v[j + 1]);
}

void ordinaSelectionSort(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++) {
        int posMin = i;                                  // cerco il minimo nella parte non ordinata
        for (int j = i + 1; j < _n; j++)
            if (_v[j] < _v[posMin]) posMin = j;
        scambia(&_v[i], &_v[posMin]);
    }
}

void ordinaInsertionSort(int _n, int _v[_n]) {
    for (int i = 1; i < _n; i++) {
        int chiave = _v[i];
        int j = i - 1;
        while (j >= 0 && _v[j] > chiave) {               // sposto a destra i maggiori
            _v[j + 1] = _v[j];
            j--;
        }
        _v[j + 1] = chiave;                              // inserisco nel punto giusto
    }
}


/* ---------- 1.5 MODIFICA ---------- */

void invertiVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n / 2; i++)
        scambia(&_v[i], &_v[_n - 1 - i]);
}

void ruotaDestraVettore(int _n, int _v[_n]) {
    int ultimo = _v[_n - 1];
    for (int i = _n - 1; i > 0; i--)
        _v[i] = _v[i - 1];
    _v[0] = ultimo;
}

void ruotaSinistraVettore(int _n, int _v[_n]) {
    int primo = _v[0];
    for (int i = 0; i < _n - 1; i++)
        _v[i] = _v[i + 1];
    _v[_n - 1] = primo;
}

void ruotaDestraKVettore(int _n, int _v[_n], int _k) {
    _k = ((_k % _n) + _n) % _n;                          // ruotare di n = non cambia nulla; k negativo = verso sinistra
    for (int i = 0; i < _k; i++)
        ruotaDestraVettore(_n, _v);
}

bool inserisciInVettore(int *_n, int _capacita, int _v[], int _pos, int _x) {
    if (_pos < 0 || _pos > *_n || *_n >= _capacita) return false;
    for (int i = *_n; i > _pos; i--)                     // faccio spazio spostando a destra
        _v[i] = _v[i - 1];
    _v[_pos] = _x;
    (*_n)++;
    return true;
}

bool eliminaDaVettore(int *_n, int _v[], int _pos) {
    if (_pos < 0 || _pos >= *_n) return false;
    for (int i = _pos; i < *_n - 1; i++)                 // chiudo il buco spostando a sinistra
        _v[i] = _v[i + 1];
    (*_n)--;
    return true;
}

void eliminaValoreVettore(int *_n, int _v[], int _x) {
    int i = 0;
    while (i < *_n) {
        if (_v[i] == _x) eliminaDaVettore(_n, _v, i);    // NON incremento i: ora c'e' un nuovo elemento
        else i++;
    }
}

void eliminaDuplicatiVettore(int *_n, int _v[]) {
    for (int i = 0; i < *_n; i++) {
        int j = i + 1;
        while (j < *_n) {
            if (_v[j] == _v[i]) eliminaDaVettore(_n, _v, j);
            else j++;
        }
    }
}

void sostituisciInVettore(int _n, int _v[_n], int _vecchio, int _nuovo) {
    for (int i = 0; i < _n; i++)
        if (_v[i] == _vecchio) _v[i] = _nuovo;
}


/* ---------- 1.6 OPERAZIONI TRA DUE VETTORI ---------- */

void sommaVettori(int _n, int _a[_n], int _b[_n], int _ris[_n]) {
    for (int i = 0; i < _n; i++)
        _ris[i] = _a[i] + _b[i];
}

void differenzaVettori(int _n, int _a[_n], int _b[_n], int _ris[_n]) {
    for (int i = 0; i < _n; i++)
        _ris[i] = _a[i] - _b[i];
}

int calcolaProdottoScalare(int _n, int _a[_n], int _b[_n]) {
    int ris = 0;
    for (int i = 0; i < _n; i++)
        ris += _a[i] * _b[i];
    return ris;
}

void moltiplicaVettoreScalare(int _n, int _v[_n], int _k) {
    for (int i = 0; i < _n; i++)
        _v[i] *= _k;
}

bool verificaVettoriUguali(int _na, int _a[_na], int _nb, int _b[_nb]) {
    if (_na != _nb) return false;                        // lunghezze diverse -> diversi
    for (int i = 0; i < _na; i++)
        if (_a[i] != _b[i]) return false;
    return true;
}

void fondiVettoriOrdinati(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    int i = 0, j = 0;
    *_nc = 0;
    while (i < _na && j < _nb) {                         // prendo sempre il piu' piccolo dei due
        if (_a[i] <= _b[j]) _c[(*_nc)++] = _a[i++];
        else                _c[(*_nc)++] = _b[j++];
    }
    while (i < _na) _c[(*_nc)++] = _a[i++];              // copio i rimasti di a
    while (j < _nb) _c[(*_nc)++] = _b[j++];              // copio i rimasti di b
}

void concatenaVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    *_nc = 0;
    for (int i = 0; i < _na; i++) _c[(*_nc)++] = _a[i];
    for (int i = 0; i < _nb; i++) _c[(*_nc)++] = _b[i];
}

void intersezioneVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    *_nc = 0;
    for (int i = 0; i < _na; i++)
        // lo aggiungo se e' anche in b e se non l'ho gia' aggiunto
        if (cercaInVettore(_nb, _b, _a[i]) != -1 && cercaInVettore(*_nc, _c, _a[i]) == -1)
            _c[(*_nc)++] = _a[i];
}


/* ---------- 1.7 CONTROLLI ---------- */

bool verificaVettoreCrescente(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        if (_v[i] > _v[i + 1]) return false;
    return true;
}

bool verificaVettoreDecrescente(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        if (_v[i] < _v[i + 1]) return false;
    return true;
}

bool verificaVettorePalindromo(int _n, int _v[_n]) {
    for (int i = 0; i < _n / 2; i++)
        if (_v[i] != _v[_n - 1 - i]) return false;
    return true;
}

bool verificaVettoreHaDuplicati(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            if (_v[i] == _v[j]) return true;
    return false;
}

bool verificaVettoreTuttiUguali(int _n, int _v[_n]) {
    for (int i = 1; i < _n; i++)
        if (_v[i] != _v[0]) return false;
    return true;
}

bool verificaPrimo(int _x) {
    if (_x < 2) return false;
    for (int d = 2; d <= _x / d; d++)                    // basta provare fino alla radice (d <= x/d evita l'overflow di d*d)
        if (_x % d == 0) return false;
    return true;
}


/* ============================================================
 *  2. MATRICI
 * ============================================================ */

/* ---------- 2.1 INPUT / OUTPUT ---------- */

void caricaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &_m[i][j]);
        }
}

void riempiMatriceCasuale(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = rand() % (_max - _min + 1) + _min;
}

void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++)
            printf("%d\t", _m[i][j]);
        printf("\n");
    }
}

void copiaMatrice(int _rows, int _cols, int _src[_rows][_cols], int _dst[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _dst[i][j] = _src[i][j];
}

void riempiMatriceCon(int _rows, int _cols, int _m[_rows][_cols], int _valore) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = _valore;
}

void creaMatriceIdentita(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            _m[i][j] = (i == j) ? 1 : 0;
}


/* ---------- 2.2 STATISTICHE ---------- */

int calcolaSommaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int somma = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            somma += _m[i][j];
    return somma;
}

float calcolaMediaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    return (float) calcolaSommaMatrice(_rows, _cols, _m) / (_rows * _cols);
}

int trovaMassimoMatrice(int _rows, int _cols, int _m[_rows][_cols], int *_riga, int *_col) {
    int max = _m[0][0];
    *_riga = 0;
    *_col = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] > max) {
                max = _m[i][j];
                *_riga = i;
                *_col = j;
            }
    return max;
}

int trovaMinimoMatrice(int _rows, int _cols, int _m[_rows][_cols], int *_riga, int *_col) {
    int min = _m[0][0];
    *_riga = 0;
    *_col = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] < min) {
                min = _m[i][j];
                *_riga = i;
                *_col = j;
            }
    return min;
}

int contaOccorrenzeMatrice(int _rows, int _cols, int _m[_rows][_cols], int _x) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] == _x) cont++;
    return cont;
}

int contaPariMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] % 2 == 0) cont++;
    return cont;
}

bool cercaInMatrice(int _rows, int _cols, int _m[_rows][_cols], int _x, int *_riga, int *_col) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] == _x) {
                *_riga = i;
                *_col = j;
                return true;
            }
    return false;
}


/* ---------- 2.3 RIGHE, COLONNE, DIAGONALI ---------- */

int calcolaSommaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    int somma = 0;
    for (int j = 0; j < _cols; j++)
        somma += _m[_riga][j];
    return somma;
}

int calcolaSommaColonna(int _rows, int _cols, int _m[_rows][_cols], int _col) {
    int somma = 0;
    for (int i = 0; i < _rows; i++)
        somma += _m[i][_col];
    return somma;
}

void calcolaSommeRighe(int _rows, int _cols, int _m[_rows][_cols], int _out[_rows]) {
    for (int i = 0; i < _rows; i++)
        _out[i] = calcolaSommaRiga(_rows, _cols, _m, i);
}

void calcolaSommeColonne(int _rows, int _cols, int _m[_rows][_cols], int _out[_cols]) {
    for (int j = 0; j < _cols; j++)
        _out[j] = calcolaSommaColonna(_rows, _cols, _m, j);
}

int trovaRigaSommaMax(int _rows, int _cols, int _m[_rows][_cols]) {
    int pos = 0;
    for (int i = 1; i < _rows; i++)
        if (calcolaSommaRiga(_rows, _cols, _m, i) > calcolaSommaRiga(_rows, _cols, _m, pos)) pos = i;
    return pos;
}

int trovaColonnaSommaMax(int _rows, int _cols, int _m[_rows][_cols]) {
    int pos = 0;
    for (int j = 1; j < _cols; j++)
        if (calcolaSommaColonna(_rows, _cols, _m, j) > calcolaSommaColonna(_rows, _cols, _m, pos)) pos = j;
    return pos;
}

int trovaMassimoRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    int max = _m[_riga][0];
    for (int j = 1; j < _cols; j++)
        if (_m[_riga][j] > max) max = _m[_riga][j];
    return max;
}

int trovaMassimoColonna(int _rows, int _cols, int _m[_rows][_cols], int _col) {
    int max = _m[0][_col];
    for (int i = 1; i < _rows; i++)
        if (_m[i][_col] > max) max = _m[i][_col];
    return max;
}

int calcolaSommaDiagonalePrincipale(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _m[i][i];                               // riga == colonna
    return somma;
}

int calcolaSommaDiagonaleSecondaria(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _m[i][_n - 1 - i];                      // riga + colonna == n - 1
    return somma;
}

int calcolaSommaSopraDiagonale(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            somma += _m[i][j];
    return somma;
}

int calcolaSommaSottoDiagonale(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 1; i < _n; i++)
        for (int j = 0; j < i; j++)
            somma += _m[i][j];
    return somma;
}

int calcolaSommaPerimetro(int _rows, int _cols, int _m[_rows][_cols]) {
    int somma = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (i == 0 || i == _rows - 1 || j == 0 || j == _cols - 1)
                somma += _m[i][j];
    return somma;
}

void stampaDiagonalePrincipale(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _m[i][i]);
    printf("\n");
}


/* ---------- 2.4 OPERAZIONI TRA MATRICI ---------- */

void sommaMatrici(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols], int _ris[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[i][j] = _a[i][j] + _b[i][j];
}

void differenzaMatrici(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols], int _ris[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[i][j] = _a[i][j] - _b[i][j];
}

void moltiplicaMatriceScalare(int _rows, int _cols, int _m[_rows][_cols], int _k) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] *= _k;
}

void prodottoMatrici(int _r1, int _c1, int _c2, int _a[_r1][_c1], int _b[_c1][_c2], int _ris[_r1][_c2]) {
    for (int i = 0; i < _r1; i++)
        for (int j = 0; j < _c2; j++) {
            _ris[i][j] = 0;
            for (int k = 0; k < _c1; k++)                // riga i di A per colonna j di B
                _ris[i][j] += _a[i][k] * _b[k][j];
        }
}

void prodottoMatriceVettore(int _rows, int _cols, int _m[_rows][_cols], int _v[_cols], int _ris[_rows]) {
    for (int i = 0; i < _rows; i++) {
        _ris[i] = 0;
        for (int j = 0; j < _cols; j++)
            _ris[i] += _m[i][j] * _v[j];
    }
}

void potenzaMatrice(int _n, int _m[_n][_n], int _k, int _ris[_n][_n]) {
    int temp[_n][_n];
    creaMatriceIdentita(_n, _ris);                       // m^0 = identita'
    for (int p = 0; p < _k; p++) {
        prodottoMatrici(_n, _n, _n, _ris, _m, temp);
        copiaMatrice(_n, _n, temp, _ris);
    }
}

bool verificaMatriciUguali(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_a[i][j] != _b[i][j]) return false;
    return true;
}


/* ---------- 2.5 TRASFORMAZIONI ---------- */

void calcolaTrasposta(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[j][i] = _m[i][j];
}

void traspostaSulPosto(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)                 // solo sopra la diagonale, altrimenti riscambio
            scambia(&_m[i][j], &_m[j][i]);
}

void scambiaRigheMatrice(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _r2) {
    for (int j = 0; j < _cols; j++)
        scambia(&_m[_r1][j], &_m[_r2][j]);
}

void scambiaColonneMatrice(int _rows, int _cols, int _m[_rows][_cols], int _c1, int _c2) {
    for (int i = 0; i < _rows; i++)
        scambia(&_m[i][_c1], &_m[i][_c2]);
}

void ruotaMatrice90Orario(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[j][_rows - 1 - i] = _m[i][j];
}

void specchiaMatriceOrizzontale(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols / 2; j++)
            scambia(&_m[i][j], &_m[i][_cols - 1 - j]);
}

void specchiaMatriceVerticale(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows / 2; i++)
        scambiaRigheMatrice(_rows, _cols, _m, i, _rows - 1 - i);
}

void ordinaRigaMatrice(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    (void) _rows;
    for (int i = 0; i < _cols - 1; i++)
        for (int j = 0; j < _cols - 1 - i; j++)
            if (_m[_riga][j] > _m[_riga][j + 1])
                scambia(&_m[_riga][j], &_m[_riga][j + 1]);
}

void copiaMatriceSenzaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga, int _out[_rows - 1][_cols]) {
    int ri = 0;                                          // indice di riga nel risultato
    for (int i = 0; i < _rows; i++) {
        if (i == _riga) continue;
        for (int j = 0; j < _cols; j++)
            _out[ri][j] = _m[i][j];
        ri++;
    }
}

void copiaMatriceSenzaColonna(int _rows, int _cols, int _m[_rows][_cols], int _col, int _out[_rows][_cols - 1]) {
    for (int i = 0; i < _rows; i++) {
        int cj = 0;                                      // indice di colonna nel risultato
        for (int j = 0; j < _cols; j++) {
            if (j == _col) continue;
            _out[i][cj++] = _m[i][j];
        }
    }
}


/* ---------- 2.6 CONTROLLI SUL TIPO DI MATRICE ---------- */

bool verificaMatriceSimmetrica(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            if (_m[i][j] != _m[j][i]) return false;
    return true;
}

bool verificaMatriceDiagonale(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            if (i != j && _m[i][j] != 0) return false;
    return true;
}

bool verificaMatriceIdentita(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++) {
            if (i == j && _m[i][j] != 1) return false;
            if (i != j && _m[i][j] != 0) return false;
        }
    return true;
}

bool verificaMatriceTriangolareSup(int _n, int _m[_n][_n]) {
    for (int i = 1; i < _n; i++)
        for (int j = 0; j < i; j++)
            if (_m[i][j] != 0) return false;
    return true;
}

bool verificaMatriceTriangolareInf(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            if (_m[i][j] != 0) return false;
    return true;
}

bool verificaMatriceNulla(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] != 0) return false;
    return true;
}

bool verificaQuadratoMagico(int _n, int _m[_n][_n]) {
    int s = calcolaSommaDiagonalePrincipale(_n, _m);     // somma di riferimento
    if (calcolaSommaDiagonaleSecondaria(_n, _m) != s) return false;
    for (int i = 0; i < _n; i++) {
        if (calcolaSommaRiga(_n, _n, _m, i) != s) return false;
        if (calcolaSommaColonna(_n, _n, _m, i) != s) return false;
    }
    return true;
}

bool verificaMatriceElementiDiversi(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            for (int k = 0; k < _rows; k++)
                for (int l = 0; l < _cols; l++)
                    if ((i != k || j != l) && _m[i][j] == _m[k][l]) return false;
    return true;
}


/* ---------- 2.7 DETERMINANTE ---------- */

long long calcolaDeterminante(int _n, int _m[_n][_n]) {
    if (_n == 1) return _m[0][0];                        // casi base
    if (_n == 2) return (long long) _m[0][0] * _m[1][1] - (long long) _m[0][1] * _m[1][0];

    long long det = 0;
    int minore[_n - 1][_n - 1];                          // sottomatrice (n-1) x (n-1)

    for (int col = 0; col < _n; col++) {
        // costruisco il minore togliendo la riga 0 e la colonna "col"
        for (int i = 1; i < _n; i++) {
            int cm = 0;
            for (int j = 0; j < _n; j++) {
                if (j == col) continue;
                minore[i - 1][cm++] = _m[i][j];
            }
        }
        int segno = (col % 2 == 0) ? 1 : -1;             // segni alternati + - + - ...
        det += segno * (long long) _m[0][col] * calcolaDeterminante(_n - 1, minore);
    }
    return det;
}


/* ---------- 2.8 CONVERSIONI VETTORE <-> MATRICE ---------- */

void matriceInVettore(int _rows, int _cols, int _m[_rows][_cols], int _v[_rows * _cols]) {
    int k = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _v[k++] = _m[i][j];
}

void vettoreInMatrice(int _rows, int _cols, int _v[_rows * _cols], int _m[_rows][_cols]) {
    int k = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = _v[k++];
}


/* ============================================================
 *  3. FUNZIONI EXTRA
 * ============================================================ */

/* ---------- 3.1 NUMERI E UTILITA' ---------- */

int calcolaMCD(int _a, int _b) {
    if (_a < 0) _a = -_a;
    if (_b < 0) _b = -_b;
    while (_b != 0) {                                    // Euclide: MCD(a,b) = MCD(b, a%b)
        int resto = _a % _b;
        _a = _b;
        _b = resto;
    }
    return _a;
}

int calcolaMCM(int _a, int _b) {
    if (_a == 0 || _b == 0) return 0;
    int mcd = calcolaMCD(_a, _b);
    int mcm = _a / mcd * _b;                             // divido prima per evitare overflow
    return mcm < 0 ? -mcm : mcm;
}

int calcolaMCDVettore(int _n, int _v[_n]) {
    int mcd = _v[0];
    for (int i = 1; i < _n; i++)
        mcd = calcolaMCD(mcd, _v[i]);
    return mcd;
}

long long calcolaFattoriale(int _x) {
    long long ris = 1;
    for (int i = 2; i <= _x; i++)
        ris *= i;
    return ris;
}

int contaCifre(int _x) {
    if (_x < 0) _x = -_x;
    int cifre = 1;                                       // lo 0 ha 1 cifra
    while (_x >= 10) {
        _x /= 10;
        cifre++;
    }
    return cifre;
}

int calcolaSommaCifre(int _x) {
    if (_x < 0) _x = -_x;
    int somma = 0;
    while (_x > 0) {
        somma += _x % 10;                                // ultima cifra
        _x /= 10;                                        // tolgo l'ultima cifra
    }
    return somma;
}

int invertiNumero(int _x) {
    int segno = 1;
    if (_x < 0) { segno = -1; _x = -_x; }
    int ris = 0;
    while (_x > 0) {
        ris = ris * 10 + _x % 10;                        // aggiungo l'ultima cifra in coda
        _x /= 10;
    }
    return segno * ris;
}

bool verificaNumeroPalindromo(int _x) {
    return _x >= 0 && invertiNumero(_x) == _x;
}

void numeroInVettoreCifre(int _x, int _v[], int *_n) {
    if (_x < 0) _x = -_x;
    *_n = contaCifre(_x);
    for (int i = *_n - 1; i >= 0; i--) {                 // riempio da destra verso sinistra
        _v[i] = _x % 10;
        _x /= 10;
    }
}

long long vettoreCifreInNumero(int _n, int _v[_n]) {
    long long ris = 0;
    for (int i = 0; i < _n; i++)
        ris = ris * 10 + _v[i];
    return ris;
}

void convertiNumeroInBase(int _x, int _base, int _v[], int *_n) {
    int tmp[64];
    int k = 0;
    if (_x == 0) tmp[k++] = 0;
    while (_x > 0) {                                     // i resti escono dal meno significativo
        tmp[k++] = _x % _base;
        _x /= _base;
    }
    *_n = k;
    for (int i = 0; i < k; i++)                          // li metto in ordine inverso
        _v[i] = tmp[k - 1 - i];
}

void generaFibonacciVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        _v[i] = (i < 2) ? i : _v[i - 1] + _v[i - 2];     // 0, 1, poi somma dei due precedenti
}

void generaPrimiVettore(int _n, int _v[_n]) {
    int trovati = 0, candidato = 2;
    while (trovati < _n) {
        if (verificaPrimo(candidato))
            _v[trovati++] = candidato;
        candidato++;
    }
}


/* ---------- 3.2 VETTORI EXTRA ---------- */

void riempiVettoreCasualeUnici(int _n, int _v[_n], int _min, int _max) {
    for (int i = 0; i < _n; i++) {
        int x;
        do {
            x = rand() % (_max - _min + 1) + _min;
        } while (cercaInVettore(i, _v, x) != -1);        // ripeto finche' e' gia' presente
        _v[i] = x;
    }
}

void stampaVettoreInverso(int _n, int _v[_n]) {
    for (int i = _n - 1; i >= 0; i--)
        printf("%d ", _v[i]);
    printf("\n");
}

int trovaSecondoMassimoVettore(int _n, int _v[_n]) {
    int max = trovaMassimoVettore(_n, _v);
    int secondo = max;
    bool trovato = false;
    for (int i = 0; i < _n; i++)
        if (_v[i] < max && (!trovato || _v[i] > secondo)) {
            secondo = _v[i];
            trovato = true;
        }
    return secondo;
}

int calcolaModaVettore(int _n, int _v[_n]) {
    int moda = _v[0];
    int maxOcc = 0;
    for (int i = 0; i < _n; i++) {
        int occ = contaOccorrenzeVettore(_n, _v, _v[i]);
        if (occ > maxOcc) {                              // ">" stretto: a parita' resta il primo
            maxOcc = occ;
            moda = _v[i];
        }
    }
    return moda;
}

float calcolaMedianaVettore(int _n, int _v[_n]) {
    int tmp[_n];                                         // lavoro su una copia
    copiaVettore(_n, _v, tmp);
    ordinaInsertionSort(_n, tmp);
    if (_n % 2 == 1) return tmp[_n / 2];                 // dispari: elemento centrale
    return (tmp[_n / 2 - 1] + tmp[_n / 2]) / 2.0f;       // pari: media dei due centrali
}

int calcolaDifferenzaMaxMin(int _n, int _v[_n]) {
    return trovaMassimoVettore(_n, _v) - trovaMinimoVettore(_n, _v);
}

int calcolaSommaPosizioniPariVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i += 2)
        somma += _v[i];
    return somma;
}

int calcolaSommaPosizioniDispariVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 1; i < _n; i += 2)
        somma += _v[i];
    return somma;
}

void calcolaSommeCumulativeVettore(int _n, int _v[_n], int _out[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++) {
        somma += _v[i];
        _out[i] = somma;
    }
}

int trovaLunghezzaSequenzaCrescenteMax(int _n, int _v[_n]) {
    if (_n == 0) return 0;
    int max = 1, corrente = 1;
    for (int i = 1; i < _n; i++) {
        if (_v[i] > _v[i - 1]) corrente++;               // la sequenza continua
        else corrente = 1;                               // si interrompe: ricomincio
        if (corrente > max) max = corrente;
    }
    return max;
}

int cercaSottovettore(int _n, int _v[_n], int _m, int _sub[_m]) {
    for (int i = 0; i + _m <= _n; i++) {
        bool uguale = true;
        for (int j = 0; j < _m && uguale; j++)
            if (_v[i + j] != _sub[j]) uguale = false;
        if (uguale) return i;
    }
    return -1;
}

bool verificaVettoriPermutazione(int _na, int _a[_na], int _nb, int _b[_nb]) {
    if (_na != _nb) return false;
    for (int i = 0; i < _na; i++)                        // ogni valore deve comparire lo stesso numero di volte
        if (contaOccorrenzeVettore(_na, _a, _a[i]) != contaOccorrenzeVettore(_nb, _b, _a[i]))
            return false;
    return true;
}

void unioneVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    *_nc = 0;
    for (int i = 0; i < _na; i++)
        if (cercaInVettore(*_nc, _c, _a[i]) == -1) _c[(*_nc)++] = _a[i];
    for (int i = 0; i < _nb; i++)
        if (cercaInVettore(*_nc, _c, _b[i]) == -1) _c[(*_nc)++] = _b[i];
}

void separaPariDispari(int _n, int _v[_n], int _pari[], int *_np, int _dispari[], int *_nd) {
    *_np = 0;
    *_nd = 0;
    for (int i = 0; i < _n; i++) {
        if (_v[i] % 2 == 0) _pari[(*_np)++] = _v[i];
        else                _dispari[(*_nd)++] = _v[i];
    }
}

void spostaZeriInFondoVettore(int _n, int _v[_n]) {
    int k = 0;                                           // prossima posizione per un non-zero
    for (int i = 0; i < _n; i++)
        if (_v[i] != 0) _v[k++] = _v[i];
    while (k < _n) _v[k++] = 0;                          // riempio il resto di zeri
}

bool inserisciOrdinatoVettore(int *_n, int _capacita, int _v[], int _x) {
    int pos = 0;
    while (pos < *_n && _v[pos] < _x)                    // trovo il primo elemento >= x
        pos++;
    return inserisciInVettore(_n, _capacita, _v, pos, _x);
}


/* ---------- 3.3 MATRICI EXTRA ---------- */

int calcolaTraccia(int _n, int _m[_n][_n]) {
    return calcolaSommaDiagonalePrincipale(_n, _m);
}

void calcolaMassimiRighe(int _rows, int _cols, int _m[_rows][_cols], int _out[_rows]) {
    for (int i = 0; i < _rows; i++)
        _out[i] = trovaMassimoRiga(_rows, _cols, _m, i);
}

void calcolaMassimiColonne(int _rows, int _cols, int _m[_rows][_cols], int _out[_cols]) {
    for (int j = 0; j < _cols; j++)
        _out[j] = trovaMassimoColonna(_rows, _cols, _m, j);
}

void calcolaMedieRighe(int _rows, int _cols, int _m[_rows][_cols], float _out[_rows]) {
    for (int i = 0; i < _rows; i++)
        _out[i] = (float) calcolaSommaRiga(_rows, _cols, _m, i) / _cols;
}

void calcolaMedieColonne(int _rows, int _cols, int _m[_rows][_cols], float _out[_cols]) {
    for (int j = 0; j < _cols; j++)
        _out[j] = (float) calcolaSommaColonna(_rows, _cols, _m, j) / _rows;
}

void stampaDiagonaleSecondaria(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _m[i][_n - 1 - i]);
    printf("\n");
}

void stampaMatriceSpirale(int _rows, int _cols, int _m[_rows][_cols]) {
    int alto = 0, basso = _rows - 1, sinistra = 0, destra = _cols - 1;
    while (alto <= basso && sinistra <= destra) {
        for (int j = sinistra; j <= destra; j++) printf("%d ", _m[alto][j]);      // verso destra
        alto++;
        for (int i = alto; i <= basso; i++) printf("%d ", _m[i][destra]);         // verso il basso
        destra--;
        if (alto <= basso) {
            for (int j = destra; j >= sinistra; j--) printf("%d ", _m[basso][j]); // verso sinistra
            basso--;
        }
        if (sinistra <= destra) {
            for (int i = basso; i >= alto; i--) printf("%d ", _m[i][sinistra]);   // verso l'alto
            sinistra++;
        }
    }
    printf("\n");
}

void riempiMatriceSpirale(int _rows, int _cols, int _m[_rows][_cols]) {
    int alto = 0, basso = _rows - 1, sinistra = 0, destra = _cols - 1;
    int k = 1;                                           // numero da scrivere
    while (alto <= basso && sinistra <= destra) {
        for (int j = sinistra; j <= destra; j++) _m[alto][j] = k++;
        alto++;
        for (int i = alto; i <= basso; i++) _m[i][destra] = k++;
        destra--;
        if (alto <= basso) {
            for (int j = destra; j >= sinistra; j--) _m[basso][j] = k++;
            basso--;
        }
        if (sinistra <= destra) {
            for (int i = basso; i >= alto; i--) _m[i][sinistra] = k++;
            sinistra++;
        }
    }
}

void creaTriangoloPascal(int _n, int _m[_n][_n]) {
    riempiMatriceCon(_n, _n, _m, 0);
    for (int i = 0; i < _n; i++) {
        _m[i][0] = 1;                                    // primo elemento di ogni riga = 1
        for (int j = 1; j <= i; j++)
            _m[i][j] = _m[i - 1][j - 1] + _m[i - 1][j];  // somma dei due elementi sopra
    }
}

void ordinaMatriceCrescente(int _rows, int _cols, int _m[_rows][_cols]) {
    int tmp[_rows * _cols];
    matriceInVettore(_rows, _cols, _m, tmp);             // "srotolo" la matrice in un vettore
    ordinaInsertionSort(_rows * _cols, tmp);             // ordino il vettore
    vettoreInMatrice(_rows, _cols, tmp, _m);             // lo rimetto nella matrice
}

void ordinaRigheMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        ordinaRigaMatrice(_rows, _cols, _m, i);
}

void ordinaColonnaMatrice(int _rows, int _cols, int _m[_rows][_cols], int _col) {
    for (int i = 0; i < _rows - 1; i++)
        for (int j = 0; j < _rows - 1 - i; j++)
            if (_m[j][_col] > _m[j + 1][_col])
                scambia(&_m[j][_col], &_m[j + 1][_col]);
}

long long calcolaMinore(int _n, int _m[_n][_n], int _riga, int _col) {
    if (_n == 1) return 1;                               // minore di una matrice 1x1
    int sub[_n - 1][_n - 1];
    int ri = 0;
    for (int i = 0; i < _n; i++) {
        if (i == _riga) continue;
        int cj = 0;
        for (int j = 0; j < _n; j++) {
            if (j == _col) continue;
            sub[ri][cj++] = _m[i][j];
        }
        ri++;
    }
    return calcolaDeterminante(_n - 1, sub);
}

long long calcolaCofattore(int _n, int _m[_n][_n], int _riga, int _col) {
    long long minore = calcolaMinore(_n, _m, _riga, _col);
    return ((_riga + _col) % 2 == 0) ? minore : -minore; // segno a scacchiera + - + -
}

bool verificaMatriceInvertibile(int _n, int _m[_n][_n]) {
    return calcolaDeterminante(_n, _m) != 0;
}

bool calcolaMatriceInversa(int _n, int _m[_n][_n], float _ris[_n][_n]) {
    long long det = calcolaDeterminante(_n, _m);
    if (det == 0) return false;
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            _ris[j][i] = (float) calcolaCofattore(_n, _m, i, j) / det;   // [j][i]: trasposta dei cofattori
    return true;
}

bool trovaPuntoSella(int _rows, int _cols, int _m[_rows][_cols], int *_riga, int *_col) {
    for (int i = 0; i < _rows; i++) {
        int minRiga = _m[i][0];                          // minimo della riga i
        for (int j = 1; j < _cols; j++)
            if (_m[i][j] < minRiga) minRiga = _m[i][j];
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] == minRiga && _m[i][j] == trovaMassimoColonna(_rows, _cols, _m, j)) {
                *_riga = i;
                *_col = j;
                return true;
            }
    }
    return false;
}

int calcolaSommaVicini(int _rows, int _cols, int _m[_rows][_cols], int _riga, int _col) {
    int somma = 0;
    for (int di = -1; di <= 1; di++)
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;            // salto l'elemento stesso
            int i = _riga + di, j = _col + dj;
            if (i >= 0 && i < _rows && j >= 0 && j < _cols)   // controllo di non uscire dalla matrice
                somma += _m[i][j];
        }
    return somma;
}

void ruotaMatrice90Antiorario(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[_cols - 1 - j][i] = _m[i][j];
}

int calcolaSommaSottomatrice(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _c1, int _r2, int _c2) {
    (void) _rows;
    (void) _cols;
    int somma = 0;
    for (int i = _r1; i <= _r2; i++)
        for (int j = _c1; j <= _c2; j++)
            somma += _m[i][j];
    return somma;
}

void sostituisciInMatrice(int _rows, int _cols, int _m[_rows][_cols], int _vecchio, int _nuovo) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] == _vecchio) _m[i][j] = _nuovo;
}

int contaPrimiMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (verificaPrimo(_m[i][j])) cont++;
    return cont;
}