/* Esercizio 3: Scrivere una funzione 
   ricorsiva che stampi tutti i divisori 
   di un numero
*/
#include <stdio.h>


void print_div(int n, int div);

int main() {
    int n = 178246;
    print_div(n, n);
    return 0;
}

void print_div(int n, int div) {
    if (n % div == 0) {
        printf("%d %% %d == 0\n", n, div);
    }

    // Caso base
    if (div == 1) {
        return;   
    }

    // Passo ricorsivo
    print_div(n, div-1);
}