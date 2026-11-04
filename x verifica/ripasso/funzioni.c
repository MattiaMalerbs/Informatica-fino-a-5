/*
 * ============================================================
 *  funzioni.c - Implementazione delle funzioni di funzioni.h
 *  Compilare con:  gcc -std=c99 -Wall main.c funzioni.c -o programma
 * ============================================================
 *  COME LEGGERE QUESTO FILE
 *   Sopra ogni funzione trovi:
 *    - cosa fa, con i parametri (@param) e il valore restituito (@return)
 *    - COME FUNZIONA: l'idea dell'algoritmo, in poche righe
 *    - ESEMPIO: come si chiama (n, v, m... sono i nomi delle TUE variabili)
 *   Le funzioni sono raggruppate nelle stesse sezioni del file .h.
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"


/* ============================================================
 *  1. VETTORI
 * ============================================================ */

/* ---------- 1.1 INPUT / OUTPUT ---------- */

/**
 * Carica il vettore chiedendo gli elementi da tastiera.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Un ciclo for da 0 a n-1: ad ogni giro stampa un messaggio e legge
 *   con scanf il valore dell'elemento i (scanf vuole l'indirizzo, per
 *   questo si scrive &v[i]).
 *
 * ESEMPIO:  caricaVettore(n, v);
 */
void caricaVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &_v[i]);
    }
}

/**
 * Riempie il vettore con numeri casuali compresi tra min e max (inclusi).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore minimo.
 * @param int Valore massimo.
 *
 * COME FUNZIONA:
 *   rand() % (max - min + 1) da' un numero tra 0 e (max - min);
 *   sommando min lo si sposta nell'intervallo [min, max]. Prima di
 *   usarla serve srand(time(0)) una volta nel main.
 *
 * ESEMPIO:  riempiVettoreCasuale(n, v, min, max);
 */
void riempiVettoreCasuale(int _n, int _v[_n], int _min, int _max) {
    for (int i = 0; i < _n; i++)
        _v[i] = rand() % (_max - _min + 1) + _min;   // numero tra min e max
}

/**
 * Stampa il vettore su una riga, elementi separati da spazio.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Ciclo for che stampa ogni elemento seguito da uno spazio, poi va a
 *   capo.
 *
 * ESEMPIO:  stampaVettore(n, v);
 */
void stampaVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _v[i]);
    printf("\n");
}

/**
 * Copia il vettore sorgente nel vettore destinazione.
 * @param int Numero di elementi.
 * @param int* Riferimento al vettore sorgente.
 * @param int* Riferimento al vettore destinazione.
 *
 * COME FUNZIONA:
 *   Ciclo for che copia elemento per elemento: dst[i] = src[i].
 *
 * ESEMPIO:  copiaVettore(n, src, dst);
 */
void copiaVettore(int _n, int _src[_n], int _dst[_n]) {
    for (int i = 0; i < _n; i++)
        _dst[i] = _src[i];
}


/* ---------- 1.2 STATISTICHE ---------- */

/**
 * Calcola e restituisce la somma di tutti gli elementi del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Somma degli elementi.
 *
 * COME FUNZIONA:
 *   Usa un accumulatore: parte da somma = 0 e con un ciclo aggiunge
 *   ogni elemento.
 *
 * ESEMPIO:  int risultato = calcolaSommaVettore(n, v);
 */
int calcolaSommaVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _v[i];
    return somma;
}

/**
 * Calcola e restituisce il valor medio del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Valor medio del vettore.
 *
 * COME FUNZIONA:
 *   Media = somma / n. Il cast (float) e' necessario: senza, int / int
 *   e' una divisione intera e perde i decimali.
 *
 * ESEMPIO:  float risultato = calcolaMediaVettore(n, v);
 */
float calcolaMediaVettore(int _n, int _v[_n]) {
    return (float) calcolaSommaVettore(_n, _v) / _n;   // cast a float: niente divisione intera
}

/**
 * Trova il valore massimo del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Valore massimo.
 *
 * COME FUNZIONA:
 *   Si assume che il massimo sia il primo elemento (non 0: i numeri
 *   potrebbero essere tutti negativi), poi si scorre il resto: se un
 *   elemento e' maggiore diventa il nuovo massimo.
 *
 * ESEMPIO:  int risultato = trovaMassimoVettore(n, v);
 */
int trovaMassimoVettore(int _n, int _v[_n]) {
    int max = _v[0];
    for (int i = 1; i < _n; i++)
        if (_v[i] > max) max = _v[i];
    return max;
}

/**
 * Trova il valore minimo del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Valore minimo.
 *
 * COME FUNZIONA:
 *   Si assume che il minimo sia il primo elemento, poi si scorre il
 *   resto: se un elemento e' minore diventa il nuovo minimo.
 *
 * ESEMPIO:  int risultato = trovaMinimoVettore(n, v);
 */
int trovaMinimoVettore(int _n, int _v[_n]) {
    int min = _v[0];
    for (int i = 1; i < _n; i++)
        if (_v[i] < min) min = _v[i];
    return min;
}

/**
 * Trova la posizione del massimo (la prima se ce ne sono piu' di uno).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Indice dell'elemento massimo.
 *
 * COME FUNZIONA:
 *   Come il massimo, ma si memorizza l'INDICE invece del valore. Il
 *   confronto e' con > stretto, quindi a parita' resta la prima
 *   posizione.
 *
 * ESEMPIO:  int risultato = trovaPosMassimoVettore(n, v);
 */
int trovaPosMassimoVettore(int _n, int _v[_n]) {
    int pos = 0;
    for (int i = 1; i < _n; i++)
        if (_v[i] > _v[pos]) pos = i;
    return pos;
}

/**
 * Trova la posizione del minimo (la prima se ce ne sono piu' di uno).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Indice dell'elemento minimo.
 *
 * COME FUNZIONA:
 *   Come il minimo, ma si memorizza l'INDICE invece del valore. Il
 *   confronto e' con < stretto, quindi a parita' resta la prima
 *   posizione.
 *
 * ESEMPIO:  int risultato = trovaPosMinimoVettore(n, v);
 */
int trovaPosMinimoVettore(int _n, int _v[_n]) {
    int pos = 0;
    for (int i = 1; i < _n; i++)
        if (_v[i] < _v[pos]) pos = i;
    return pos;
}

/**
 * Conta quante volte un valore compare nel vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da contare.
 * @return Numero di occorrenze.
 *
 * COME FUNZIONA:
 *   Contatore a 0: ogni volta che v[i] == x lo incrementa.
 *
 * ESEMPIO:  int risultato = contaOccorrenzeVettore(n, v, x);
 */
int contaOccorrenzeVettore(int _n, int _v[_n], int _x) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] == _x) cont++;
    return cont;
}

/**
 * Conta gli elementi pari del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi pari.
 *
 * COME FUNZIONA:
 *   v[i] % 2 == 0 significa resto zero nella divisione per 2, cioe'
 *   numero pari (vale anche per i negativi e per lo 0).
 *
 * ESEMPIO:  int risultato = contaPariVettore(n, v);
 */
int contaPariVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] % 2 == 0) cont++;
    return cont;
}

/**
 * Conta gli elementi dispari del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi dispari.
 *
 * COME FUNZIONA:
 *   I dispari sono tutti gli elementi meno i pari (n - contaPari). Non
 *   si usa % 2 == 1 perche' per i negativi il resto vale -1.
 *
 * ESEMPIO:  int risultato = contaDispariVettore(n, v);
 */
int contaDispariVettore(int _n, int _v[_n]) {
    return _n - contaPariVettore(_n, _v);
}

/**
 * Conta gli elementi positivi (> 0) del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi positivi.
 *
 * COME FUNZIONA:
 *   Contatore: incrementa quando v[i] > 0 (lo 0 non e' ne' positivo ne'
 *   negativo).
 *
 * ESEMPIO:  int risultato = contaPositiviVettore(n, v);
 */
int contaPositiviVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] > 0) cont++;
    return cont;
}

/**
 * Conta gli elementi negativi (< 0) del vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi negativi.
 *
 * COME FUNZIONA:
 *   Contatore: incrementa quando v[i] < 0.
 *
 * ESEMPIO:  int risultato = contaNegativiVettore(n, v);
 */
int contaNegativiVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] < 0) cont++;
    return cont;
}

/**
 * Conta gli elementi strettamente maggiori di una soglia.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Soglia.
 * @return Numero di elementi maggiori della soglia.
 *
 * COME FUNZIONA:
 *   Contatore: incrementa quando v[i] e' strettamente maggiore della
 *   soglia.
 *
 * ESEMPIO:  int risultato = contaMaggioriVettore(n, v, soglia);
 */
int contaMaggioriVettore(int _n, int _v[_n], int _soglia) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] > _soglia) cont++;
    return cont;
}

/**
 * Conta gli elementi del vettore che sono numeri primi.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di elementi primi.
 *
 * COME FUNZIONA:
 *   Per ogni elemento chiama verificaPrimo e conta quelli per cui e'
 *   vera.
 *
 * ESEMPIO:  int risultato = contaPrimiVettore(n, v);
 */
int contaPrimiVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (verificaPrimo(_v[i])) cont++;
    return cont;
}


/* ---------- 1.3 RICERCA ---------- */

/**
 * Ricerca lineare: cerca un valore scorrendo il vettore dall'inizio.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da cercare.
 * @return Indice della prima occorrenza, oppure -1 se non presente.
 *
 * COME FUNZIONA:
 *   Ricerca lineare: scorre il vettore e al primo elemento uguale a x
 *   restituisce subito l'indice (return interrompe la funzione). Se il
 *   ciclo finisce senza trovarlo restituisce -1.
 *
 * ESEMPIO:  int risultato = cercaInVettore(n, v, x);
 */
int cercaInVettore(int _n, int _v[_n], int _x) {
    for (int i = 0; i < _n; i++)
        if (_v[i] == _x) return i;
    return -1;
}

/**
 * Ricerca binaria: il vettore DEVE essere ordinato in modo crescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore (ordinato crescente).
 * @param int Valore da cercare.
 * @return Indice del valore, oppure -1 se non presente.
 *
 * COME FUNZIONA:
 *   Ad ogni passo guarda l'elemento centrale: se e' x ha finito, se e'
 *   minore di x cerca solo nella meta' destra, altrimenti solo nella
 *   sinistra (l'intervallo si dimezza ad ogni giro). Funziona SOLO se
 *   il vettore e' ordinato crescente.
 *
 * ESEMPIO:  int risultato = cercaBinariaVettore(n, v, x);
 */
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

/**
 * Scambia il valore di due interi.
 * @param int* Puntatore al primo intero.
 * @param int* Puntatore al secondo intero.
 *
 * COME FUNZIONA:
 *   Usa una variabile temporanea: temp = a; a = b; b = temp. Riceve
 *   puntatori (int *), quindi si chiama con scambia(&x, &y) e modifica
 *   le variabili originali.
 *
 * ESEMPIO:  scambia(&a, &b);
 */
void scambia(int *_a, int *_b) {
    int temp = *_a;
    *_a = *_b;
    *_b = temp;
}

/**
 * Ordina il vettore in modo CRESCENTE con il Bubble Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Confronta coppie vicine v[j] e v[j+1] e le scambia se sono
 *   nell'ordine sbagliato. Dopo ogni giro del ciclo esterno l'elemento
 *   piu' grande 'sale' in fondo, per questo il ciclo interno si
 *   accorcia di i.
 *
 * ESEMPIO:  ordinaBubbleSort(n, v);
 */
void ordinaBubbleSort(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        for (int j = 0; j < _n - 1 - i; j++)
            if (_v[j] > _v[j + 1])
                scambia(&_v[j], &_v[j + 1]);
}

/**
 * Ordina il vettore in modo DECRESCENTE con il Bubble Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Uguale al bubble sort crescente, ma scambia quando v[j] < v[j+1]: i
 *   valori piu' grandi restano all'inizio.
 *
 * ESEMPIO:  ordinaBubbleSortDecr(n, v);
 */
void ordinaBubbleSortDecr(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        for (int j = 0; j < _n - 1 - i; j++)
            if (_v[j] < _v[j + 1])
                scambia(&_v[j], &_v[j + 1]);
}

/**
 * Ordina il vettore in modo CRESCENTE con il Selection Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Ad ogni giro i cerca il minimo tra la posizione i e la fine e lo
 *   scambia con v[i]: la parte sinistra del vettore e' cosi' sempre
 *   ordinata.
 *
 * ESEMPIO:  ordinaSelectionSort(n, v);
 */
void ordinaSelectionSort(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++) {
        int posMin = i;                                  // cerco il minimo nella parte non ordinata
        for (int j = i + 1; j < _n; j++)
            if (_v[j] < _v[posMin]) posMin = j;
        scambia(&_v[i], &_v[posMin]);
    }
}

/**
 * Ordina il vettore in modo CRESCENTE con l'Insertion Sort.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Prende l'elemento v[i], sposta a destra tutti i precedenti piu'
 *   grandi di lui e lo inserisce nel buco: come ordinare le carte che
 *   hai in mano.
 *
 * ESEMPIO:  ordinaInsertionSort(n, v);
 */
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

/**
 * Inverte l'ordine degli elementi (il primo diventa l'ultimo, ecc.).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Scambia il primo con l'ultimo, il secondo col penultimo, ecc. Basta
 *   arrivare a meta' (n/2): andando oltre si scambierebbe tutto una
 *   seconda volta e il vettore tornerebbe uguale.
 *
 * ESEMPIO:  invertiVettore(n, v);
 */
void invertiVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n / 2; i++)
        scambia(&_v[i], &_v[_n - 1 - i]);
}

/**
 * Ruota il vettore a destra di una posizione (l'ultimo diventa il primo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Salva l'ultimo elemento, sposta tutti gli altri di una posizione a
 *   destra (partendo dalla fine per non sovrascriverli) e mette
 *   l'elemento salvato in posizione 0.
 *
 * ESEMPIO:  ruotaDestraVettore(n, v);
 */
void ruotaDestraVettore(int _n, int _v[_n]) {
    int ultimo = _v[_n - 1];
    for (int i = _n - 1; i > 0; i--)
        _v[i] = _v[i - 1];
    _v[0] = ultimo;
}

/**
 * Ruota il vettore a sinistra di una posizione (il primo diventa l'ultimo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Salva il primo elemento, sposta tutti gli altri di una posizione a
 *   sinistra (partendo dall'inizio) e mette l'elemento salvato in
 *   fondo.
 *
 * ESEMPIO:  ruotaSinistraVettore(n, v);
 */
void ruotaSinistraVettore(int _n, int _v[_n]) {
    int primo = _v[0];
    for (int i = 0; i < _n - 1; i++)
        _v[i] = _v[i + 1];
    _v[_n - 1] = primo;
}

/**
 * Ruota il vettore a destra di k posizioni.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero di posizioni di cui ruotare.
 *
 * COME FUNZIONA:
 *   Ripete k volte la rotazione di 1. Con k % n si evitano giri inutili
 *   (ruotare di n posizioni riporta al vettore iniziale); un k negativo
 *   diventa una rotazione a sinistra equivalente.
 *
 * ESEMPIO:  ruotaDestraKVettore(n, v, k);
 */
void ruotaDestraKVettore(int _n, int _v[_n], int _k) {
    _k = ((_k % _n) + _n) % _n;                          // ruotare di n = non cambia nulla; k negativo = verso sinistra
    for (int i = 0; i < _k; i++)
        ruotaDestraVettore(_n, _v);
}

/**
 * Inserisce un valore in una posizione, spostando a destra gli altri elementi.
 * @param int* Puntatore al numero di elementi (viene aumentato di 1).
 * @param int Capacita' massima del vettore.
 * @param int* Riferimento al vettore.
 * @param int Posizione in cui inserire (da 0 a n compreso).
 * @param int Valore da inserire.
 * @return true se l'inserimento e' riuscito, false se posizione non valida o vettore pieno.
 *
 * COME FUNZIONA:
 *   Controlla che la posizione sia valida e che ci sia spazio; poi
 *   sposta a destra gli elementi dalla fine fino a pos per fare spazio,
 *   scrive x in pos e aumenta n.
 *
 * ESEMPIO:  bool risultato = inserisciInVettore(&n, capacita, v, pos, x);
 */
bool inserisciInVettore(int *_n, int _capacita, int _v[], int _pos, int _x) {
    if (_pos < 0 || _pos > *_n || *_n >= _capacita) return false;
    for (int i = *_n; i > _pos; i--)                     // faccio spazio spostando a destra
        _v[i] = _v[i - 1];
    _v[_pos] = _x;
    (*_n)++;
    return true;
}

/**
 * Elimina l'elemento in una posizione, spostando a sinistra gli altri.
 * @param int* Puntatore al numero di elementi (viene diminuito di 1).
 * @param int* Riferimento al vettore.
 * @param int Posizione dell'elemento da eliminare.
 * @return true se l'eliminazione e' riuscita, false se la posizione non e' valida.
 *
 * COME FUNZIONA:
 *   Sposta a sinistra di una posizione tutti gli elementi dopo pos
 *   (sovrascrivendo quello da eliminare) e diminuisce n.
 *
 * ESEMPIO:  bool risultato = eliminaDaVettore(&n, v, pos);
 */
bool eliminaDaVettore(int *_n, int _v[], int _pos) {
    if (_pos < 0 || _pos >= *_n) return false;
    for (int i = _pos; i < *_n - 1; i++)                 // chiudo il buco spostando a sinistra
        _v[i] = _v[i + 1];
    (*_n)--;
    return true;
}

/**
 * Elimina TUTTE le occorrenze di un valore dal vettore.
 * @param int* Puntatore al numero di elementi (viene aggiornato).
 * @param int* Riferimento al vettore.
 * @param int Valore da eliminare.
 *
 * COME FUNZIONA:
 *   Scorre il vettore: quando trova x lo elimina SENZA incrementare i
 *   (in posizione i e' arrivato un nuovo elemento ancora da
 *   controllare), altrimenti passa al successivo.
 *
 * ESEMPIO:  eliminaValoreVettore(&n, v, x);
 */
void eliminaValoreVettore(int *_n, int _v[], int _x) {
    int i = 0;
    while (i < *_n) {
        if (_v[i] == _x) eliminaDaVettore(_n, _v, i);    // NON incremento i: ora c'e' un nuovo elemento
        else i++;
    }
}

/**
 * Elimina i duplicati, lasciando solo la prima occorrenza di ogni valore.
 * @param int* Puntatore al numero di elementi (viene aggiornato).
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Per ogni elemento i guarda tutti i successivi j ed elimina quelli
 *   uguali: resta solo la prima occorrenza di ogni valore.
 *
 * ESEMPIO:  eliminaDuplicatiVettore(&n, v);
 */
void eliminaDuplicatiVettore(int *_n, int _v[]) {
    for (int i = 0; i < *_n; i++) {
        int j = i + 1;
        while (j < *_n) {
            if (_v[j] == _v[i]) eliminaDaVettore(_n, _v, j);
            else j++;
        }
    }
}

/**
 * Sostituisce ogni occorrenza di un valore con un altro.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da sostituire.
 * @param int Nuovo valore.
 *
 * COME FUNZIONA:
 *   Scorre il vettore e ogni volta che trova il valore vecchio lo
 *   sovrascrive con il nuovo.
 *
 * ESEMPIO:  sostituisciInVettore(n, v, vecchio, nuovo);
 */
void sostituisciInVettore(int _n, int _v[_n], int _vecchio, int _nuovo) {
    for (int i = 0; i < _n; i++)
        if (_v[i] == _vecchio) _v[i] = _nuovo;
}


/* ---------- 1.6 OPERAZIONI TRA DUE VETTORI ---------- */

/**
 * Somma due vettori elemento per elemento: ris[i] = a[i] + b[i].
 * @param int Numero di elementi dei vettori.
 * @param int* Primo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato.
 *
 * COME FUNZIONA:
 *   ris[i] = a[i] + b[i] per ogni posizione: i vettori devono avere la
 *   stessa lunghezza.
 *
 * ESEMPIO:  sommaVettori(n, a, b, ris);
 */
void sommaVettori(int _n, int _a[_n], int _b[_n], int _ris[_n]) {
    for (int i = 0; i < _n; i++)
        _ris[i] = _a[i] + _b[i];
}

/**
 * Sottrae due vettori elemento per elemento: ris[i] = a[i] - b[i].
 * @param int Numero di elementi dei vettori.
 * @param int* Primo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato.
 *
 * COME FUNZIONA:
 *   ris[i] = a[i] - b[i] per ogni posizione.
 *
 * ESEMPIO:  differenzaVettori(n, a, b, ris);
 */
void differenzaVettori(int _n, int _a[_n], int _b[_n], int _ris[_n]) {
    for (int i = 0; i < _n; i++)
        _ris[i] = _a[i] - _b[i];
}

/**
 * Calcola il prodotto scalare: a[0]*b[0] + a[1]*b[1] + ...
 * @param int Numero di elementi dei vettori.
 * @param int* Primo vettore.
 * @param int* Secondo vettore.
 * @return Prodotto scalare.
 *
 * COME FUNZIONA:
 *   Si moltiplicano gli elementi nella stessa posizione e si sommano
 *   tutti i prodotti: a[0]*b[0] + a[1]*b[1] + ...
 *
 * ESEMPIO:  int risultato = calcolaProdottoScalare(n, a, b);
 */
int calcolaProdottoScalare(int _n, int _a[_n], int _b[_n]) {
    int ris = 0;
    for (int i = 0; i < _n; i++)
        ris += _a[i] * _b[i];
    return ris;
}

/**
 * Moltiplica ogni elemento del vettore per un numero.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero per cui moltiplicare.
 *
 * COME FUNZIONA:
 *   Ogni elemento viene moltiplicato per k (v[i] *= k): il vettore
 *   viene modificato.
 *
 * ESEMPIO:  moltiplicaVettoreScalare(n, v, k);
 */
void moltiplicaVettoreScalare(int _n, int _v[_n], int _k) {
    for (int i = 0; i < _n; i++)
        _v[i] *= _k;
}

/**
 * Verifica se due vettori sono uguali (stessa lunghezza e stessi elementi).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @return true se uguali, false altrimenti.
 *
 * COME FUNZIONA:
 *   Se le lunghezze sono diverse i vettori sono diversi; altrimenti
 *   basta UN elemento diverso per restituire false. Se il ciclo
 *   finisce, sono uguali.
 *
 * ESEMPIO:  bool risultato = verificaVettoriUguali(na, a, nb, b);
 */
bool verificaVettoriUguali(int _na, int _a[_na], int _nb, int _b[_nb]) {
    if (_na != _nb) return false;                        // lunghezze diverse -> diversi
    for (int i = 0; i < _na; i++)
        if (_a[i] != _b[i]) return false;
    return true;
}

/**
 * Fonde due vettori GIA' ORDINATI in un terzo vettore ordinato (merge).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore (ordinato).
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore (ordinato).
 * @param int* Vettore risultato (deve contenere almeno na + nb elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 *
 * COME FUNZIONA:
 *   Due indici i e j scorrono i due vettori: si copia in c il piu'
 *   piccolo tra a[i] e b[j] e si avanza solo in quel vettore. Quando
 *   uno finisce, si copiano gli elementi rimasti dell'altro.
 *
 * ESEMPIO:  fondiVettoriOrdinati(na, a, nb, b, c, &nc);
 */
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

/**
 * Concatena due vettori: il risultato contiene prima a e poi b.
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato (deve contenere almeno na + nb elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 *
 * COME FUNZIONA:
 *   Copia prima tutti gli elementi di a e poi tutti quelli di b nel
 *   vettore c, contando quanti ne scrive.
 *
 * ESEMPIO:  concatenaVettori(na, a, nb, b, c, &nc);
 */
void concatenaVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    *_nc = 0;
    for (int i = 0; i < _na; i++) _c[(*_nc)++] = _a[i];
    for (int i = 0; i < _nb; i++) _c[(*_nc)++] = _b[i];
}

/**
 * Calcola l'intersezione: elementi presenti sia in a sia in b, senza ripetizioni.
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato (deve contenere almeno na elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 *
 * COME FUNZIONA:
 *   Per ogni elemento di a: lo aggiunge a c solo se e' presente anche
 *   in b e non e' gia' stato aggiunto (cosi' non ci sono ripetizioni).
 *
 * ESEMPIO:  intersezioneVettori(na, a, nb, b, c, &nc);
 */
void intersezioneVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    *_nc = 0;
    for (int i = 0; i < _na; i++)
        // lo aggiungo se e' anche in b e se non l'ho gia' aggiunto
        if (cercaInVettore(_nb, _b, _a[i]) != -1 && cercaInVettore(*_nc, _c, _a[i]) == -1)
            _c[(*_nc)++] = _a[i];
}


/* ---------- 1.7 CONTROLLI ---------- */

/**
 * Verifica se il vettore e' ordinato in modo crescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se ordinato crescente, false altrimenti.
 *
 * COME FUNZIONA:
 *   Confronta ogni elemento con il successivo: se ne trova uno maggiore
 *   del successivo non e' crescente. Elementi uguali consecutivi sono
 *   ammessi.
 *
 * ESEMPIO:  bool risultato = verificaVettoreCrescente(n, v);
 */
bool verificaVettoreCrescente(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        if (_v[i] > _v[i + 1]) return false;
    return true;
}

/**
 * Verifica se il vettore e' ordinato in modo decrescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se ordinato decrescente, false altrimenti.
 *
 * COME FUNZIONA:
 *   Confronta ogni elemento con il successivo: se ne trova uno minore
 *   del successivo non e' decrescente. Elementi uguali consecutivi sono
 *   ammessi.
 *
 * ESEMPIO:  bool risultato = verificaVettoreDecrescente(n, v);
 */
bool verificaVettoreDecrescente(int _n, int _v[_n]) {
    for (int i = 0; i < _n - 1; i++)
        if (_v[i] < _v[i + 1]) return false;
    return true;
}

/**
 * Verifica se il vettore e' palindromo (si legge uguale in entrambi i versi).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se palindromo, false altrimenti.
 *
 * COME FUNZIONA:
 *   Confronta il primo con l'ultimo, il secondo col penultimo, ecc.
 *   fino a meta' vettore; basta una coppia diversa per dire false.
 *
 * ESEMPIO:  bool risultato = verificaVettorePalindromo(n, v);
 */
bool verificaVettorePalindromo(int _n, int _v[_n]) {
    for (int i = 0; i < _n / 2; i++)
        if (_v[i] != _v[_n - 1 - i]) return false;
    return true;
}

/**
 * Verifica se il vettore contiene elementi ripetuti.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se esiste almeno un duplicato, false altrimenti.
 *
 * COME FUNZIONA:
 *   Doppio ciclo: confronta ogni elemento i con tutti i successivi j;
 *   se ne trova due uguali restituisce true.
 *
 * ESEMPIO:  bool risultato = verificaVettoreHaDuplicati(n, v);
 */
bool verificaVettoreHaDuplicati(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            if (_v[i] == _v[j]) return true;
    return false;
}

/**
 * Verifica se tutti gli elementi del vettore sono uguali.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se tutti uguali, false altrimenti.
 *
 * COME FUNZIONA:
 *   Confronta ogni elemento con il primo: se ne trova uno diverso
 *   restituisce false.
 *
 * ESEMPIO:  bool risultato = verificaVettoreTuttiUguali(n, v);
 */
bool verificaVettoreTuttiUguali(int _n, int _v[_n]) {
    for (int i = 1; i < _n; i++)
        if (_v[i] != _v[0]) return false;
    return true;
}

/**
 * Verifica se un numero e' primo.
 * @param int Numero da controllare.
 * @return true se il numero e' primo, false altrimenti.
 *
 * COME FUNZIONA:
 *   Un numero e' primo se e' >= 2 e non ha divisori tra 2 e la sua
 *   radice quadrata. Si prova con d <= x / d (equivale a d*d <= x ma
 *   senza rischio di overflow).
 *
 * ESEMPIO:  bool risultato = verificaPrimo(x);
 */
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

/**
 * Carica la matrice chiedendo gli elementi da tastiera.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Due cicli annidati: quello esterno scorre le righe, quello interno
 *   le colonne; ogni elemento viene letto con scanf.
 *
 * ESEMPIO:  caricaMatrice(rows, cols, m);
 */
void caricaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &_m[i][j]);
        }
}

/**
 * Riempie la matrice con numeri casuali compresi tra min e max (inclusi).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore minimo.
 * @param int Valore massimo.
 *
 * COME FUNZIONA:
 *   Due cicli annidati; ogni elemento riceve rand() % (max - min + 1) +
 *   min (vedi riempiVettoreCasuale).
 *
 * ESEMPIO:  riempiMatriceCasuale(rows, cols, m, min, max);
 */
void riempiMatriceCasuale(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = rand() % (_max - _min + 1) + _min;
}

/**
 * Stampa la matrice riga per riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Due cicli annidati; dopo ogni riga completa (fine del ciclo
 *   interno) stampa un a capo. Un tab separa le colonne.
 *
 * ESEMPIO:  stampaMatrice(rows, cols, m);
 */
void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++)
            printf("%d\t", _m[i][j]);
        printf("\n");
    }
}

/**
 * Copia la matrice sorgente nella matrice destinazione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice sorgente.
 * @param int* Riferimento alla matrice destinazione.
 *
 * COME FUNZIONA:
 *   Due cicli annidati che copiano ogni elemento: dst[i][j] =
 *   src[i][j].
 *
 * ESEMPIO:  copiaMatrice(rows, cols, src, dst);
 */
void copiaMatrice(int _rows, int _cols, int _src[_rows][_cols], int _dst[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _dst[i][j] = _src[i][j];
}

/**
 * Riempie tutta la matrice con lo stesso valore (ad esempio 0).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore con cui riempire.
 *
 * COME FUNZIONA:
 *   Due cicli annidati che scrivono lo stesso valore in ogni posizione.
 *
 * ESEMPIO:  riempiMatriceCon(rows, cols, m, valore);
 */
void riempiMatriceCon(int _rows, int _cols, int _m[_rows][_cols], int _valore) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = _valore;
}

/**
 * Crea la matrice identita' (1 sulla diagonale principale, 0 altrove).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Se riga == colonna (diagonale principale) scrive 1, altrimenti 0.
 *
 * ESEMPIO:  creaMatriceIdentita(n, m);
 */
void creaMatriceIdentita(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            _m[i][j] = (i == j) ? 1 : 0;
}


/* ---------- 2.2 STATISTICHE ---------- */

/**
 * Calcola e restituisce la somma di tutti gli elementi della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi.
 *
 * COME FUNZIONA:
 *   Accumulatore con due cicli annidati che scorrono tutti gli
 *   elementi.
 *
 * ESEMPIO:  int risultato = calcolaSommaMatrice(rows, cols, m);
 */
int calcolaSommaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int somma = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            somma += _m[i][j];
    return somma;
}

/**
 * Calcola e restituisce il valor medio della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Valor medio della matrice.
 *
 * COME FUNZIONA:
 *   Somma di tutti gli elementi divisa per il numero di elementi (righe
 *   * colonne), con cast a float.
 *
 * ESEMPIO:  float risultato = calcolaMediaMatrice(rows, cols, m);
 */
float calcolaMediaMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    return (float) calcolaSommaMatrice(_rows, _cols, _m) / (_rows * _cols);
}

/**
 * Trova il massimo della matrice e la sua posizione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Puntatore dove salvare la riga del massimo.
 * @param int* Puntatore dove salvare la colonna del massimo.
 * @return Valore massimo.
 *
 * COME FUNZIONA:
 *   Come per il vettore, ma ogni volta che trova un nuovo massimo salva
 *   anche riga e colonna nelle variabili puntate da riga e col
 *   (parametri passati per puntatore).
 *
 * ESEMPIO:  int risultato = trovaMassimoMatrice(rows, cols, m, &riga, &col);
 */
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

/**
 * Trova il minimo della matrice e la sua posizione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Puntatore dove salvare la riga del minimo.
 * @param int* Puntatore dove salvare la colonna del minimo.
 * @return Valore minimo.
 *
 * COME FUNZIONA:
 *   Come per il vettore, ma ogni volta che trova un nuovo minimo salva
 *   anche riga e colonna nelle variabili puntate da riga e col
 *   (parametri passati per puntatore).
 *
 * ESEMPIO:  int risultato = trovaMinimoMatrice(rows, cols, m, &riga, &col);
 */
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

/**
 * Conta quante volte un valore compare nella matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore da contare.
 * @return Numero di occorrenze.
 *
 * COME FUNZIONA:
 *   Due cicli annidati con un contatore: incrementa quando l'elemento
 *   e' uguale a x.
 *
 * ESEMPIO:  int risultato = contaOccorrenzeMatrice(rows, cols, m, x);
 */
int contaOccorrenzeMatrice(int _rows, int _cols, int _m[_rows][_cols], int _x) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] == _x) cont++;
    return cont;
}

/**
 * Conta gli elementi pari della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Numero di elementi pari.
 *
 * COME FUNZIONA:
 *   Due cicli annidati con un contatore: incrementa quando m[i][j] % 2
 *   == 0.
 *
 * ESEMPIO:  int risultato = contaPariMatrice(rows, cols, m);
 */
int contaPariMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] % 2 == 0) cont++;
    return cont;
}

/**
 * Cerca un valore nella matrice e ne restituisce la posizione.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore da cercare.
 * @param int* Puntatore dove salvare la riga trovata.
 * @param int* Puntatore dove salvare la colonna trovata.
 * @return true se il valore e' presente, false altrimenti.
 *
 * COME FUNZIONA:
 *   Scorre la matrice; al primo elemento uguale a x salva riga e
 *   colonna e restituisce true. Se finisce senza trovarlo restituisce
 *   false.
 *
 * ESEMPIO:  bool risultato = cercaInMatrice(rows, cols, m, x, &riga, &col);
 */
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

/**
 * Calcola la somma degli elementi di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga.
 * @return Somma della riga.
 *
 * COME FUNZIONA:
 *   Fissata la riga, un solo ciclo sulle colonne j: si somma
 *   m[riga][j].
 *
 * ESEMPIO:  int risultato = calcolaSommaRiga(rows, cols, m, riga);
 */
int calcolaSommaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    (void) _rows;
    int somma = 0;
    for (int j = 0; j < _cols; j++)
        somma += _m[_riga][j];
    return somma;
}

/**
 * Calcola la somma degli elementi di una colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna.
 * @return Somma della colonna.
 *
 * COME FUNZIONA:
 *   Fissata la colonna, un solo ciclo sulle righe i: si somma
 *   m[i][col].
 *
 * ESEMPIO:  int risultato = calcolaSommaColonna(rows, cols, m, col);
 */
int calcolaSommaColonna(int _rows, int _cols, int _m[_rows][_cols], int _col) {
    int somma = 0;
    for (int i = 0; i < _rows; i++)
        somma += _m[i][_col];
    return somma;
}

/**
 * Salva in un vettore la somma di ogni riga (out[i] = somma della riga i).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (rows elementi).
 *
 * COME FUNZIONA:
 *   Per ogni riga chiama calcolaSommaRiga e salva il risultato in
 *   out[i].
 *
 * ESEMPIO:  calcolaSommeRighe(rows, cols, m, out);
 */
void calcolaSommeRighe(int _rows, int _cols, int _m[_rows][_cols], int _out[_rows]) {
    for (int i = 0; i < _rows; i++)
        _out[i] = calcolaSommaRiga(_rows, _cols, _m, i);
}

/**
 * Salva in un vettore la somma di ogni colonna (out[j] = somma della colonna j).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (cols elementi).
 *
 * COME FUNZIONA:
 *   Per ogni colonna chiama calcolaSommaColonna e salva il risultato in
 *   out[j].
 *
 * ESEMPIO:  calcolaSommeColonne(rows, cols, m, out);
 */
void calcolaSommeColonne(int _rows, int _cols, int _m[_rows][_cols], int _out[_cols]) {
    for (int j = 0; j < _cols; j++)
        _out[j] = calcolaSommaColonna(_rows, _cols, _m, j);
}

/**
 * Trova l'indice della riga con somma massima.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Indice della riga con somma massima.
 *
 * COME FUNZIONA:
 *   Tiene l'indice della riga con la somma maggiore trovata finora e lo
 *   aggiorna quando una riga successiva ha una somma piu' grande.
 *
 * ESEMPIO:  int risultato = trovaRigaSommaMax(rows, cols, m);
 */
int trovaRigaSommaMax(int _rows, int _cols, int _m[_rows][_cols]) {
    int pos = 0;
    for (int i = 1; i < _rows; i++)
        if (calcolaSommaRiga(_rows, _cols, _m, i) > calcolaSommaRiga(_rows, _cols, _m, pos)) pos = i;
    return pos;
}

/**
 * Trova l'indice della colonna con somma massima.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Indice della colonna con somma massima.
 *
 * COME FUNZIONA:
 *   Tiene l'indice della colonna con la somma maggiore trovata finora e
 *   lo aggiorna quando una colonna successiva ha una somma piu' grande.
 *
 * ESEMPIO:  int risultato = trovaColonnaSommaMax(rows, cols, m);
 */
int trovaColonnaSommaMax(int _rows, int _cols, int _m[_rows][_cols]) {
    int pos = 0;
    for (int j = 1; j < _cols; j++)
        if (calcolaSommaColonna(_rows, _cols, _m, j) > calcolaSommaColonna(_rows, _cols, _m, pos)) pos = j;
    return pos;
}

/**
 * Trova il valore massimo di una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga.
 * @return Massimo della riga.
 *
 * COME FUNZIONA:
 *   Massimo di un vettore, ma limitato ai soli elementi della riga
 *   indicata.
 *
 * ESEMPIO:  int risultato = trovaMassimoRiga(rows, cols, m, riga);
 */
int trovaMassimoRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    (void) _rows;
    int max = _m[_riga][0];
    for (int j = 1; j < _cols; j++)
        if (_m[_riga][j] > max) max = _m[_riga][j];
    return max;
}

/**
 * Trova il valore massimo di una colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna.
 * @return Massimo della colonna.
 *
 * COME FUNZIONA:
 *   Massimo limitato ai soli elementi della colonna indicata.
 *
 * ESEMPIO:  int risultato = trovaMassimoColonna(rows, cols, m, col);
 */
int trovaMassimoColonna(int _rows, int _cols, int _m[_rows][_cols], int _col) {
    int max = _m[0][_col];
    for (int i = 1; i < _rows; i++)
        if (_m[i][_col] > max) max = _m[i][_col];
    return max;
}

/**
 * Calcola la somma della diagonale principale (alto-sinistra -> basso-destra).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma della diagonale principale.
 *
 * COME FUNZIONA:
 *   Sulla diagonale principale riga e colonna sono uguali: basta un
 *   solo ciclo e si somma m[i][i].
 *
 * ESEMPIO:  int risultato = calcolaSommaDiagonalePrincipale(n, m);
 */
int calcolaSommaDiagonalePrincipale(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _m[i][i];                               // riga == colonna
    return somma;
}

/**
 * Calcola la somma della diagonale secondaria (alto-destra -> basso-sinistra).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma della diagonale secondaria.
 *
 * COME FUNZIONA:
 *   Sulla diagonale secondaria riga + colonna = n - 1, quindi la
 *   colonna e' n - 1 - i: si somma m[i][n-1-i].
 *
 * ESEMPIO:  int risultato = calcolaSommaDiagonaleSecondaria(n, m);
 */
int calcolaSommaDiagonaleSecondaria(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        somma += _m[i][_n - 1 - i];                      // riga + colonna == n - 1
    return somma;
}

/**
 * Calcola la somma degli elementi sopra la diagonale principale (j > i).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi sopra la diagonale.
 *
 * COME FUNZIONA:
 *   Sopra la diagonale principale la colonna e' maggiore della riga:
 *   per ogni riga i il ciclo delle colonne parte da i + 1.
 *
 * ESEMPIO:  int risultato = calcolaSommaSopraDiagonale(n, m);
 */
int calcolaSommaSopraDiagonale(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            somma += _m[i][j];
    return somma;
}

/**
 * Calcola la somma degli elementi sotto la diagonale principale (j < i).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi sotto la diagonale.
 *
 * COME FUNZIONA:
 *   Sotto la diagonale principale la colonna e' minore della riga: per
 *   ogni riga i il ciclo delle colonne va da 0 a i - 1.
 *
 * ESEMPIO:  int risultato = calcolaSommaSottoDiagonale(n, m);
 */
int calcolaSommaSottoDiagonale(int _n, int _m[_n][_n]) {
    int somma = 0;
    for (int i = 1; i < _n; i++)
        for (int j = 0; j < i; j++)
            somma += _m[i][j];
    return somma;
}

/**
 * Calcola la somma degli elementi del perimetro (prima/ultima riga e colonna).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Somma degli elementi del perimetro.
 *
 * COME FUNZIONA:
 *   Scorre tutta la matrice e somma solo gli elementi sulla prima o
 *   ultima riga oppure sulla prima o ultima colonna.
 *
 * ESEMPIO:  int risultato = calcolaSommaPerimetro(rows, cols, m);
 */
int calcolaSommaPerimetro(int _rows, int _cols, int _m[_rows][_cols]) {
    int somma = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (i == 0 || i == _rows - 1 || j == 0 || j == _cols - 1)
                somma += _m[i][j];
    return somma;
}

/**
 * Stampa su una riga gli elementi della diagonale principale.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Un solo ciclo che stampa m[i][i].
 *
 * ESEMPIO:  stampaDiagonalePrincipale(n, m);
 */
void stampaDiagonalePrincipale(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _m[i][i]);
    printf("\n");
}


/* ---------- 2.4 OPERAZIONI TRA MATRICI ---------- */

/**
 * Somma due matrici: ris = a + b.
 * @param int Numero di righe delle matrici.
 * @param int Numero di colonne delle matrici.
 * @param int* Prima matrice.
 * @param int* Seconda matrice.
 * @param int* Matrice risultato.
 *
 * COME FUNZIONA:
 *   ris[i][j] = a[i][j] + b[i][j] per ogni posizione: le matrici devono
 *   avere la stessa dimensione.
 *
 * ESEMPIO:  sommaMatrici(rows, cols, a, b, ris);
 */
void sommaMatrici(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols], int _ris[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[i][j] = _a[i][j] + _b[i][j];
}

/**
 * Sottrae due matrici: ris = a - b.
 * @param int Numero di righe delle matrici.
 * @param int Numero di colonne delle matrici.
 * @param int* Prima matrice.
 * @param int* Seconda matrice.
 * @param int* Matrice risultato.
 *
 * COME FUNZIONA:
 *   ris[i][j] = a[i][j] - b[i][j] per ogni posizione.
 *
 * ESEMPIO:  differenzaMatrici(rows, cols, a, b, ris);
 */
void differenzaMatrici(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols], int _ris[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[i][j] = _a[i][j] - _b[i][j];
}

/**
 * Moltiplica ogni elemento della matrice per un numero.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Numero per cui moltiplicare.
 *
 * COME FUNZIONA:
 *   Ogni elemento viene moltiplicato per k (la matrice viene
 *   modificata).
 *
 * ESEMPIO:  moltiplicaMatriceScalare(rows, cols, m, k);
 */
void moltiplicaMatriceScalare(int _rows, int _cols, int _m[_rows][_cols], int _k) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] *= _k;
}

/**
 * Prodotto righe per colonne: A (r1 x c1) * B (c1 x c2) = ris (r1 x c2).
 * Il numero di colonne di A deve coincidere con il numero di righe di B.
 * @param int Numero di righe di A.
 * @param int Numero di colonne di A (= righe di B).
 * @param int Numero di colonne di B.
 * @param int* Matrice A.
 * @param int* Matrice B.
 * @param int* Matrice risultato (r1 x c2).
 *
 * COME FUNZIONA:
 *   ris[i][j] e' il prodotto scalare tra la riga i di A e la colonna j
 *   di B: tre cicli annidati (i, j, k) con ris[i][j] += a[i][k] *
 *   b[k][j]. Servono colonne di A = righe di B; il risultato e' r1 x
 *   c2.
 *
 * ESEMPIO:  prodottoMatrici(r1, c1, c2, a, b, ris);
 */
void prodottoMatrici(int _r1, int _c1, int _c2, int _a[_r1][_c1], int _b[_c1][_c2], int _ris[_r1][_c2]) {
    for (int i = 0; i < _r1; i++)
        for (int j = 0; j < _c2; j++) {
            _ris[i][j] = 0;
            for (int k = 0; k < _c1; k++)                // riga i di A per colonna j di B
                _ris[i][j] += _a[i][k] * _b[k][j];
        }
}

/**
 * Prodotto matrice per vettore: ris[i] = somma(m[i][j] * v[j]).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore (cols elementi).
 * @param int* Vettore risultato (rows elementi).
 *
 * COME FUNZIONA:
 *   ris[i] e' il prodotto scalare tra la riga i della matrice e il
 *   vettore.
 *
 * ESEMPIO:  prodottoMatriceVettore(rows, cols, m, v, ris);
 */
void prodottoMatriceVettore(int _rows, int _cols, int _m[_rows][_cols], int _v[_cols], int _ris[_rows]) {
    for (int i = 0; i < _rows; i++) {
        _ris[i] = 0;
        for (int j = 0; j < _cols; j++)
            _ris[i] += _m[i][j] * _v[j];
    }
}

/**
 * Elevamento a potenza di una matrice quadrata: ris = m^k (k >= 0).
 * La matrice m e la matrice ris devono essere DIVERSE.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param int Esponente.
 * @param int* Matrice risultato.
 *
 * COME FUNZIONA:
 *   Parte dalla matrice identita' (m alla 0) e la moltiplica k volte
 *   per m, usando una matrice d'appoggio temp (non si puo' moltiplicare
 *   una matrice 'su se stessa' mentre la si sta leggendo).
 *
 * ESEMPIO:  potenzaMatrice(n, m, k, ris);
 */
void potenzaMatrice(int _n, int _m[_n][_n], int _k, int _ris[_n][_n]) {
    int temp[_n][_n];
    creaMatriceIdentita(_n, _ris);                       // m^0 = identita'
    for (int p = 0; p < _k; p++) {
        prodottoMatrici(_n, _n, _n, _ris, _m, temp);
        copiaMatrice(_n, _n, temp, _ris);
    }
}

/**
 * Verifica se due matrici sono uguali.
 * @param int Numero di righe delle matrici.
 * @param int Numero di colonne delle matrici.
 * @param int* Prima matrice.
 * @param int* Seconda matrice.
 * @return true se uguali, false altrimenti.
 *
 * COME FUNZIONA:
 *   Basta UN elemento diverso per restituire false; se il ciclo finisce
 *   le matrici sono uguali.
 *
 * ESEMPIO:  bool risultato = verificaMatriciUguali(rows, cols, a, b);
 */
bool verificaMatriciUguali(int _rows, int _cols, int _a[_rows][_cols], int _b[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_a[i][j] != _b[i][j]) return false;
    return true;
}


/* ---------- 2.5 TRASFORMAZIONI ---------- */

/**
 * Calcola la trasposta: ris[j][i] = m[i][j] (righe e colonne si scambiano).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (cols x rows).
 *
 * COME FUNZIONA:
 *   L'elemento in riga i e colonna j va in riga j e colonna i:
 *   ris[j][i] = m[i][j]. La matrice risultato ha le dimensioni
 *   scambiate (cols x rows).
 *
 * ESEMPIO:  calcolaTrasposta(rows, cols, m, ris);
 */
void calcolaTrasposta(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[j][i] = _m[i][j];
}

/**
 * Trasposta "sul posto" di una matrice quadrata (modifica la matrice stessa).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Scambia m[i][j] con m[j][i] ma solo sopra la diagonale (j > i):
 *   scorrendo tutta la matrice ogni coppia verrebbe scambiata due volte
 *   e tornerebbe com'era.
 *
 * ESEMPIO:  traspostaSulPosto(n, m);
 */
void traspostaSulPosto(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)                 // solo sopra la diagonale, altrimenti riscambio
            scambia(&_m[i][j], &_m[j][i]);
}

/**
 * Scambia due righe della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della prima riga.
 * @param int Indice della seconda riga.
 *
 * COME FUNZIONA:
 *   Scambia, colonna per colonna, gli elementi delle due righe usando
 *   scambia().
 *
 * ESEMPIO:  scambiaRigheMatrice(rows, cols, m, r1, r2);
 */
void scambiaRigheMatrice(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _r2) {
    (void) _rows;
    for (int j = 0; j < _cols; j++)
        scambia(&_m[_r1][j], &_m[_r2][j]);
}

/**
 * Scambia due colonne della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della prima colonna.
 * @param int Indice della seconda colonna.
 *
 * COME FUNZIONA:
 *   Scambia, riga per riga, gli elementi delle due colonne usando
 *   scambia().
 *
 * ESEMPIO:  scambiaColonneMatrice(rows, cols, m, c1, c2);
 */
void scambiaColonneMatrice(int _rows, int _cols, int _m[_rows][_cols], int _c1, int _c2) {
    for (int i = 0; i < _rows; i++)
        scambia(&_m[i][_c1], &_m[i][_c2]);
}

/**
 * Ruota la matrice di 90 gradi in senso orario.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (cols x rows).
 *
 * COME FUNZIONA:
 *   L'elemento (i, j) finisce in (j, rows-1-i): la prima riga diventa
 *   l'ultima colonna. Il risultato ha dimensioni cols x rows.
 *
 * ESEMPIO:  ruotaMatrice90Orario(rows, cols, m, ris);
 */
void ruotaMatrice90Orario(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[j][_rows - 1 - i] = _m[i][j];
}

/**
 * Specchia la matrice in orizzontale (inverte l'ordine delle colonne).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   In ogni riga scambia la prima colonna con l'ultima, la seconda con
 *   la penultima, ecc. (si ferma a cols/2).
 *
 * ESEMPIO:  specchiaMatriceOrizzontale(rows, cols, m);
 */
void specchiaMatriceOrizzontale(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols / 2; j++)
            scambia(&_m[i][j], &_m[i][_cols - 1 - j]);
}

/**
 * Specchia la matrice in verticale (inverte l'ordine delle righe).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Scambia la prima riga con l'ultima, la seconda con la penultima,
 *   ecc. (si ferma a rows/2).
 *
 * ESEMPIO:  specchiaMatriceVerticale(rows, cols, m);
 */
void specchiaMatriceVerticale(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows / 2; i++)
        scambiaRigheMatrice(_rows, _cols, _m, i, _rows - 1 - i);
}

/**
 * Ordina in modo crescente gli elementi di una singola riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga da ordinare.
 *
 * COME FUNZIONA:
 *   Bubble sort applicato ai soli elementi di una riga.
 *
 * ESEMPIO:  ordinaRigaMatrice(rows, cols, m, riga);
 */
void ordinaRigaMatrice(int _rows, int _cols, int _m[_rows][_cols], int _riga) {
    (void) _rows;
    for (int i = 0; i < _cols - 1; i++)
        for (int j = 0; j < _cols - 1 - i; j++)
            if (_m[_riga][j] > _m[_riga][j + 1])
                scambia(&_m[_riga][j], &_m[_riga][j + 1]);
}

/**
 * Copia la matrice in un'altra togliendo una riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga da togliere.
 * @param int* Matrice risultato ((rows - 1) x cols).
 *
 * COME FUNZIONA:
 *   Copia tutte le righe tranne quella indicata (continue la salta)
 *   usando un indice separato ri per la riga di destinazione.
 *
 * ESEMPIO:  copiaMatriceSenzaRiga(rows, cols, m, riga, out);
 */
void copiaMatriceSenzaRiga(int _rows, int _cols, int _m[_rows][_cols], int _riga, int _out[_rows - 1][_cols]) {
    int ri = 0;                                          // indice di riga nel risultato
    for (int i = 0; i < _rows; i++) {
        if (i == _riga) continue;
        for (int j = 0; j < _cols; j++)
            _out[ri][j] = _m[i][j];
        ri++;
    }
}

/**
 * Copia la matrice in un'altra togliendo una colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna da togliere.
 * @param int* Matrice risultato (rows x (cols - 1)).
 *
 * COME FUNZIONA:
 *   Per ogni riga copia tutte le colonne tranne quella indicata, con un
 *   indice separato cj per la colonna di destinazione.
 *
 * ESEMPIO:  copiaMatriceSenzaColonna(rows, cols, m, col, out);
 */
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

/**
 * Verifica se la matrice quadrata e' simmetrica (m[i][j] == m[j][i]).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se simmetrica, false altrimenti.
 *
 * COME FUNZIONA:
 *   Una matrice e' simmetrica se m[i][j] == m[j][i]. Basta controllare
 *   meta' matrice (j > i).
 *
 * ESEMPIO:  bool risultato = verificaMatriceSimmetrica(n, m);
 */
bool verificaMatriceSimmetrica(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            if (_m[i][j] != _m[j][i]) return false;
    return true;
}

/**
 * Verifica se la matrice quadrata e' diagonale (0 fuori dalla diagonale principale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se diagonale, false altrimenti.
 *
 * COME FUNZIONA:
 *   Tutti gli elementi con riga diversa da colonna devono essere 0.
 *
 * ESEMPIO:  bool risultato = verificaMatriceDiagonale(n, m);
 */
bool verificaMatriceDiagonale(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            if (i != j && _m[i][j] != 0) return false;
    return true;
}

/**
 * Verifica se la matrice quadrata e' la matrice identita'.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se identita', false altrimenti.
 *
 * COME FUNZIONA:
 *   Sulla diagonale devono esserci solo 1, fuori dalla diagonale solo
 *   0.
 *
 * ESEMPIO:  bool risultato = verificaMatriceIdentita(n, m);
 */
bool verificaMatriceIdentita(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++) {
            if (i == j && _m[i][j] != 1) return false;
            if (i != j && _m[i][j] != 0) return false;
        }
    return true;
}

/**
 * Verifica se la matrice quadrata e' triangolare superiore (0 sotto la diagonale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se triangolare superiore, false altrimenti.
 *
 * COME FUNZIONA:
 *   Triangolare superiore: tutti gli elementi sotto la diagonale (j <
 *   i) devono essere 0.
 *
 * ESEMPIO:  bool risultato = verificaMatriceTriangolareSup(n, m);
 */
bool verificaMatriceTriangolareSup(int _n, int _m[_n][_n]) {
    for (int i = 1; i < _n; i++)
        for (int j = 0; j < i; j++)
            if (_m[i][j] != 0) return false;
    return true;
}

/**
 * Verifica se la matrice quadrata e' triangolare inferiore (0 sopra la diagonale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se triangolare inferiore, false altrimenti.
 *
 * COME FUNZIONA:
 *   Triangolare inferiore: tutti gli elementi sopra la diagonale (j >
 *   i) devono essere 0.
 *
 * ESEMPIO:  bool risultato = verificaMatriceTriangolareInf(n, m);
 */
bool verificaMatriceTriangolareInf(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)
            if (_m[i][j] != 0) return false;
    return true;
}

/**
 * Verifica se la matrice e' nulla (tutti gli elementi uguali a 0).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return true se nulla, false altrimenti.
 *
 * COME FUNZIONA:
 *   Basta UN elemento diverso da 0 per restituire false.
 *
 * ESEMPIO:  bool risultato = verificaMatriceNulla(rows, cols, m);
 */
bool verificaMatriceNulla(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] != 0) return false;
    return true;
}

/**
 * Verifica se la matrice quadrata e' un quadrato magico
 * (righe, colonne e le due diagonali hanno tutte la stessa somma).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se quadrato magico, false altrimenti.
 *
 * COME FUNZIONA:
 *   Calcola la somma della diagonale principale come riferimento e
 *   verifica che la diagonale secondaria e tutte le righe e colonne
 *   abbiano la stessa somma.
 *
 * ESEMPIO:  bool risultato = verificaQuadratoMagico(n, m);
 */
bool verificaQuadratoMagico(int _n, int _m[_n][_n]) {
    int s = calcolaSommaDiagonalePrincipale(_n, _m);     // somma di riferimento
    if (calcolaSommaDiagonaleSecondaria(_n, _m) != s) return false;
    for (int i = 0; i < _n; i++) {
        if (calcolaSommaRiga(_n, _n, _m, i) != s) return false;
        if (calcolaSommaColonna(_n, _n, _m, i) != s) return false;
    }
    return true;
}

/**
 * Verifica se tutti gli elementi della matrice sono diversi tra loro.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return true se tutti diversi, false se esiste almeno un duplicato.
 *
 * COME FUNZIONA:
 *   Confronta ogni elemento con tutti gli altri (quattro cicli
 *   annidati) saltando il confronto con se stesso: se due posizioni
 *   diverse hanno lo stesso valore restituisce false.
 *
 * ESEMPIO:  bool risultato = verificaMatriceElementiDiversi(rows, cols, m);
 */
bool verificaMatriceElementiDiversi(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            for (int k = 0; k < _rows; k++)
                for (int l = 0; l < _cols; l++)
                    if ((i != k || j != l) && _m[i][j] == _m[k][l]) return false;
    return true;
}


/* ---------- 2.7 DETERMINANTE ---------- */

/**
 * Calcola il determinante di una matrice quadrata (sviluppo di Laplace
 * sulla prima riga, ricorsivo).
 * @param int Dimensione della matrice quadrata (>= 1).
 * @param int* Riferimento alla matrice.
 * @return Determinante della matrice.
 *
 * COME FUNZIONA:
 *   Ricorsiva (sviluppo di Laplace sulla prima riga): det = somma di
 *   segno * m[0][col] * det(minore), con segni alternati + - + -. Il
 *   minore e' la matrice senza la riga 0 e senza la colonna col. Casi
 *   base: 1x1 e' l'elemento stesso, 2x2 e' ad - bc.
 *
 * ESEMPIO:  long long risultato = calcolaDeterminante(n, m);
 */
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

/**
 * Copia la matrice in un vettore, riga dopo riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (rows * cols elementi).
 *
 * COME FUNZIONA:
 *   Un contatore k avanza ad ogni elemento: copia la matrice nel
 *   vettore riga dopo riga.
 *
 * ESEMPIO:  matriceInVettore(rows, cols, m, v);
 */
void matriceInVettore(int _rows, int _cols, int _m[_rows][_cols], int _v[_rows * _cols]) {
    int k = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _v[k++] = _m[i][j];
}

/**
 * Riempie la matrice con gli elementi del vettore, riga dopo riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Vettore sorgente (rows * cols elementi).
 * @param int* Matrice risultato.
 *
 * COME FUNZIONA:
 *   Operazione inversa: legge il vettore in ordine e riempie la matrice
 *   riga dopo riga.
 *
 * ESEMPIO:  vettoreInMatrice(rows, cols, v, m);
 */
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

/**
 * Calcola il Massimo Comun Divisore con l'algoritmo di Euclide.
 * @param int Primo numero.
 * @param int Secondo numero.
 * @return MCD dei due numeri.
 *
 * COME FUNZIONA:
 *   Algoritmo di Euclide: MCD(a, b) = MCD(b, a % b); si ripete finche'
 *   b diventa 0, allora a e' il MCD.
 *
 * ESEMPIO:  int risultato = calcolaMCD(a, b);
 */
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

/**
 * Calcola il minimo comune multiplo.
 * @param int Primo numero.
 * @param int Secondo numero.
 * @return mcm dei due numeri.
 *
 * COME FUNZIONA:
 *   mcm = a / MCD * b (si divide prima per non far crescere troppo il
 *   numero).
 *
 * ESEMPIO:  int risultato = calcolaMCM(a, b);
 */
int calcolaMCM(int _a, int _b) {
    if (_a == 0 || _b == 0) return 0;
    int mcd = calcolaMCD(_a, _b);
    int mcm = _a / mcd * _b;                             // divido prima per evitare overflow
    return mcm < 0 ? -mcm : mcm;
}

/**
 * Calcola il MCD di tutti gli elementi di un vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return MCD di tutti gli elementi.
 *
 * COME FUNZIONA:
 *   Parte dal primo elemento e calcola il MCD con ognuno dei
 *   successivi.
 *
 * ESEMPIO:  int risultato = calcolaMCDVettore(n, v);
 */
int calcolaMCDVettore(int _n, int _v[_n]) {
    int mcd = _v[0];
    for (int i = 1; i < _n; i++)
        mcd = calcolaMCD(mcd, _v[i]);
    return mcd;
}

/**
 * Calcola il fattoriale di un numero (n!).
 * @param int Numero (>= 0, al massimo 20 per non andare in overflow).
 * @return Fattoriale del numero.
 *
 * COME FUNZIONA:
 *   Moltiplica tutti i numeri da 2 a x. Il risultato e' long long
 *   perche' cresce velocemente (20! e' l'ultimo che entra).
 *
 * ESEMPIO:  long long risultato = calcolaFattoriale(x);
 */
long long calcolaFattoriale(int _x) {
    long long ris = 1;
    for (int i = 2; i <= _x; i++)
        ris *= i;
    return ris;
}

/**
 * Conta le cifre di un numero (il segno viene ignorato; lo 0 ha 1 cifra).
 * @param int Numero.
 * @return Numero di cifre.
 *
 * COME FUNZIONA:
 *   Divide ripetutamente per 10 finche' il numero e' >= 10, contando i
 *   passaggi (lo 0 ha una cifra).
 *
 * ESEMPIO:  int risultato = contaCifre(x);
 */
int contaCifre(int _x) {
    if (_x < 0) _x = -_x;
    int cifre = 1;                                       // lo 0 ha 1 cifra
    while (_x >= 10) {
        _x /= 10;
        cifre++;
    }
    return cifre;
}

/**
 * Calcola la somma delle cifre di un numero (il segno viene ignorato).
 * @param int Numero.
 * @return Somma delle cifre.
 *
 * COME FUNZIONA:
 *   x % 10 e' l'ultima cifra, x / 10 toglie l'ultima cifra: si ripete
 *   finche' x > 0 sommando le cifre.
 *
 * ESEMPIO:  int risultato = calcolaSommaCifre(x);
 */
int calcolaSommaCifre(int _x) {
    if (_x < 0) _x = -_x;
    int somma = 0;
    while (_x > 0) {
        somma += _x % 10;                                // ultima cifra
        _x /= 10;                                        // tolgo l'ultima cifra
    }
    return somma;
}

/**
 * Inverte le cifre di un numero (es. 123 -> 321, -45 -> -54).
 * @param int Numero.
 * @return Numero con le cifre invertite.
 *
 * COME FUNZIONA:
 *   Prende l'ultima cifra di x e la aggiunge in coda al risultato (ris
 *   * 10 + cifra), poi la toglie da x.
 *
 * ESEMPIO:  int risultato = invertiNumero(x);
 */
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

/**
 * Verifica se un numero e' palindromo (es. 12321).
 * @param int Numero.
 * @return true se palindromo, false altrimenti.
 *
 * COME FUNZIONA:
 *   Un numero e' palindromo se e' uguale al suo inverso
 *   (invertiNumero).
 *
 * ESEMPIO:  bool risultato = verificaNumeroPalindromo(x);
 */
bool verificaNumeroPalindromo(int _x) {
    return _x >= 0 && invertiNumero(_x) == _x;
}

/**
 * Scompone un numero nel vettore delle sue cifre (la prima e' la piu' significativa).
 * @param int Numero (il segno viene ignorato).
 * @param int* Vettore risultato (almeno 10 elementi).
 * @param int* Puntatore dove salvare il numero di cifre.
 *
 * COME FUNZIONA:
 *   Calcola quante cifre ha, poi riempie il vettore DA DESTRA: x % 10
 *   e' la cifra meno significativa e va nell'ultima posizione.
 *
 * ESEMPIO:  numeroInVettoreCifre(x, v, &n);
 */
void numeroInVettoreCifre(int _x, int _v[], int *_n) {
    if (_x < 0) _x = -_x;
    *_n = contaCifre(_x);
    for (int i = *_n - 1; i >= 0; i--) {                 // riempio da destra verso sinistra
        _v[i] = _x % 10;
        _x /= 10;
    }
}

/**
 * Ricostruisce un numero a partire dal vettore delle cifre (operazione inversa).
 * @param int Numero di cifre.
 * @param int* Riferimento al vettore delle cifre.
 * @return Numero ricostruito.
 *
 * COME FUNZIONA:
 *   Per ogni cifra: ris = ris * 10 + cifra (metodo di Horner).
 *
 * ESEMPIO:  long long risultato = vettoreCifreInNumero(n, v);
 */
long long vettoreCifreInNumero(int _n, int _v[_n]) {
    long long ris = 0;
    for (int i = 0; i < _n; i++)
        ris = ris * 10 + _v[i];
    return ris;
}

/**
 * Converte un numero in una base (2..16) salvando le cifre in un vettore.
 * La prima cifra del vettore e' la piu' significativa (es. 10 in base 2 -> 1 0 1 0).
 * @param int Numero da convertire (>= 0).
 * @param int Base di arrivo.
 * @param int* Vettore risultato (almeno 32 elementi).
 * @param int* Puntatore dove salvare il numero di cifre.
 *
 * COME FUNZIONA:
 *   Si divide ripetutamente per la base: i resti sono le cifre, ma
 *   escono dalla meno significativa. Si salvano in un vettore
 *   temporaneo e poi si copiano in ordine inverso.
 *
 * ESEMPIO:  convertiNumeroInBase(x, base, v, &n);
 */
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

/**
 * Riempie il vettore con i primi n numeri di Fibonacci (0 1 1 2 3 5 ...).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   I primi due valori sono 0 e 1; ogni altro e' la somma dei due
 *   precedenti.
 *
 * ESEMPIO:  generaFibonacciVettore(n, v);
 */
void generaFibonacciVettore(int _n, int _v[_n]) {
    for (int i = 0; i < _n; i++)
        _v[i] = (i < 2) ? i : _v[i - 1] + _v[i - 2];     // 0, 1, poi somma dei due precedenti
}

/**
 * Riempie il vettore con i primi n numeri primi (2 3 5 7 11 ...).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Prova i numeri 2, 3, 4, ... e salva nel vettore quelli per cui
 *   verificaPrimo e' vera, finche' ne ha trovati n.
 *
 * ESEMPIO:  generaPrimiVettore(n, v);
 */
void generaPrimiVettore(int _n, int _v[_n]) {
    int trovati = 0, candidato = 2;
    while (trovati < _n) {
        if (verificaPrimo(candidato))
            _v[trovati++] = candidato;
        candidato++;
    }
}


/**
 * Converte un numero scritto come vettore di cifre in una base qualsiasi nel suo valore decimale
 * (la prima cifra del vettore e' la piu' significativa; ogni cifra deve essere < base).
 * @param int Numero di cifre.
 * @param int* Riferimento al vettore delle cifre.
 * @param int Base in cui sono scritte le cifre (es. 2 per il binario).
 * @return Valore decimale del numero.
 *
 * COME FUNZIONA:
 *   Metodo di Horner: parte da 0 e per ogni cifra fa ris = ris * base +
 *   cifra (come vettoreCifreInNumero ma con una base qualsiasi). Le
 *   cifre devono essere minori della base.
 *
 * ESEMPIO:  long long risultato = convertiDaBaseInDecimale(n, v, base);
 */
long long convertiDaBaseInDecimale(int _n, int _v[_n], int _base) {
    long long ris = 0;
    for (int i = 0; i < _n; i++)
        ris = ris * _base + _v[i];                       // come vettoreCifreInNumero ma con la base
    return ris;
}


/**
 * Calcola una potenza intera: base elevato a esp (esp >= 0).
 * @param int Base.
 * @param int Esponente.
 * @return Risultato della potenza (con esponente 0 vale 1).
 *
 * COME FUNZIONA:
 *   Parte da 1 e moltiplica per la base esp volte. Con esp = 0
 *   restituisce 1. Il risultato e' long long perche' cresce in fretta.
 *
 * ESEMPIO:  long long risultato = calcolaPotenza(base, esp);
 */
long long calcolaPotenza(int _base, int _esp) {
    long long ris = 1;
    for (int i = 0; i < _esp; i++)
        ris *= _base;
    return ris;
}


/**
 * Calcola la parte intera della radice quadrata (il piu' grande r con r*r <= x),
 * senza usare math.h. Per x negativo restituisce 0.
 * @param int Numero.
 * @return Radice quadrata intera.
 *
 * COME FUNZIONA:
 *   Trova il piu' grande r con r*r <= x: aumenta r finche' (r+1)*(r+1)
 *   <= x. Il confronto e' scritto (r+1) <= x / (r+1) per evitare
 *   l'overflow. Non serve math.h.
 *
 * ESEMPIO:  int risultato = calcolaRadiceIntera(x);
 */
int calcolaRadiceIntera(int _x) {
    int r = 0;
    while (r + 1 <= _x / (r + 1))                        // (r+1)^2 <= x scritto cosi' non va in overflow
        r++;
    return r;
}


/**
 * Conta i divisori positivi di un numero (compresi 1 e il numero stesso).
 * @param int Numero (>= 1).
 * @return Numero di divisori.
 *
 * COME FUNZIONA:
 *   Prova i d da 1 fino alla radice di x: ogni divisore d ha un
 *   'gemello' x / d, quindi se d divide x si contano entrambi (una
 *   volta sola se d == x / d, cioe' la radice esatta).
 *
 * ESEMPIO:  int risultato = contaDivisori(x);
 */
int contaDivisori(int _x) {
    int cont = 0;
    for (int d = 1; d <= _x / d; d++)                    // basta arrivare alla radice: ogni d ha il suo "gemello" x/d
        if (_x % d == 0) {
            cont++;
            if (d != _x / d) cont++;                     // non conto due volte la radice esatta
        }
    return cont;
}


/**
 * Verifica se un numero e' perfetto: uguale alla somma dei suoi divisori propri (es. 6 = 1+2+3).
 * @param int Numero.
 * @return true se perfetto, false altrimenti.
 *
 * COME FUNZIONA:
 *   Un numero e' perfetto se e' uguale alla somma dei suoi divisori
 *   propri (escluso se stesso): 6 = 1 + 2 + 3. Parte da somma = 1 e
 *   aggiunge ogni coppia di divisori d e x / d fino alla radice.
 *
 * ESEMPIO:  bool risultato = verificaNumeroPerfetto(x);
 */
bool verificaNumeroPerfetto(int _x) {
    if (_x < 2) return false;
    int somma = 1;                                       // 1 divide sempre (e' un divisore proprio)
    for (int d = 2; d <= _x / d; d++)
        if (_x % d == 0) {
            somma += d;
            if (d != _x / d) somma += _x / d;
        }
    return somma == _x;
}


/**
 * Verifica se un numero e' di Armstrong: uguale alla somma delle sue cifre
 * elevate al numero di cifre (es. 153 = 1^3 + 5^3 + 3^3).
 * @param int Numero.
 * @return true se di Armstrong, false altrimenti.
 *
 * COME FUNZIONA:
 *   Un numero e' di Armstrong se e' uguale alla somma delle sue cifre
 *   elevate al numero di cifre (153 = 1^3 + 5^3 + 3^3). Estrae le cifre
 *   con % 10 e / 10 e usa calcolaPotenza.
 *
 * ESEMPIO:  bool risultato = verificaNumeroArmstrong(x);
 */
bool verificaNumeroArmstrong(int _x) {
    if (_x < 0) return false;
    int n = contaCifre(_x);
    long long somma = 0;
    int resto = _x;
    while (resto > 0) {
        somma += calcolaPotenza(resto % 10, n);
        resto /= 10;
    }
    return somma == _x;
}


/**
 * Scompone un numero in fattori primi, in ordine crescente (es. 12 -> 2 2 3).
 * Per 0 e 1 non salva nessun fattore.
 * @param int Numero da scomporre.
 * @param int* Vettore risultato (almeno 32 elementi).
 * @param int* Puntatore dove salvare il numero di fattori.
 *
 * COME FUNZIONA:
 *   Prova i divisori d = 2, 3, ...: finche' d divide x lo salva nel
 *   vettore e divide x per d. Alla fine, se resta un x > 1, e' un
 *   numero primo e va aggiunto. Un int ha al massimo 31 fattori primi.
 *
 * ESEMPIO:  scomponiInFattoriPrimi(x, v, &n);
 */
void scomponiInFattoriPrimi(int _x, int _v[], int *_n) {
    *_n = 0;
    for (int d = 2; d <= _x / d; d++)
        while (_x % d == 0) {                            // tolgo d finche' si puo'
            _v[(*_n)++] = d;
            _x /= d;
        }
    if (_x > 1) _v[(*_n)++] = _x;                        // quello che resta e' primo
}


/**
 * Calcola il coefficiente binomiale "n su k" (quanti modi di scegliere k elementi tra n).
 * @param int Numero n.
 * @param int Numero k.
 * @return Coefficiente binomiale, oppure 0 se k < 0 o k > n.
 *
 * COME FUNZIONA:
 *   Calcola n su k con il prodotto ris = ris * (n - k + i) / i per i da
 *   1 a k: a ogni passo il risultato resta intero. Usa C(n,k) =
 *   C(n,n-k) per fare meno passaggi.
 *
 * ESEMPIO:  long long risultato = calcolaBinomiale(n, k);
 */
long long calcolaBinomiale(int _n, int _k) {
    if (_k < 0 || _k > _n) return 0;
    if (_k > _n - _k) _k = _n - _k;                      // C(n,k) = C(n,n-k): meno passaggi
    long long ris = 1;
    for (int i = 1; i <= _k; i++)
        ris = ris * (_n - _k + i) / i;                   // a ogni passo il risultato e' ancora intero
    return ris;
}



/* ---------- 3.2 VETTORI EXTRA ---------- */

/**
 * Riempie il vettore con numeri casuali TUTTI DIVERSI tra min e max (inclusi).
 * Attenzione: deve valere (max - min + 1) >= n, altrimenti non termina.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore minimo.
 * @param int Valore massimo.
 *
 * COME FUNZIONA:
 *   Per ogni posizione genera numeri casuali con un do...while,
 *   ripetendo finche' il numero NON e' gia' presente nelle posizioni
 *   precedenti.
 *
 * ESEMPIO:  riempiVettoreCasualeUnici(n, v, min, max);
 */
void riempiVettoreCasualeUnici(int _n, int _v[_n], int _min, int _max) {
    for (int i = 0; i < _n; i++) {
        int x;
        do {
            x = rand() % (_max - _min + 1) + _min;
        } while (cercaInVettore(i, _v, x) != -1);        // ripeto finche' e' gia' presente
        _v[i] = x;
    }
}

/**
 * Stampa il vettore partendo dall'ultimo elemento (senza modificarlo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Ciclo for che parte da n-1 e scende fino a 0.
 *
 * ESEMPIO:  stampaVettoreInverso(n, v);
 */
void stampaVettoreInverso(int _n, int _v[_n]) {
    for (int i = _n - 1; i >= 0; i--)
        printf("%d ", _v[i]);
    printf("\n");
}

/**
 * Trova il secondo valore piu' grande (strettamente minore del massimo).
 * Se tutti gli elementi sono uguali restituisce il massimo.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Secondo massimo.
 *
 * COME FUNZIONA:
 *   Trova il massimo, poi cerca il valore piu' grande tra quelli
 *   STRETTAMENTE minori del massimo (quindi un massimo ripetuto non
 *   conta come secondo).
 *
 * ESEMPIO:  int risultato = trovaSecondoMassimoVettore(n, v);
 */
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

/**
 * Calcola la moda: il valore che compare piu' volte (a parita', il primo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Moda del vettore.
 *
 * COME FUNZIONA:
 *   Per ogni elemento conta quante volte compare
 *   (contaOccorrenzeVettore) e tiene quello con il conteggio maggiore;
 *   a parita' resta il primo.
 *
 * ESEMPIO:  int risultato = calcolaModaVettore(n, v);
 */
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

/**
 * Calcola la mediana (non modifica il vettore, lavora su una copia).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Mediana del vettore.
 *
 * COME FUNZIONA:
 *   Lavora su una copia (il vettore originale non cambia): la ordina;
 *   se n e' dispari la mediana e' l'elemento centrale, se e' pari la
 *   media dei due centrali.
 *
 * ESEMPIO:  float risultato = calcolaMedianaVettore(n, v);
 */
float calcolaMedianaVettore(int _n, int _v[_n]) {
    int tmp[_n];                                         // lavoro su una copia
    copiaVettore(_n, _v, tmp);
    ordinaInsertionSort(_n, tmp);
    if (_n % 2 == 1) return tmp[_n / 2];                 // dispari: elemento centrale
    return (tmp[_n / 2 - 1] + tmp[_n / 2]) / 2.0f;       // pari: media dei due centrali
}

/**
 * Calcola la differenza tra il massimo e il minimo (escursione).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Massimo - minimo.
 *
 * COME FUNZIONA:
 *   Massimo meno minimo, usando le funzioni gia' scritte.
 *
 * ESEMPIO:  int risultato = calcolaDifferenzaMaxMin(n, v);
 */
int calcolaDifferenzaMaxMin(int _n, int _v[_n]) {
    return trovaMassimoVettore(_n, _v) - trovaMinimoVettore(_n, _v);
}

/**
 * Somma gli elementi nelle posizioni (indici) pari: v[0] + v[2] + v[4] + ...
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Somma degli elementi in posizione pari.
 *
 * COME FUNZIONA:
 *   Il ciclo parte da 0 e avanza di 2 in 2 (i += 2): somma v[0], v[2],
 *   v[4], ...
 *
 * ESEMPIO:  int risultato = calcolaSommaPosizioniPariVettore(n, v);
 */
int calcolaSommaPosizioniPariVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i += 2)
        somma += _v[i];
    return somma;
}

/**
 * Somma gli elementi nelle posizioni (indici) dispari: v[1] + v[3] + v[5] + ...
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Somma degli elementi in posizione dispari.
 *
 * COME FUNZIONA:
 *   Il ciclo parte da 1 e avanza di 2 in 2 (i += 2): somma v[1], v[3],
 *   v[5], ...
 *
 * ESEMPIO:  int risultato = calcolaSommaPosizioniDispariVettore(n, v);
 */
int calcolaSommaPosizioniDispariVettore(int _n, int _v[_n]) {
    int somma = 0;
    for (int i = 1; i < _n; i += 2)
        somma += _v[i];
    return somma;
}

/**
 * Calcola le somme cumulative: out[i] = v[0] + v[1] + ... + v[i].
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int* Vettore risultato.
 *
 * COME FUNZIONA:
 *   Un accumulatore somma man mano gli elementi; ad ogni passo il
 *   valore corrente viene salvato in out[i].
 *
 * ESEMPIO:  calcolaSommeCumulativeVettore(n, v, out);
 */
void calcolaSommeCumulativeVettore(int _n, int _v[_n], int _out[_n]) {
    int somma = 0;
    for (int i = 0; i < _n; i++) {
        somma += _v[i];
        _out[i] = somma;
    }
}

/**
 * Trova la lunghezza della piu' lunga sequenza consecutiva strettamente crescente.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Lunghezza massima trovata.
 *
 * COME FUNZIONA:
 *   Tiene la lunghezza della sequenza corrente: se v[i] > v[i-1] la
 *   aumenta, altrimenti riparte da 1. Memorizza il valore massimo
 *   raggiunto.
 *
 * ESEMPIO:  int risultato = trovaLunghezzaSequenzaCrescenteMax(n, v);
 */
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

/**
 * Cerca un sottovettore (sequenza consecutiva) dentro un vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero di elementi del sottovettore.
 * @param int* Riferimento al sottovettore.
 * @return Indice di inizio della prima occorrenza, oppure -1.
 *
 * COME FUNZIONA:
 *   Prova ogni possibile posizione di partenza i e confronta sub con
 *   gli m elementi a partire da i; se tutti coincidono restituisce i.
 *
 * ESEMPIO:  int risultato = cercaSottovettore(n, v, m, sub);
 */
int cercaSottovettore(int _n, int _v[_n], int _m, int _sub[_m]) {
    for (int i = 0; i + _m <= _n; i++) {
        bool uguale = true;
        for (int j = 0; j < _m && uguale; j++)
            if (_v[i + j] != _sub[j]) uguale = false;
        if (uguale) return i;
    }
    return -1;
}

/**
 * Verifica se un vettore e' una permutazione dell'altro (stessi elementi, ordine diverso).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @return true se sono permutazione l'uno dell'altro, false altrimenti.
 *
 * COME FUNZIONA:
 *   Due vettori sono una permutazione se hanno la stessa lunghezza e
 *   ogni valore compare lo stesso numero di volte in entrambi.
 *
 * ESEMPIO:  bool risultato = verificaVettoriPermutazione(na, a, nb, b);
 */
bool verificaVettoriPermutazione(int _na, int _a[_na], int _nb, int _b[_nb]) {
    if (_na != _nb) return false;
    for (int i = 0; i < _na; i++)                        // ogni valore deve comparire lo stesso numero di volte
        if (contaOccorrenzeVettore(_na, _a, _a[i]) != contaOccorrenzeVettore(_nb, _b, _a[i]))
            return false;
    return true;
}

/**
 * Calcola l'unione: tutti gli elementi di a e di b, senza ripetizioni.
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @param int* Vettore risultato (deve contenere almeno na + nb elementi).
 * @param int* Puntatore al numero di elementi del risultato (viene calcolato).
 *
 * COME FUNZIONA:
 *   Aggiunge in c ogni elemento di a e poi di b, ma solo se non e' gia'
 *   presente in c.
 *
 * ESEMPIO:  unioneVettori(na, a, nb, b, c, &nc);
 */
void unioneVettori(int _na, int _a[_na], int _nb, int _b[_nb], int _c[], int *_nc) {
    *_nc = 0;
    for (int i = 0; i < _na; i++)
        if (cercaInVettore(*_nc, _c, _a[i]) == -1) _c[(*_nc)++] = _a[i];
    for (int i = 0; i < _nb; i++)
        if (cercaInVettore(*_nc, _c, _b[i]) == -1) _c[(*_nc)++] = _b[i];
}

/**
 * Separa gli elementi pari da quelli dispari in due vettori (mantenendo l'ordine).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int* Vettore dei pari (almeno n elementi).
 * @param int* Puntatore al numero di pari (viene calcolato).
 * @param int* Vettore dei dispari (almeno n elementi).
 * @param int* Puntatore al numero di dispari (viene calcolato).
 *
 * COME FUNZIONA:
 *   Un solo ciclo: ogni elemento va nel vettore dei pari o in quello
 *   dei dispari, ognuno con il proprio contatore.
 *
 * ESEMPIO:  separaPariDispari(n, v, pari, &np, dispari, &nd);
 */
void separaPariDispari(int _n, int _v[_n], int _pari[], int *_np, int _dispari[], int *_nd) {
    *_np = 0;
    *_nd = 0;
    for (int i = 0; i < _n; i++) {
        if (_v[i] % 2 == 0) _pari[(*_np)++] = _v[i];
        else                _dispari[(*_nd)++] = _v[i];
    }
}

/**
 * Sposta tutti gli 0 in fondo al vettore, mantenendo l'ordine degli altri elementi.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Copia in avanti (con l'indice k) solo gli elementi diversi da 0,
 *   mantenendone l'ordine; poi riempie le posizioni rimaste con 0.
 *
 * ESEMPIO:  spostaZeriInFondoVettore(n, v);
 */
void spostaZeriInFondoVettore(int _n, int _v[_n]) {
    int k = 0;                                           // prossima posizione per un non-zero
    for (int i = 0; i < _n; i++)
        if (_v[i] != 0) _v[k++] = _v[i];
    while (k < _n) _v[k++] = 0;                          // riempio il resto di zeri
}

/**
 * Inserisce un valore in un vettore GIA' ORDINATO crescente, mantenendolo ordinato.
 * @param int* Puntatore al numero di elementi (viene aumentato di 1).
 * @param int Capacita' massima del vettore.
 * @param int* Riferimento al vettore (ordinato crescente).
 * @param int Valore da inserire.
 * @return true se l'inserimento e' riuscito, false se il vettore e' pieno.
 *
 * COME FUNZIONA:
 *   Trova la prima posizione dove v[pos] >= x e poi usa
 *   inserisciInVettore per inserire in quel punto: il vettore resta
 *   ordinato.
 *
 * ESEMPIO:  bool risultato = inserisciOrdinatoVettore(&n, capacita, v, x);
 */
bool inserisciOrdinatoVettore(int *_n, int _capacita, int _v[], int _x) {
    int pos = 0;
    while (pos < *_n && _v[pos] < _x)                    // trovo il primo elemento >= x
        pos++;
    return inserisciInVettore(_n, _capacita, _v, pos, _x);
}


/**
 * Trova la somma massima che si puo' ottenere sommando elementi CONSECUTIVI del vettore
 * (algoritmo di Kadane). Con tutti elementi negativi restituisce il massimo elemento.
 * @param int Numero di elementi del vettore (>= 1).
 * @param int* Riferimento al vettore.
 * @return Somma massima di un tratto consecutivo.
 *
 * COME FUNZIONA:
 *   Algoritmo di Kadane: tiene la somma migliore di un tratto che
 *   finisce nella posizione i. Se la somma precedente e' positiva
 *   conviene continuare il tratto, altrimenti si riparte da v[i].
 *
 * ESEMPIO:  int risultato = trovaSommaSottovettoreMax(n, v);
 */
int trovaSommaSottovettoreMax(int _n, int _v[_n]) {
    int migliore = _v[0];
    int corrente = _v[0];                                // somma migliore che finisce nella posizione i
    for (int i = 1; i < _n; i++) {
        if (corrente > 0) corrente += _v[i];             // continuare conviene solo se la somma e' positiva
        else corrente = _v[i];                           // altrimenti riparto da qui
        if (corrente > migliore) migliore = corrente;
    }
    return migliore;
}


/**
 * Conta le coppie di posizioni (i < j) i cui elementi sommano a un valore dato.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Somma cercata.
 * @return Numero di coppie trovate.
 *
 * COME FUNZIONA:
 *   Doppio ciclo con j che parte da i + 1: ogni coppia di posizioni
 *   viene controllata una volta sola; si conta se la somma vale quella
 *   cercata.
 *
 * ESEMPIO:  int risultato = contaCoppieSommaVettore(n, v, somma);
 */
int contaCoppieSommaVettore(int _n, int _v[_n], int _somma) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        for (int j = i + 1; j < _n; j++)                 // j parte da i+1: ogni coppia contata una volta sola
            if (_v[i] + _v[j] == _somma) cont++;
    return cont;
}


/**
 * Verifica se ogni elemento di a e' presente anche in b (come verificaSottoinsiemeVettore).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @return true se tutti gli elementi di a sono in b, false altrimenti.
 *
 * COME FUNZIONA:
 *   Per ogni elemento di a controlla con cercaInVettore che sia
 *   presente anche in b; al primo che manca restituisce false.
 *
 * ESEMPIO:  bool risultato = verificaVettoreSottoinsieme(na, a, nb, b);
 */
bool verificaVettoreSottoinsieme(int _na, int _a[_na], int _nb, int _b[_nb]) {
    for (int i = 0; i < _na; i++)
        if (cercaInVettore(_nb, _b, _a[i]) == -1) return false;
    return true;
}


/**
 * Elimina tutti gli elementi pari dal vettore, mantenendo l'ordine degli altri.
 * @param int* Puntatore al numero di elementi (viene aggiornato).
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Scorre il vettore e quando trova un pari lo elimina SENZA
 *   incrementare i (al suo posto e' arrivato un nuovo elemento da
 *   controllare).
 *
 * ESEMPIO:  eliminaPariVettore(&n, v);
 */
void eliminaPariVettore(int *_n, int _v[]) {
    int i = 0;
    while (i < *_n) {
        if (_v[i] % 2 == 0) eliminaDaVettore(_n, _v, i); // NON incremento i, come in eliminaValoreVettore
        else i++;
    }
}


/**
 * Ruota il vettore a sinistra di k posizioni (con k negativo ruota a destra).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Numero di posizioni di cui ruotare.
 *
 * COME FUNZIONA:
 *   Ruotare a sinistra di k equivale a ruotare a destra di -k: richiama
 *   ruotaDestraKVettore.
 *
 * ESEMPIO:  ruotaSinistraKVettore(n, v, k);
 */
void ruotaSinistraKVettore(int _n, int _v[_n], int _k) {
    ruotaDestraKVettore(_n, _v, -_k);                    // ruotare a sinistra di k = a destra di -k
}


/**
 * Inverte l'ordine degli elementi tra due posizioni (estremi inclusi); il resto resta uguale.
 * Gli indici devono essere validi (0 <= inizio, fine < n).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Indice del primo elemento del tratto.
 * @param int Indice dell'ultimo elemento del tratto.
 *
 * COME FUNZIONA:
 *   Due indici (uno parte da inizio, l'altro da fine) si scambiano gli
 *   elementi e si avvicinano fino a incontrarsi.
 *
 * ESEMPIO:  invertiParteVettore(n, v, inizio, fine);
 */
void invertiParteVettore(int _n, int _v[_n], int _inizio, int _fine) {
    (void) _n;
    while (_inizio < _fine) {
        scambia(&_v[_inizio], &_v[_fine]);
        _inizio++;
        _fine--;
    }
}


/**
 * Mescola a caso gli elementi del vettore (algoritmo di Fisher-Yates).
 * Ricordarsi di chiamare srand(time(0)) una sola volta nel main.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Algoritmo di Fisher-Yates: dall'ultima posizione verso la prima
 *   scambia v[i] con un elemento a caso tra le posizioni 0 e i. Serve
 *   srand(time(0)) nel main.
 *
 * ESEMPIO:  mescolaVettore(n, v);
 */
void mescolaVettore(int _n, int _v[_n]) {
    for (int i = _n - 1; i > 0; i--) {                   // Fisher-Yates: scambio v[i] con uno a caso tra 0 e i
        int j = rand() % (i + 1);
        scambia(&_v[i], &_v[j]);
    }
}


/**
 * Conta quanti valori DIVERSI ci sono nel vettore (come contaElementiDistintiVettore).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di valori distinti.
 *
 * COME FUNZIONA:
 *   Un elemento e' 'nuovo' se non compare tra quelli che lo precedono:
 *   si conta con cercaInVettore sulle prime i posizioni.
 *
 * ESEMPIO:  int risultato = contaValoriDistintiVettore(n, v);
 */
int contaValoriDistintiVettore(int _n, int _v[_n]) {
    int cont = 0;
    for (int i = 0; i < _n; i++)
        if (cercaInVettore(i, _v, _v[i]) == -1)          // non l'ho visto tra i primi i elementi
            cont++;
    return cont;
}



/* ---------- 3.3 MATRICI EXTRA ---------- */

/**
 * Calcola la traccia di una matrice quadrata (somma della diagonale principale).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return Traccia della matrice.
 *
 * COME FUNZIONA:
 *   La traccia e' la somma della diagonale principale: richiama
 *   calcolaSommaDiagonalePrincipale.
 *
 * ESEMPIO:  int risultato = calcolaTraccia(n, m);
 */
int calcolaTraccia(int _n, int _m[_n][_n]) {
    return calcolaSommaDiagonalePrincipale(_n, _m);
}

/**
 * Salva in un vettore il massimo di ogni riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (rows elementi).
 *
 * COME FUNZIONA:
 *   Per ogni riga i salva in out[i] il massimo di quella riga.
 *
 * ESEMPIO:  calcolaMassimiRighe(rows, cols, m, out);
 */
void calcolaMassimiRighe(int _rows, int _cols, int _m[_rows][_cols], int _out[_rows]) {
    for (int i = 0; i < _rows; i++)
        _out[i] = trovaMassimoRiga(_rows, _cols, _m, i);
}

/**
 * Salva in un vettore il massimo di ogni colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Vettore risultato (cols elementi).
 *
 * COME FUNZIONA:
 *   Per ogni colonna j salva in out[j] il massimo di quella colonna.
 *
 * ESEMPIO:  calcolaMassimiColonne(rows, cols, m, out);
 */
void calcolaMassimiColonne(int _rows, int _cols, int _m[_rows][_cols], int _out[_cols]) {
    for (int j = 0; j < _cols; j++)
        _out[j] = trovaMassimoColonna(_rows, _cols, _m, j);
}

/**
 * Salva in un vettore la media di ogni riga.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param float* Vettore risultato (rows elementi).
 *
 * COME FUNZIONA:
 *   Somma della riga divisa per il numero di colonne (con cast a
 *   float).
 *
 * ESEMPIO:  calcolaMedieRighe(rows, cols, m, out);
 */
void calcolaMedieRighe(int _rows, int _cols, int _m[_rows][_cols], float _out[_rows]) {
    for (int i = 0; i < _rows; i++)
        _out[i] = (float) calcolaSommaRiga(_rows, _cols, _m, i) / _cols;
}

/**
 * Salva in un vettore la media di ogni colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param float* Vettore risultato (cols elementi).
 *
 * COME FUNZIONA:
 *   Somma della colonna divisa per il numero di righe (con cast a
 *   float).
 *
 * ESEMPIO:  calcolaMedieColonne(rows, cols, m, out);
 */
void calcolaMedieColonne(int _rows, int _cols, int _m[_rows][_cols], float _out[_cols]) {
    for (int j = 0; j < _cols; j++)
        _out[j] = (float) calcolaSommaColonna(_rows, _cols, _m, j) / _rows;
}

/**
 * Stampa su una riga gli elementi della diagonale secondaria.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Un solo ciclo che stampa m[i][n-1-i].
 *
 * ESEMPIO:  stampaDiagonaleSecondaria(n, m);
 */
void stampaDiagonaleSecondaria(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        printf("%d ", _m[i][_n - 1 - i]);
    printf("\n");
}

/**
 * Stampa gli elementi della matrice "a spirale" (verso orario, dall'angolo in alto a sinistra).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Quattro variabili (alto, basso, sinistra, destra) delimitano la
 *   parte ancora da stampare. Si stampa la riga in alto verso destra,
 *   la colonna a destra verso il basso, la riga in basso verso
 *   sinistra, la colonna a sinistra verso l'alto; dopo ogni lato il
 *   bordo si restringe.
 *
 * ESEMPIO:  stampaMatriceSpirale(rows, cols, m);
 */
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

/**
 * Riempie la matrice con i numeri 1, 2, 3, ... disposti a spirale (verso orario).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Stesso percorso della stampa a spirale, ma invece di stampare
 *   scrive i numeri 1, 2, 3, ...
 *
 * ESEMPIO:  riempiMatriceSpirale(rows, cols, m);
 */
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

/**
 * Crea il triangolo di Pascal (coefficienti binomiali) in una matrice n x n.
 * Gli elementi sopra la diagonale vengono messi a 0.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Prima azzera la matrice. Ogni riga inizia con 1; ogni altro
 *   elemento e' la somma dell'elemento sopra e di quello sopra a
 *   sinistra: m[i][j] = m[i-1][j-1] + m[i-1][j].
 *
 * ESEMPIO:  creaTriangoloPascal(n, m);
 */
void creaTriangoloPascal(int _n, int _m[_n][_n]) {
    riempiMatriceCon(_n, _n, _m, 0);
    for (int i = 0; i < _n; i++) {
        _m[i][0] = 1;                                    // primo elemento di ogni riga = 1
        for (int j = 1; j <= i; j++)
            _m[i][j] = _m[i - 1][j - 1] + _m[i - 1][j];  // somma dei due elementi sopra
    }
}

/**
 * Ordina TUTTI gli elementi della matrice in modo crescente (riga per riga).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Trucco: 'srotola' la matrice in un vettore (matriceInVettore), lo
 *   ordina e lo rimette nella matrice (vettoreInMatrice).
 *
 * ESEMPIO:  ordinaMatriceCrescente(rows, cols, m);
 */
void ordinaMatriceCrescente(int _rows, int _cols, int _m[_rows][_cols]) {
    int tmp[_rows * _cols];
    matriceInVettore(_rows, _cols, _m, tmp);             // "srotolo" la matrice in un vettore
    ordinaInsertionSort(_rows * _cols, tmp);             // ordino il vettore
    vettoreInMatrice(_rows, _cols, tmp, _m);             // lo rimetto nella matrice
}

/**
 * Ordina in modo crescente ogni riga della matrice (separatamente).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Richiama ordinaRigaMatrice su ogni riga.
 *
 * ESEMPIO:  ordinaRigheMatrice(rows, cols, m);
 */
void ordinaRigheMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        ordinaRigaMatrice(_rows, _cols, _m, i);
}

/**
 * Ordina in modo crescente gli elementi di una singola colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Indice della colonna da ordinare.
 *
 * COME FUNZIONA:
 *   Bubble sort applicato ai soli elementi di una colonna.
 *
 * ESEMPIO:  ordinaColonnaMatrice(rows, cols, m, col);
 */
void ordinaColonnaMatrice(int _rows, int _cols, int _m[_rows][_cols], int _col) {
    for (int i = 0; i < _rows - 1; i++)
        for (int j = 0; j < _rows - 1 - i; j++)
            if (_m[j][_col] > _m[j + 1][_col])
                scambia(&_m[j][_col], &_m[j + 1][_col]);
}

/**
 * Calcola il minore (determinante della sottomatrice senza la riga e la colonna indicate).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga da togliere.
 * @param int Indice della colonna da togliere.
 * @return Valore del minore.
 *
 * COME FUNZIONA:
 *   Costruisce la sottomatrice senza la riga e la colonna indicate e ne
 *   calcola il determinante.
 *
 * ESEMPIO:  long long risultato = calcolaMinore(n, m, riga, col);
 */
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

/**
 * Calcola il complemento algebrico (cofattore): minore con segno (-1)^(riga+colonna).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param int Indice della riga.
 * @param int Indice della colonna.
 * @return Valore del cofattore.
 *
 * COME FUNZIONA:
 *   E' il minore con segno: + se (riga + colonna) e' pari, - se e'
 *   dispari (segni a scacchiera).
 *
 * ESEMPIO:  long long risultato = calcolaCofattore(n, m, riga, col);
 */
long long calcolaCofattore(int _n, int _m[_n][_n], int _riga, int _col) {
    long long minore = calcolaMinore(_n, _m, _riga, _col);
    return ((_riga + _col) % 2 == 0) ? minore : -minore; // segno a scacchiera + - + -
}

/**
 * Verifica se la matrice e' invertibile (determinante diverso da 0).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se invertibile, false altrimenti.
 *
 * COME FUNZIONA:
 *   Una matrice quadrata e' invertibile solo se il suo determinante e'
 *   diverso da 0.
 *
 * ESEMPIO:  bool risultato = verificaMatriceInvertibile(n, m);
 */
bool verificaMatriceInvertibile(int _n, int _m[_n][_n]) {
    return calcolaDeterminante(_n, _m) != 0;
}

/**
 * Calcola la matrice inversa: (1 / det) * trasposta della matrice dei cofattori.
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @param float* Matrice risultato (n x n, di float).
 * @return true se l'inversa esiste, false se il determinante e' 0.
 *
 * COME FUNZIONA:
 *   Formula: inversa = (1 / det) * trasposta della matrice dei
 *   cofattori. Per questo ris[j][i] (indici scambiati) vale
 *   cofattore(i, j) / det. Se det == 0 l'inversa non esiste.
 *
 * ESEMPIO:  bool risultato = calcolaMatriceInversa(n, m, ris);
 */
bool calcolaMatriceInversa(int _n, int _m[_n][_n], float _ris[_n][_n]) {
    long long det = calcolaDeterminante(_n, _m);
    if (det == 0) return false;
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            _ris[j][i] = (float) calcolaCofattore(_n, _m, i, j) / det;   // [j][i]: trasposta dei cofattori
    return true;
}

/**
 * Cerca un punto di sella: elemento minimo della propria riga e massimo della propria colonna.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Puntatore dove salvare la riga trovata.
 * @param int* Puntatore dove salvare la colonna trovata.
 * @return true se esiste un punto di sella, false altrimenti.
 *
 * COME FUNZIONA:
 *   Per ogni riga trova il minimo; poi controlla se quel minimo e'
 *   anche il MASSIMO della sua colonna: se si', e' un punto di sella.
 *
 * ESEMPIO:  bool risultato = trovaPuntoSella(rows, cols, m, &riga, &col);
 */
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

/**
 * Calcola la somma degli elementi "vicini" (fino a 8, quelli adiacenti anche in diagonale),
 * escluso l'elemento stesso. Gestisce correttamente bordi e angoli.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Riga dell'elemento.
 * @param int Colonna dell'elemento.
 * @return Somma dei vicini.
 *
 * COME FUNZIONA:
 *   Due cicli con spostamenti -1, 0, +1 su riga e colonna (8 vicini;
 *   salta (0,0), cioe' l'elemento stesso); somma solo le posizioni che
 *   non escono dalla matrice.
 *
 * ESEMPIO:  int risultato = calcolaSommaVicini(rows, cols, m, riga, col);
 */
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

/**
 * Ruota la matrice di 90 gradi in senso ANTIORARIO.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (cols x rows).
 *
 * COME FUNZIONA:
 *   L'elemento (i, j) finisce in (cols-1-j, i): la prima riga diventa
 *   la prima colonna letta dal basso verso l'alto.
 *
 * ESEMPIO:  ruotaMatrice90Antiorario(rows, cols, m, ris);
 */
void ruotaMatrice90Antiorario(int _rows, int _cols, int _m[_rows][_cols], int _ris[_cols][_rows]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[_cols - 1 - j][i] = _m[i][j];
}

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
 *
 * COME FUNZIONA:
 *   Due cicli annidati che vanno da (r1, c1) a (r2, c2), estremi
 *   inclusi, sommando gli elementi.
 *
 * ESEMPIO:  int risultato = calcolaSommaSottomatrice(rows, cols, m, r1, c1, r2, c2);
 */
int calcolaSommaSottomatrice(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _c1, int _r2, int _c2) {
    (void) _rows;
    (void) _cols;
    int somma = 0;
    for (int i = _r1; i <= _r2; i++)
        for (int j = _c1; j <= _c2; j++)
            somma += _m[i][j];
    return somma;
}

/**
 * Sostituisce ogni occorrenza di un valore con un altro.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Valore da sostituire.
 * @param int Nuovo valore.
 *
 * COME FUNZIONA:
 *   Scorre la matrice e ogni volta che trova il valore vecchio lo
 *   sovrascrive con il nuovo.
 *
 * ESEMPIO:  sostituisciInMatrice(rows, cols, m, vecchio, nuovo);
 */
void sostituisciInMatrice(int _rows, int _cols, int _m[_rows][_cols], int _vecchio, int _nuovo) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] == _vecchio) _m[i][j] = _nuovo;
}

/**
 * Conta gli elementi della matrice che sono numeri primi.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Numero di elementi primi.
 *
 * COME FUNZIONA:
 *   Per ogni elemento chiama verificaPrimo e conta quelli per cui e'
 *   vera.
 *
 * ESEMPIO:  int risultato = contaPrimiMatrice(rows, cols, m);
 */
int contaPrimiMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (verificaPrimo(_m[i][j])) cont++;
    return cont;
}


/**
 * Conta gli elementi positivi (> 0) della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Numero di elementi positivi.
 *
 * COME FUNZIONA:
 *   Due cicli annidati con un contatore: incrementa quando m[i][j] > 0.
 *
 * ESEMPIO:  int risultato = contaPositiviMatrice(rows, cols, m);
 */
int contaPositiviMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] > 0) cont++;
    return cont;
}


/**
 * Conta gli elementi negativi (< 0) della matrice.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @return Numero di elementi negativi.
 *
 * COME FUNZIONA:
 *   Due cicli annidati con un contatore: incrementa quando m[i][j] < 0.
 *
 * ESEMPIO:  int risultato = contaNegativiMatrice(rows, cols, m);
 */
int contaNegativiMatrice(int _rows, int _cols, int _m[_rows][_cols]) {
    int cont = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_m[i][j] < 0) cont++;
    return cont;
}


/**
 * Riempie la matrice a scacchiera: 0 e 1 alternati (m[i][j] = (i + j) % 2).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   m[i][j] = (i + j) % 2: vale 0 quando riga + colonna e' pari e 1
 *   quando e' dispari, quindi i valori si alternano come le caselle di
 *   una scacchiera.
 *
 * ESEMPIO:  riempiMatriceScacchiera(rows, cols, m);
 */
void riempiMatriceScacchiera(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = (i + j) % 2;                      // riga + colonna dispari -> 1
}


/**
 * Ruota di 90 gradi in senso orario una matrice QUADRATA, modificando la matrice stessa
 * (senza matrice di appoggio).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   Una rotazione oraria di 90 gradi equivale a fare la trasposta e poi
 *   specchiare ogni riga (si invertono le colonne). Non serve una
 *   seconda matrice.
 *
 * ESEMPIO:  ruotaMatriceQuadrata90OrarioSulPosto(n, m);
 */
void ruotaMatriceQuadrata90OrarioSulPosto(int _n, int _m[_n][_n]) {
    traspostaSulPosto(_n, _m);                           // prima la trasposta...
    specchiaMatriceOrizzontale(_n, _n, _m);              // ...poi inverto ogni riga = rotazione oraria
}



/* ---------- 3.4 ALTRE FUNZIONI UTILI ---------- */

/**
 * Salva in un vettore le posizioni di TUTTE le occorrenze di un valore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da cercare.
 * @param int* Vettore dove salvare le posizioni (almeno n elementi).
 * @param int* Puntatore al numero di posizioni trovate (viene calcolato).
 *
 * COME FUNZIONA:
 *   Come cercaInVettore ma non si ferma alla prima: ogni volta che v[i]
 *   == x salva l'indice i in pos e aumenta il contatore.
 *
 * ESEMPIO:  cercaTutteOccorrenzeVettore(n, v, x, pos, &np);
 */
void cercaTutteOccorrenzeVettore(int _n, int _v[_n], int _x, int _pos[], int *_np) {
    *_np = 0;
    for (int i = 0; i < _n; i++)
        if (_v[i] == _x) _pos[(*_np)++] = i;             // salvo l'indice e aumento il contatore
}

/**
 * Conta quanti valori DIVERSI ci sono nel vettore (i duplicati contano una volta sola).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Numero di valori distinti.
 *
 * COME FUNZIONA:
 *   Un elemento e' 'nuovo' se non compare nelle posizioni precedenti
 *   (cercaInVettore sulle prime i posizioni): si contano solo quelli.
 *
 * ESEMPIO:  int risultato = contaElementiDistintiVettore(n, v);
 */
int contaElementiDistintiVettore(int _n, int _v[_n]) {
    int distinti = 0;
    for (int i = 0; i < _n; i++)
        if (cercaInVettore(i, _v, _v[i]) == -1)          // non compare nelle posizioni precedenti: e' "nuovo"
            distinti++;
    return distinti;
}

/**
 * Verifica se un valore e' presente nel vettore.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore da cercare.
 * @return true se presente, false altrimenti.
 *
 * COME FUNZIONA:
 *   Richiama cercaInVettore e controlla che il risultato non sia -1.
 *
 * ESEMPIO:  bool risultato = verificaPresenteInVettore(n, v, x);
 */
bool verificaPresenteInVettore(int _n, int _v[_n], int _x) {
    return cercaInVettore(_n, _v, _x) != -1;
}

/**
 * Calcola la varianza: media dei quadrati degli scarti dalla media.
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return Varianza del vettore.
 *
 * COME FUNZIONA:
 *   Calcola la media, poi somma i quadrati degli scarti (v[i] - media)
 *   e divide per n. La deviazione standard e' la radice quadrata della
 *   varianza (sqrt, da math.h).
 *
 * ESEMPIO:  float risultato = calcolaVarianzaVettore(n, v);
 */
float calcolaVarianzaVettore(int _n, int _v[_n]) {
    float media = calcolaMediaVettore(_n, _v);
    float somma = 0;
    for (int i = 0; i < _n; i++) {
        float scarto = _v[i] - media;
        somma += scarto * scarto;                        // quadrato dello scarto dalla media
    }
    return somma / _n;
}

/**
 * Calcola le frequenze: freq[k] = quante volte il valore k compare nel vettore.
 * Funziona per valori compresi tra 0 e maxValore (gli altri vengono ignorati).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @param int Valore massimo possibile nel vettore.
 * @param int* Vettore delle frequenze (maxValore + 1 elementi).
 *
 * COME FUNZIONA:
 *   Vettore di frequenze: freq[k] contiene quante volte il valore k
 *   compare in v. Prima azzera tutte le frequenze, poi per ogni
 *   elemento incrementa freq[v[i]].
 *
 * ESEMPIO:  calcolaIstogrammaVettore(n, v, maxValore, freq);
 */
void calcolaIstogrammaVettore(int _n, int _v[_n], int _maxValore, int _freq[_maxValore + 1]) {
    for (int k = 0; k <= _maxValore; k++)
        _freq[k] = 0;                                    // azzero le frequenze
    for (int i = 0; i < _n; i++)
        if (_v[i] >= 0 && _v[i] <= _maxValore)
            _freq[_v[i]]++;                              // il valore stesso e' l'indice della frequenza
}

/**
 * Verifica se il vettore e' una progressione aritmetica
 * (la differenza tra elementi consecutivi e' sempre la stessa).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 * @return true se e' una progressione aritmetica, false altrimenti.
 *
 * COME FUNZIONA:
 *   Calcola la differenza tra i primi due elementi e controlla che ogni
 *   coppia di elementi consecutivi abbia la stessa differenza.
 *
 * ESEMPIO:  bool risultato = verificaProgressioneAritmetica(n, v);
 */
bool verificaProgressioneAritmetica(int _n, int _v[_n]) {
    if (_n <= 2) return true;                            // 0, 1 o 2 elementi: sempre una progressione
    int differenza = _v[1] - _v[0];
    for (int i = 2; i < _n; i++)
        if (_v[i] - _v[i - 1] != differenza) return false;
    return true;
}

/* funzione di appoggio (ricorsiva) per il Quick Sort: ordina v tra gli indici sx e dx */
static void quickSortRicorsivo(int *_v, int _sx, int _dx) {
    if (_sx >= _dx) return;                              // 0 o 1 elemento: gia' ordinato
    int pivot = _v[_dx];                                 // pivot = ultimo elemento
    int i = _sx - 1;                                     // i = fine della zona dei "minori o uguali al pivot"
    for (int j = _sx; j < _dx; j++)
        if (_v[j] <= pivot) {
            i++;
            scambia(&_v[i], &_v[j]);
        }
    scambia(&_v[i + 1], &_v[_dx]);                       // il pivot va tra minori e maggiori
    quickSortRicorsivo(_v, _sx, i);                      // ordino la parte sinistra
    quickSortRicorsivo(_v, i + 2, _dx);                  // ordino la parte destra
}

/**
 * Ordina il vettore in modo CRESCENTE con il Quick Sort (ricorsivo).
 * @param int Numero di elementi del vettore.
 * @param int* Riferimento al vettore.
 *
 * COME FUNZIONA:
 *   Sceglie un pivot (l'ultimo elemento), porta a sinistra i minori e a
 *   destra i maggiori, poi ordina ricorsivamente le due parti (funzione
 *   d'appoggio quickSortRicorsivo).
 *
 * ESEMPIO:  ordinaQuickSort(n, v);
 */
void ordinaQuickSort(int _n, int _v[_n]) {
    quickSortRicorsivo(_v, 0, _n - 1);
}

/**
 * Verifica se ogni elemento di a e' presente anche in b (a e' "contenuto" in b).
 * @param int Numero di elementi del primo vettore.
 * @param int* Primo vettore.
 * @param int Numero di elementi del secondo vettore.
 * @param int* Secondo vettore.
 * @return true se tutti gli elementi di a sono in b, false altrimenti.
 *
 * COME FUNZIONA:
 *   Ogni elemento di a deve essere presente in b (cercaInVettore); al
 *   primo che manca restituisce false.
 *
 * ESEMPIO:  bool risultato = verificaSottoinsiemeVettore(na, a, nb, b);
 */
bool verificaSottoinsiemeVettore(int _na, int _a[_na], int _nb, int _b[_nb]) {
    for (int i = 0; i < _na; i++)
        if (cercaInVettore(_nb, _b, _a[i]) == -1) return false;   // un elemento di a manca in b
    return true;
}

/**
 * Verifica se la matrice quadrata e' antisimmetrica (m[i][j] == -m[j][i]).
 * @param int Dimensione della matrice quadrata.
 * @param int* Riferimento alla matrice.
 * @return true se antisimmetrica, false altrimenti.
 *
 * COME FUNZIONA:
 *   Deve valere m[i][j] == -m[j][i]; sulla diagonale questo significa
 *   che gli elementi sono 0.
 *
 * ESEMPIO:  bool risultato = verificaMatriceAntisimmetrica(n, m);
 */
bool verificaMatriceAntisimmetrica(int _n, int _m[_n][_n]) {
    for (int i = 0; i < _n; i++)
        for (int j = i; j < _n; j++)                     // j parte da i: include la diagonale (deve essere 0)
            if (_m[i][j] != -_m[j][i]) return false;
    return true;
}

/**
 * Riempie la matrice con la tabellina pitagorica: m[i][j] = (i + 1) * (j + 1).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 *
 * COME FUNZIONA:
 *   m[i][j] = (i + 1) * (j + 1): la tabellina pitagorica (gli indici
 *   partono da 0, quindi si aggiunge 1).
 *
 * ESEMPIO:  riempiMatriceTabellina(rows, cols, m);
 */
void riempiMatriceTabellina(int _rows, int _cols, int _m[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = (i + 1) * (j + 1);
}

/**
 * Riempie la matrice con numeri progressivi, riga dopo riga, a partire da un valore.
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Primo valore da scrivere.
 *
 * COME FUNZIONA:
 *   Un contatore parte da start e viene scritto riga dopo riga,
 *   incrementandolo ad ogni elemento.
 *
 * ESEMPIO:  riempiMatriceProgressiva(rows, cols, m, start);
 */
void riempiMatriceProgressiva(int _rows, int _cols, int _m[_rows][_cols], int _start) {
    int k = _start;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _m[i][j] = k++;
}

/**
 * Stampa la matrice con ogni numero allineato a destra in una colonna di larghezza fissa
 * (output piu' ordinato quando i numeri hanno cifre diverse).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int Larghezza di ogni colonna (numero di caratteri).
 *
 * COME FUNZIONA:
 *   Usa printf con %*d: la larghezza viene presa dagli argomenti e ogni
 *   numero resta allineato a destra in una colonna larga larghezza
 *   caratteri.
 *
 * ESEMPIO:  stampaMatriceAllineata(rows, cols, m, larghezza);
 */
void stampaMatriceAllineata(int _rows, int _cols, int _m[_rows][_cols], int _larghezza) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++)
            printf("%*d", _larghezza, _m[i][j]);         // %*d: la larghezza arriva dall'argomento
        printf("\n");
    }
}

/**
 * Ruota la matrice di 180 gradi (equivale a specchiarla in orizzontale e in verticale).
 * @param int Numero di righe della matrice.
 * @param int Numero di colonne della matrice.
 * @param int* Riferimento alla matrice.
 * @param int* Matrice risultato (rows x cols).
 *
 * COME FUNZIONA:
 *   L'elemento (i, j) finisce in (rows-1-i, cols-1-j): e' come
 *   specchiare sia in orizzontale sia in verticale.
 *
 * ESEMPIO:  ruotaMatrice180(rows, cols, m, ris);
 */
void ruotaMatrice180(int _rows, int _cols, int _m[_rows][_cols], int _ris[_rows][_cols]) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _ris[_rows - 1 - i][_cols - 1 - j] = _m[i][j];
}

/* ============================================================
 *  AGGIUNTE: MINIGIOCO BATTAGLIA NAVALE
 * ============================================================ */

void preparaCampo(int campo[LATO][LATO]) {
    // Pulisce la griglia impostando ogni cella a 0 (acqua pulita)
    riempiMatriceCon(LATO, LATO, campo, 0);
}

int piazzaNavi(int campo[LATO][LATO]) {
    int lunghezze[NUM_NAVI] = {4, 3, 3, 2}; // Dimensioni delle 4 navi
    int occupate = 0;
    bool libero;

    for (int n = 0; n < NUM_NAVI; n++) {
        int lung = lunghezze[n];
        int r, c, dr, dc;
        
        do {
            // 1. Sceglie una coordinata di partenza casuale
            r = rand() % LATO;
            c = rand() % LATO;
            
            // 2. Sceglie casualmente la direzione: 0 = Orizzontale (dr=0, dc=1), 1 = Verticale (dr=1, dc=0)
            if (rand() % 2 == 0) { dr = 0; dc = 1; } 
            else                 { dr = 1; dc = 0; } 

            // 3. Controlla se la nave ci sta dentro la griglia e se lo spazio è sgombro (== 0)
            libero = true;
            for (int k = 0; k < lung && libero; k++) {
                int rr = r + dr * k;
                int cc = c + dc * k;
                if (rr >= LATO || cc >= LATO || campo[rr][cc] != 0)
                    libero = false; // Spazio occupato o fuori bordo, ripete il do-while
            }
        } while (!libero);

        // 4. Se lo spazio è libero, piazza effettivamente la nave segnandola con 1
        for (int k = 0; k < lung; k++) {
            campo[r + dr * k][c + dc * k] = 1;
            occupate++;
        }
    }
    return occupate;
}

void stampaCampo(int campo[LATO][LATO], bool mostraNavi) {
    // Stampa l'intestazione delle colonne (da 1 a 10)
    printf("   ");
    for (int j = 0; j < LATO; j++)
        printf("%2d ", j + 1);
    printf("\n");

    // Stampa riga per riga la matrice traducendo i codici numerici in simboli di gioco
    for (int i = 0; i < LATO; i++) {
        printf("%2d ", i + 1); // Indice di riga
        for (int j = 0; j < LATO; j++) {
            if (campo[i][j] == 2)
                printf(" o "); // Acqua mancata (colpo a vuoto)
            else if (campo[i][j] == 3)
                printf(" X "); // Nave colpita in pieno
            else if (campo[i][j] == 1 && mostraNavi)
                printf(" # "); // Nave intera (visibile solo se richiesto dal debug)
            else
                printf(" ~ "); // Acqua nascosta / mare aperto
        }
        printf("\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void chiediColpo(int *riga, int *colonna) {
    // Chiede riga all'utente controllando che rientri nei limiti del tabellone
    do {
        printf("Riga (1-%d): ", LATO);
        scanf("%d", riga);
    } while (*riga < 1 || *riga > LATO);
    
    // Chiede colonna con lo stesso controllo
    do {
        printf("Colonna (1-%d): ", LATO);
        scanf("%d", colonna);
    } while (*colonna < 1 || *colonna > LATO);
    
    // CONVERSIONE CRUCIALE: L'utente inserisce da 1 a 10, ma gli array in C partono da 0 a 9.
    (*riga)--; 
    (*colonna)--;
}

// o prova anche questo

void chiediColpo(int *riga, int *colonna) {
    int r, c;
    do {
        printf("Riga (1-%d): ", LATO);
        // Controlliamo che scanf legga effettivamente un intero
        if (scanf("%d", &r) != 1) {
            // Se l'utente inserisce lettere, puliamo il buffer per evitare loop infiniti
            while (getchar() != '\n');
            r = -1; // Forza la ripetizione del ciclo
        }
    } while (r < 1 || r > LATO);

    do {
        printf("Colonna (1-%d): ", LATO);
        if (scanf("%d", &c) != 1) {
            while (getchar() != '\n');
            c = -1;
        }
    } while (c < 1 || c > LATO);

    *riga = r - 1;     // Conversione da 1..LATO a 0..LATO-1
    *colonna = c - 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int controllaColpo(int campo[LATO][LATO], int riga, int colonna) {
    // Se la cella è già 2 o 3, significa che l'utente aveva già sparato in questa posizione
    if (campo[riga][colonna] >= 2)
        return 2; 
        
    // Se trova 1, c'è una nave: la colpisce trasformando il valore in 3
    if (campo[riga][colonna] == 1) {
        campo[riga][colonna] = 3; 
        return 1; // Colpo andato a segno!
    }
    
    // Altrimenti (trova 0), è acqua: trasforma in 2
    campo[riga][colonna] = 2; 
    return 0; // Acqua
}