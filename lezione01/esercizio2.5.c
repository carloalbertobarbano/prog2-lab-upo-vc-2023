#include <stdio.h>


/*
    Esercizio 2.5: Invertire le cifre di un numero
*/
int main() {
    int start = 1234;
    int n = start;

    int inverse = 0;
    while(n > 0) {
        int last_digit = n % 10; // ottieni cifra finale

        // aumenta ordine di grandezza del risultato precedente
        // e aggiungi cifra finale
        inverse = (inverse * 10) + last_digit;
        n /= 10;
    }

    printf("L'inverso delle cifre di %d è %d\n", start, inverse);
}