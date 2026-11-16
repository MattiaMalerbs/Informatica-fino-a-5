#include <stdio.h>

void substr(char *dst, char *src, int init, int len){
    int i;
    for(i=0;dst[i]!='\0';i++){
       dst[i]== src[init + i]; 
    }
}