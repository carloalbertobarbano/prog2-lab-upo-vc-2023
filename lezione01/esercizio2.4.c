#include <stdio.h>


/*
    Esercizio 2.4: Trovare la somma delle cifre di un numero
*/
int main() {
    int start = 1234;
    int n = start;

    int sum = 0;
    while(n > 0) {
        sum += n % 10; // ottieni cifra finale
        n /= 10; // rimuovi cifra finale
    }

    printf("La somma delle cifre di %d è %d\n", start, sum);
}