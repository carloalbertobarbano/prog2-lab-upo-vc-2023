#include <stdio.h>

/* 
    Esercizio 7.1: Scrivere un programma che legga da un 
    file di testo una serie di numeri interi, li sommi 
    e stampi il risultato.
*/
int main() {
    int somma = 0;

    FILE *file = fopen("numeri.txt", "r");
    while (!feof(file)) {
        int n;
        fscanf(file, "%d", &n);
        somma += n;
    }
    fclose(file);
    
    printf("La somma totale è: %d\n", somma);
    return 0;
}