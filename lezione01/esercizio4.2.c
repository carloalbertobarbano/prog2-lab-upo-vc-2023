#include <stdio.h>
#include <limits.h>


/*
    Esercizio 4.2: Scrivere una funzione che accetta 
    un array di interi e la sua dimensione come argomenti 
    e restituisce un array (attraverso argomento) che contiene 
    solo gli elementi pari dell'array originale. 
    Utilizzare puntatori per accedere agli elementi dell'array 
*/
void find_even(int[], size_t, int[], int*);

int main() {
    int arr[] = {1, 2, 4, 5, 7, 6, 4};
    int res[8];
    int num_even = 0;

    find_even(arr, sizeof(arr) / sizeof(int), res, &num_even);
    
    printf("The even numbers are: ");
    for (int i = 0; i < num_even; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}

void find_even(int arr[], size_t size, int res[], int *num_even) {
    int j = 0;

    for (size_t i = 0; i < size; i++) {
        if (*(arr+i) % 2 == 0)
            res[j++] = *(arr+i);
    }

    *num_even = j;
}