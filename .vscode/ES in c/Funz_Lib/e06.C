/**funzione  rirsiva che stampa all'incontrario le cifre decimali un numero
 * es: printReverse(375) -> 573 
 */

#include <stdio.h>

void printReverse(int n){
    if (n < 10) {
        printf("%d", n);
    } else {
        printf("%d", n % 10);
        printReverse(n / 10);
    }
}

int main(void){

    int num = 0;
    printf("Inserisci un numero intero: ");
    scanf("%d", &num);
    printf("Il numero originale è: %d\n", num);
    printf("Il numero invertito è: ");
    printReverse(num);
    printf("\n");

return 0;

}