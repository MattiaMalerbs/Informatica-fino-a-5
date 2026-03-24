/*
    Semplice programma che esegue tre diverse operazioni su numeri interi, selezionabili
    da un menu numerico con discriminazione tramite switch-case.
    Utilizzo della forma iterativa do-while.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int scelta;     // variabile per la scelta utente.
    int num;        // variabile per il numero in input dell'utente.
    int div;        // variabile per eventuali operazioni sui divisori di un numero.
    int cnt;        // variabile per conteggi tipo divisori, multipli etc...
    char junk;
    int sommaDiv;   // vaiabile per sommare i divisori di un numero
    int N;          // variabile per la generazione di numeri casuali
    ;srand (time (NULL));    // seed random number generator

    do{
        printf("-- MENU --\n");
        printf("1 -> Visualizza divisori\n");
        printf("2 -> Verifica numero primo\n");
        printf("3 -> Verifica numero perfetto\n");
        
        printf("4 -> Genera N numeri casuali <1000 (n inserito da tastiera)\n");
        printf("5 -> Genera N numeri dispari <1000 (n inserito da tastiera)\n");
        printf("6 -> Genera N numeri casuali crescenti <9999 (n inserito da tastiera)\n");
        printf("7 -> Genera un numero casuale, determina il successivo numero primo\n");

        printf("0 -> Termina Programma!\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                // Visualizza a video i divisori di un numero intero acquisito da tastiera.
                // Displays on screen the divisors of an integer entered from the keyboard.
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                // Determina i divisori di un numero contenuto nella variabile num
                // Determines the divisors of a number contained in the variable num
                for(div=1; div<=num; div++){
                    if(num %div == 0){
                        printf("%d ", div);
                    }    
                }
                printf("\n\n");
                break;
            }
            case 2:{
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                cnt = 0;
                for(div=1; div<=num; div++){
                    if(num %div == 0){
                        cnt++;
                    }
                }

                if(cnt <= 2){
                    printf("Il numero %d risulta PRIMO\n", num);
                }
                else{
                    printf("Il numero %d NON risulta essere PRIMO\n", num);
                }
                printf("\n\n");
                break;
            }
            case 3:{
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                //somma dei divisori di un numero
                //sum of the divisors of a number 
                sommaDiv = 0;
                for(div = 1; div <= num; div++) {
                    if(num %div == 0) {
                        sommaDiv++;
                    }
                }
                //verifica della somma e messaggio all'utente
                //sum verification and message to the user
                if(sommaDiv == (num * 2)) {
                    printf("Il numero %d risulta essere PERFETTO.\n", num);
                } else {
                    printf("Il numero %d risulta NON essere PERFETTO.\n", num);
                }
                printf("\n\n");
                break;
            }
            case 4: {
                printf("Quanti numeri vuoi generare?: ");
                scanf("%d", &N);

                printf("Numeri generati: \n");
                for(int i = 0; i < N; i++) {
                int numero = rand() % 10;
                printf("%d \n", numero);
                }
                printf("\n\n");
                break;
            }
            case 5: {
                printf("Quanti numeri dispari vuoi generare: ");
                scanf("%d", &N);

                printf("Numeri generati: \n");
                for(int i = 0; i < N; i++) {
                    int numero = rand() % 10;

                    if(numero % 2 == 0){
                        numero++;
                    }
                    printf("%d\n", numero);
                }
                printf("\n\n");
                break;
            }
            case 6: {
                printf("Quanti numeri casuali crescenti vuoi generare?: ");
                scanf("%d", &N);

                int precedente = 0;
                printf("Numeri generati: \n");
                for(int i = 0; i < N; i++) {
                    int numero = precedente + (rand() % 10 + 1);
                    precedente = numero;
                    printf("%d\n", numero);
                }
                printf("\n\n");
                break;
            }
            case 7: {
                printf("Generazione di un numero casuale e del successivo numero primo:\n");

                int numero = rand() % 100;
                printf("Numero casuale generato: %d\n", numero);

                int prossimo = numero++;
                while (1) {
                    int cnt = 0;
                    for (int div = 1; div <= prossimo; div++) {
                        if (prossimo % div == 0) {
                            cnt++;
                        }
                    }
                    if (cnt <= 2) {
                        break;
                    }
                    prossimo++;
                }
                printf("Il successivo numero primo e': %d\n\n", prossimo);
                break;
            }
        }

    } while(scelta != 0);
    return(0);
}