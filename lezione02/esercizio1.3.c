#include <stdio.h>
#include <stdlib.h>

/*
    Esercizio 1.3: Scrivere una funzione somma_vettore 
    che prende in input un vettore di numeri interi e 
    restituisce la somma dei suoi elementi. Definire 
    una struttura vettore con i campi lunghezza e 
    dati (un puntatore a un array di interi). Chiedi 
    all'utente di inserire la lunghezza e gli elementi 
    di un vettore, e usa la funzione somma_vettore per 
    calcolarne la somma.
*/
typedef struct {
    int length;
    int *data;
} Vettore;

int somma_vettore(Vettore vettore);

int main() {
    Vettore vettore;

    printf("Inserisci lunghezza vettore: ");
    scanf("%d", &vettore.length);
    
    vettore.data = (int*)malloc(sizeof(int)*vettore.length);
    for (int i = 0;i < vettore.length; i++) {
        printf("Inserisci elemento: ");
        scanf("%d", &vettore.data[i]);
    }

    int somma = somma_vettore(vettore);
    printf("Somma totale: %d\n", somma);

    free(vettore.data);
}

int somma_vettore(Vettore vettore) {
    int somma = 0;
    for (int i = 0; i < vettore.length; i++)
        somma += vettore.data[i];
    return somma;
}