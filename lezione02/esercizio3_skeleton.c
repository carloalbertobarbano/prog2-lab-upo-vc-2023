#include <stdio.h>


typedef struct {
    char nome[64];
    char cognome[64];
    unsigned int eta;
    char sesso;
    double salario;
} Impiegato;

int main() {
    Impiegato impiegati[50];
    int num_impiegati = 0;

    int choice = 0;
    do {
        printf("\n---- Scegli un'operazione:\n");
        printf("0 - Visualizza tutti i record\n");
        printf("1 - Inserisci un nuovo impiegato\n");
        printf("9 - Esci\n");

        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: 
                // Stampa
                break;

            case 1: 
                // Leggi e inserisci nuovo impiegato 
                break;

            // ecc.
            
            default:
                break;
        }

    } while (choice != 9);

    return 0;
}
