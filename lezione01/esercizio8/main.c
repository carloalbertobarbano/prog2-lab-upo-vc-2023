#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*
    Esercizio 8.1: Riprendere l'esercizio 6.2 ed estendere 
    le funzioni per gestire vettori di qualsiasi tipo 
    (usando void*). Strutturare il programma su più files, 
    come una libreria. Questa libreria potrebbe esservi 
    utile lungo il corso 
*/
int main() {
    int *arr = (int*)create_array(sizeof(int), 10);
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    
    arr = expand_array(arr, sizeof(int), 50);
    for (int i = 10; i < 50; i++)
        arr[i] = i*2;

    for (int i = 0; i < 50; i++)
        printf("%d ", arr[i]);

    delete_array(arr);
    return 0;
}