#include <stdio.h>
#include <stdlib.h>

/*
    Esercizio 6.1: Scrivere un programma per allocare un 
    array di interi, con dimensione e valori specificati 
    dall'utente, e calcolarne la somma.
*/
int main() {
    int n;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);

    int *array = (int*)malloc(sizeof(int)*n);
    for (int i = 0;i < n; i++) {
        printf("Inserisci un valore: ");
        scanf("%d", &array[i]);
    }

    // Calcola somma
    int sum = 0;
    for (int i = 0;i < n; i++)
        sum += array[i];
    
    printf("La somma è: %d\n", sum);
    free(array);

    return 0;
}