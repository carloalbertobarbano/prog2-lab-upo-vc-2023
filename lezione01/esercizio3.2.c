#include <stdio.h>


/* 
    Esercizio 3.2: Scrivere una Scrivere una funzione che 
    accetta un array di interi e la sua dimensione come 
    argomenti e restituisce il valore massimo dell'array.
*/
int find_max(int[], size_t);

int main() {
    int arr[] = {1, 2, 4, 5, 7, 6, 3};
    int max = find_max(arr, sizeof(arr) / sizeof(int));
    printf("The max value is %d\n", max);

    return 0;
}

int find_max(int arr[], size_t size) {
    int max = 0;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}