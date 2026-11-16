#include <stdio.h>
#include <stdbool.h>

int findsubStr(char *s, char *subStr) {
    int pos = 0;
    if (subStr[0] == '\0') {
        return 0;
    }
    while (s[pos] != '\0') {
        if (substrAtPos(s, pos, subStr) == true) {
            return pos; 
        }
        pos++; 
    }
    return -1;
}