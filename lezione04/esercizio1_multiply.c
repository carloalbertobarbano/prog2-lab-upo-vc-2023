/* Esercizio 1: Scrivere una funzione ricorsiva che calcoli 
   il prodotto di due numeri interi senza utilizzare l'operatore 
   di moltiplicazione.
*/
#include <stdio.h>

int multiply(int a, int b);

int main() {
    int a = 5, b=3;
    printf("%d * %d = %d\n", a, b, multiply(a, b));
    return 0;
}

// 5 * 3 = 5 + 5 +5
// multiply(5, 1) = 5
// multiply(5, 2) = 5 + multiply(5, 1)
// multiply(5, 3) = 5 + multiply(5, 2)

// multiply(a, 1) = a // CASO BASE
// multiply(a, b) = a + multiply(a, b-1) // PASSO RICORSIVO

int multiply(int a, int b) {
    // Caso base
    if (b <= 1)
        return a;

    // Passo ricorsivo
    return a + multiply(a, b - 1);
}