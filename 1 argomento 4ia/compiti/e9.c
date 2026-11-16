// uso ai perche non avevo capito come eliminare i caratteri o se dovevo spostare gli '\0' tutti a destra dopo che li assegnavo a del
#include <stdio.h>

void removeChar(char s[], char del) {
    int leggo = 0;
    int scrivo = 0;

    // Scorriamo tutta la stringa originale con l'indice 'leggo'
    while (s[leggo] != '\0') {
        // Se il carattere NON è quello da eliminare, lo teniamo!
        if (s[leggo] != del) {
            s[scrivo] = s[leggo]; // Lo copiamo nella posizione 'scrivo'
            scrivo++;             // Avanziamo dove scriveremo la prossima lettera buona
        }
        // In ogni caso, passiamo a leggere la lettera successiva
        leggo++;
    }

    // Fondamentale: chiudiamo la nuova stringa più corta con '\0'
    s[scrivo] = '\0';
}