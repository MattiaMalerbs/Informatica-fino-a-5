#include <stdio.h>
#include <stdbool.h>

bool repeatedChars(char s[]) {
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i + 1; s[j] != '\0'; j++) {
            if (s[i] == s[j]) {
                return true;
            }
        }
    }
    return false;
}