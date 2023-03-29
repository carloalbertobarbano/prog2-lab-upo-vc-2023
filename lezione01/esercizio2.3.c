#include <stdio.h>
#include <stdbool.h>


/*
    Esercizio 2.3: Determinare se un numero è primo o no
*/
int main() {
    int n;
    scanf("%d", &n);
    
    int prime = true;
    int i = 2;
    while((i < n) && prime) {
        if (n % i == 0) {
            prime = false;
        } else {
            i++;
        }
    }

    if (prime == false) {
        printf("%d is not prime, divisible by %d\n", n, i);
    } else {
        printf("%d is prime\n");
    }
}