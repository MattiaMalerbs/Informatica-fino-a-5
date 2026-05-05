#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "lib.h"

int trovamiprimo(int x, int n) {
    int contatore_primi = 0;
    int candidato = x + 1;

    while (contatore_primi < n) {
        bool es_primo = true;
        
        if (candidato < 2) {
            es_primo = false;
        } else {
            for (int i = 2; i * i <= candidato; ++i) {
                if (candidato % i == 0) {
                    es_primo = false;
                    break;
                }
            }
        }

        if (es_primo) {
            contatore_primi++;
            if (contatore_primi == n) {
                return candidato;
            }
        }
        candidato++;
    }
    return -1;
}

void ordinatrevalori(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a; *a = *b; *b = temp;
    }
    if (*a > *c) {
        temp = *a; *a = *c; *c = temp;
    }
    if (*b > *c) {
        temp = *b; *b = *c; *c = temp;
    }
}

int inputNumeroFiltrato(int _x, int _y, int _z) {
    int valore;
    int valido = 0;

    while (!valido) {
        printf("Inserisci un numero (tra %d e %d, multiplo di %d): ", _x, _y, _z);
        scanf("%d", &valore);

        if (valore >= _x && valore <= _y && valore % _z == 0) {
            valido = 1;
        } else {
            printf("Valore non valido. Riprova.\n");
        }
    }
    return valore;
}

float determinaFigura(int _x, int _y){
    int tmpA = _x;
    int tmpB = _y;

    if(tmpA == 0 || tmpA == 0){
        return -1;
    }

    if(tmpA != tmpB){
        float AT = tmpA *tmpB;
        printf("l'aea del rettangolo è: %f \n", AT);
        return AT;
    }
    else{
        int PQ = tmpA * 4;
        printf("il perimetro del quadrato è: %d \n", PQ);
        return PQ;
    }
}

int comunicazioni (int a, int b, int c, int d){
    int cntA = a;
    int cntB = b;
    int cntC = c;
    int cntD = d;

    int tot = cntA+cntB+cntC+cntD;

    if(cntA > 0){
        printf("hai usato la 1° funzione %d volte \n", cntA);
    }
    if(cntB > 0){
        printf("hai usato la 2° funzione %d volte \n", cntB);
    }
    if(cntC > 0){
        printf("hai usato la 3° funzione %d volte \n", cntC);
    }
    if(cntD > 0){
        printf("hai usato la 4° funzione %d volte \n", cntD);
    }
    printf("totale di funzioni usate: %d\n", tot);
}