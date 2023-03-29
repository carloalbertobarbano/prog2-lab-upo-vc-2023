#include <stdio.h>


/*
    Esercizio 3.1: Scrivere una funzione che accetta 
    un array di interi e la sua dimensione come argomenti 
    e restituisce il valore medio dell'array.
*/

float average(int[], size_t);

int main() {
    int arr[] = {1, 2, 4, 5, 7, 6, 3};
    float avg = average(arr, sizeof(arr) / sizeof(int));
    printf("The avg value is %.2f\n", avg);

    return 0;
}

float average(int arr[], size_t size) {
    float sum = 0.0f;

    for (size_t i = 0; i < size; i++)
        sum += arr[i];
    
    float avg = sum / size;
    return avg;
}