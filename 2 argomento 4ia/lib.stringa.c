#include <stdio.h>
#include "lib.stringa.h"

void initStringa(int _dim, char _str[]){
    int i;
    for(i=0;i<_dim;i++){
        _str[i] = '\0';
    }
}

