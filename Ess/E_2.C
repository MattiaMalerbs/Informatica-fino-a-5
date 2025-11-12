#include <stdio.h>
int main () {

    int v1;
    char junk;
    //input valore
    printf("inserisci un valore intero: ");
    scanf("%d", &v1);
    junk = getchar();
    //serie di if per capire com'è il valore inserito
    if (v1 > 0) {
        printf("il valore inserito e' positivo\n");
    }
    if (v1==0){
        printf("il valore inserito e' zero\n");
    }
    if (v1 < 0){
        printf("il valore inserito e' negativo\n");
    }
return 0;
}