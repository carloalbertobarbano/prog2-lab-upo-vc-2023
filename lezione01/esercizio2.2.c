#include <stdio.h>

/* 
    Esercizio 2.2: Stampare la sequenza di Fibonacci 
*/
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int prev = 0, curr = 1;
    int next;

    do {
        next = prev + curr;
        prev = curr;
        printf("%d ", curr);
        curr = next;
    } while (next < n);

    return 0;
}