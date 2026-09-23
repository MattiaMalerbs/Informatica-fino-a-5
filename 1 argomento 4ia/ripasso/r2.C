#include <stdio.h>

#define DIM 5

int main () {
    int i = 0;
    int altezza [DIM];
    int min = altezza[0]; // assegno la prima altezza al valore minimo
    int totale = 0;
    float media = 0; //potevo farla anche float
    int cnt_presente = 0;
    int src = 0;

    for(i=0; i<DIM; i++){
        printf("Inserisci il [%d] valore: ",i+1);
        scanf("%d", &altezza[i]);
        printf("%d \n", altezza[i]);
    }

    for(i=1; i<DIM; i++){
        if(altezza[i] < min)
            min = altezza[i];
    }
    printf("altezza minima = ");
    printf("%d \n", min);

    for(i=0; i<DIM; i++){
        totale = totale + altezza[i];
    }
    media = totale / DIM;
    printf("la media è = %f \n", media);

    for(i=0; i<DIM; i++){ // ciclo di scorrimento del vettore
  //confronto tra contenuto cella e src; se uguali accendo incremento il contatore.
  if(altezza[i] == src) 
    cnt_presente = cnt_presente + 1;
}
printf("Il valore %d è presente %d volta/e.", src, cnt_presente);

}