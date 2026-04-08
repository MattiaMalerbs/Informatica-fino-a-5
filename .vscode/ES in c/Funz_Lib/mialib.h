/*  Contiene solo i prototipi delle funzione che vado a sviluppare
    per la mia libreria personale */

/**
 * Check whether a number is prime or not.
 * @param int Number to test.
 * @return boolean true/false.
 */
bool isPrimo(int _n);
/**
 * Verifica se un numero è perfetto oppure no
 * @param int Numero da verificare
 * @return boolean true/false
 */
bool isPerfect(int _n);
/**
 * Verifica terna pitagorica, se n1^2+n2^2 = n3^2
 * @param int _n1 Primo valore
 * @param int _n2 Secondo valore
 * @param int _n3 Terzo valore
 * @return boolean true/false
 */
bool isTernaPitagorica(int _n1, int _n2, int _n3);


/**
 * Inserimento controllato di un valore intero tra min e max estremi compresi
 * @param int Valore minimo accettato
 * @param int Valore massimo accettato
 * @return Valore inserito dall'utente valido e nel range min-max
 */
int inputValoreRange(int _min, int _max);

/**
 * Genera un valore random compreso tra due valori interi min e max, estremi compresi
 * @param int Valore minimo accettato
 * @param int Valore massimo accettato
 * @return Valore random generato compreso nel range min-max
 */
int randomValoreRange(int _min, int _max);

/**
 * Genera un valore random compreso tra due valori interi min e max, estremi compresi
 * @param int Valore minimo accettato
 * @param int Valore massimo accettato
 * @return Valore random generato compreso nel range min-max
 */

int nextPrimo(int _val);

/**
 * Genera un valore random compreso tra due valori interi min e max, estremi compresi
 * @param int Valore minimo accettato
 * @param int Valore massimo accettato
 * @return Valore random generato compreso nel range min-max
 */

 int prevPrimo(int _val);

 /**
  * visualizza a video N numeri casuali primi successivi ad un valore di riferiment
  * @param int Valore di riferimento
  * @param int Numero di primi da visualizzare
  */
void vnp(int _val, int _n);

/**
 *  FUnz che raddoppia il val 
 * @param int* roferimento alla variabile originale
 * 
 */
void rd (int* _n);

/**
 * calcola aerea e perimetro
 * restituendo al main
 * @param int bas
 * @param int alt
 * @param int* metti area
 * @param int* metti perimetro
 */

 void CAP(int _base, int _altezza, int* _area, int* _perimetro);

 /**
  * visualizza a video N numeri casuali primi successivi ad un valore di riferiment
  * @param int Valore di riferimento
  * @param int Numero di primi da visualizzare
  */

bool SCA(int _a, int _b);
