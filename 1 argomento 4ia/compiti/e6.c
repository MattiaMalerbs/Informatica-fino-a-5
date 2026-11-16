#include <stdio.h>
#include <stdbool.h>

bool substrAtPos(char *s, int pos, char *subStr) {
    int i = 0; 
    while (subStr[i] != '\0') {
        if (s[pos + i] == '\0') {
            return false;
        }
        if (s[pos + i] != subStr[i]) {
            return false; 
        }
        i++; 
    }
    return true;
}