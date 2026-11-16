#include <stdio.h>

int strcmp(char *s1, char *s2) {
    
    int i;
    for(i=0;s1[i]!='\0';i++){
        if(s1[i]<s2[i])
            return 2;
        if(s1[i]>s2[i])
            return -2;
        if(s1[i]==s2[i])
            return 0;
    }
}