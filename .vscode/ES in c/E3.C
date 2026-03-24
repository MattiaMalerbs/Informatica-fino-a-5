//sezione iclude -> librerie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

//sezione prototipi -> dichiara funzioni
/** 
verifica se un numero risulta primo o no
*@param int numero da testare 
*@return boolean true/false
*/
bool verificaprimo(int n);
/**
 * verifica se un numero è perfetto o no
 * @param boolean int n to test
 * @return boolean true/false
 */
bool vp (int v);
 /**
 * verifica terna pitagorica
 * @param boolean int n1
 * @param boolean int n2
 * @param boolean int n3
 * @return boolean true/false
 */
bool tp (float t);
//main
int main (){

/*
funzioni
*/
int valore;
int junk;
for (valore = 1; valore <= 25; valore ++){
    if(verificaprimo(valore))
        printf("%d -> Primo\n", valore);
}
vp;

return 0;

}
//funzioni -> definisci funzioni
bool verificaprimo(int n){
    int div;
    int cnt;

    cnt = 0;
    for (div = 1; div <= n; div ++) {
        if (n%div == 0)
        cnt ++;
    }
    if (cnt< 2)
        return(true);
    else
        return(false);

}
bool vp (int v){

    int num = 0;
    int div = 0;
    int cnt = 0;
    int som = 0;

    printf("inserisci un numero: ");
    scanf("%d", num);
    for(cnt = 0;num > 1; cnt++ ){

        num = num/2;
        som = som + num;
        printf("%d", som);
        while(num <= 1){
        if (som = num)
        printf("il numero è un numero perfetto");
        else
        printf("il numero non è un numero perfetto");
        }

    }

}