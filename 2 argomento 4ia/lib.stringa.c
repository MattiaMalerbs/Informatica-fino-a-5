#include <stdio.h>
#include "lib.stringa.h"
#include <stdbool.h>

void initStringa(int _dim, char _str[]){
    int i;
    for(i=0;i<_dim;i++){
        _str[i] = '\0';
    }
}

int lunghezzaStringa(char _str[]){
    int len;
    len = 0;
    while(_str[len] != '\0')
        len++;
    
    return len;
}

void stampaContrario(char str[]){
    int i;
    int len;

    len=lunghezzaStringa(str);
    for(i=len-1; i>=0; i--){
        printf("%c", str[i]);
    }

}

int contaCarattere(char str[], char src){
    int i;
    int len;
    int cnt;

    len=lunghezzaStringa(str);
    cnt = 0;
    for(i=0; i<len; i++){
        if(str[i] == src)
            cnt++;
    }
    return cnt;
}

void contaInteroAlfabeto(char str[]){
    int i;
    char src;
    src = 'a';
    for(i=0; i<26;i++){
        printf("%c-> %d", (src+i), contaCarattere(str,(src+i)));
        if((i+1)%13 == 0)
            printf("\n");
    }
    
}

bool jew(char str1[], char str2[]){
    
}