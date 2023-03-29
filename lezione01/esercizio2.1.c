#include <stdio.h>

/*
    Esercizio 2.1: Calcolare un fattoriale usando un ciclo
*/
int main() {
    int n = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    printf("%d! = %d\n", n, result);

    return 0;
}