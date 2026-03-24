// e adess?
/*programma?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * Check whether a number is prime or not.
 * @param int Number to test.
 * @return boolean true/false.
 */
bool isPrimo(int _n);
/**
 * Verifica se un numero è perfetto oppure no
 * @param int Numero da verificare
 * @return boolean true/false
 */
bool isPerfect(int _n);

int main(){
    int valore;
    int junk;
    for(valore=1; valore <= 7; valore++){
        if(isPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    printf("\n\n");
    for(valore=7; valore <= 15; valore++){
        if(isPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    printf("\n\n");
    for(valore=15; valore <= 25; valore++){
        if(isPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    printf("\n\n");

    return(0);
}

// SEZIONE DELLE FUNZIONI -> DEFINIZIONE DELLE FUNZIONI
bool isPrimo(int _n){
    int div;    // variabile per i divisori del numero passato come parametro.
    int cnt;    // contatore per i divisori trovati del numero passato come parametro.

    cnt = 0;
    for(div=1; div<=_n; div++){
        if(_n%div == 0) // ho trovato un divisore! -> incremento il contatore
            cnt++;
    }

    if(cnt<=2)
        return(true);
    else
        return(false);
}
bool isPerfect(int _n){
    int div;
    int somma;
    somma = 0;
    div = 1;
    while (div < _n){
        if(_n%div == 0)
            somma = somma + div;
        div++;
    }
    if(somma == (_n*2))
        return(true);
    else
        return(false); 
}
