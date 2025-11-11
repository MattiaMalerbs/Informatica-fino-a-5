#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define BUF_SZ 128

static int leggi_intero(const char *prompt, int min, int max) {
    char buf[BUF_SZ];
    char *endptr;
    long val;
    while (1) {
        if (prompt) printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) return min; // EOF -> return min
        // rimuovi newline
        buf[strcspn(buf, "\n")] = '\0';
        if (buf[0] == '\0') {
            printf("Input vuoto, riprova.\n");
            continue;
        }
        val = strtol(buf, &endptr, 10);
        if (endptr == buf || *endptr != '\0') {
            printf("Inserisci un numero valido.\n");
            continue;
        }
        if (val < min || val > max) {
            printf("Numero fuori intervallo (%d - %d). Riprova.\n", min, max);
            continue;
        }
        return (int)val;
    }
}

int main(void) {
    srand((unsigned) time(NULL));
    printf("=== Indovina il numero ===\n");
    printf("Regole: scegli un intervallo in base alla difficolta'.\n");
    printf("Riceverai suggerimenti 'Troppo alto' o 'Troppo basso'.\n\n");

    while (1) {
        printf("Scegli la difficolta':\n");
        printf("  1) Facile   (1-10, tentativi illimitati)\n");
        printf("  2) Normale  (1-100, max 10 tentativi)\n");
        printf("  3) Difficile(1-1000, max 15 tentativi)\n");
        printf("  4) Esci\n");

        int scelta = leggi_intero("Seleziona 1-4: ", 1, 4);
        if (scelta == 4) {
            printf("Grazie per aver giocato. Arrivederci!\n");
            break;
        }

        int min = 1, max = 10, max_tentativi = INT_MAX;
        if (scelta == 1) { max = 10; max_tentativi = INT_MAX; }
        else if (scelta == 2) { max = 100; max_tentativi = 10; }
        else if (scelta == 3) { max = 1000; max_tentativi = 15; }

        int segreto = (rand() % (max - min + 1)) + min;
        int tentativi = 0;
        int trovato = 0;

        printf("Ho scelto un numero tra %d e %d. In bocca al lupo!\n", min, max);

        while (tentativi < max_tentativi) {
            char prompt[64];
            snprintf(prompt, sizeof(prompt), "Tentativo %d - Inserisci numero: ", tentativi + 1);
            int guess = leggi_intero(prompt, min, max);
            tentativi++;

            if (guess == segreto) {
                printf("Bravo! Hai indovinato in %d tentativo%s.\n", tentativi, tentativi == 1 ? "" : "i");
                trovato = 1;
                break;
            } else if (guess < segreto) {
                printf("Troppo basso.\n");
            } else {
                printf("Troppo alto.\n");
            }

            if (max_tentativi != INT_MAX)
                printf("Rimangono %d tentativi.\n", max_tentativi - tentativi);
        }

        if (!trovato) {
            printf("Hai esaurito i tentativi. Il numero era: %d\n", segreto);
        }

        // Chiedi se vuole giocare ancora
        char buf[BUF_SZ];
        printf("Vuoi giocare ancora? (s/n): ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        if (buf[0] != 's' && buf[0] != 'S') {
            printf("Grazie per aver giocato. Ciao!\n");
            break;
        }
        printf("\n");
    }

    return 0;
}