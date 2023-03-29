#include <stdio.h>
#include <limits.h>


/*
    Esercizio 4.1: Scrivere una funzione che accetta 
    un array di interi e la sua dimensione come argomenti 
    e restituisce il valore massimo e il valore minimo 
    dell'array attraverso due puntatori passati come argomenti.
*/
void find_minmax(int[], size_t, int*, int*);

int main() {
    int arr[] = {1, 2, 4, 5, 7, 6, 3};
    int min, max;
    find_minmax(arr, sizeof(arr) / sizeof(int), &min, &max);
    printf("The min value is %d, the max value is %d\n", min, max);

    return 0;
}

void find_minmax(int arr[], size_t size, int *min, int *max) {
    *max = 0;
    *min = INT_MAX;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] > *max)
            *max = arr[i];

        if (arr[i] < *min)
            *min = arr[i];
    }
}