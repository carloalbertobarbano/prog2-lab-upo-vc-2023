#include <stdio.h>

/* 
    Esercizio 1.1: Scrivere un programma che definisce una struttura 
    persona con i campi nome, cognome e età. Chiedere all'utente di 
    inserire i dati di due persone e stampa a video il nome della 
    persona più vecchia.
*/
struct persona {
    char nome[64];
    char cognome[64];
    int eta;
};

int main() {
    struct persona persona1, persona2;

    printf("1 - Inserisci nome: ");
    scanf("%s", persona1.nome);
    printf("1 - Inserisci cognome: ");
    scanf("%s", persona1.cognome);
    printf("1 - Inserisci età: ");
    scanf("%d", &persona1.eta);

    printf("\n2 - Inserisci nome: ");
    scanf("%s", persona2.nome);
    printf("2 - Inserisci cognome: ");
    scanf("%s", persona2.cognome);
    printf("2 - Inserisci età: ");
    scanf("%d", &persona2.eta);

    struct persona *piu_vecchio = &persona1;
    if (persona2.eta >= persona1.eta)
        piu_vecchio = &persona2;
    printf("\nPiù vecchio: %s %s %d\n", piu_vecchio->nome, piu_vecchio->cognome, piu_vecchio->eta);
    
    return 0;
}