#include <stdio.h>
#include "gestionale.h"
#include "array.h"

int main() {
    Impiegato *impiegati = NULL;
    int num_impiegati = 0;

    int choice = 0;
    do {
        printf("\n---- Scegli un'operazione:\n");
        printf("0 - Visualizza tutti i record\n");
        printf("1 - Inserisci un nuovo impiegato\n");
        printf("2 - Ricerca\n");
        printf("3 - Modifica\n");
        printf("4 - Salva record su file\n");
        printf("5 - Leggi record da file\n");
        printf("9 - Esci\n");

        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: 
                printf("\n--- RECORD SALVATI (%d) ---\n", num_impiegati);
                stampa_impiegati(impiegati, num_impiegati-1);
                break;

            case 1: {
                Impiegato nuovoImpiegato = leggi_impiegato();
                if (impiegati == NULL)
                    impiegati = create_array(sizeof(Impiegato), 1);
                else
                    impiegati = expand_array(impiegati, sizeof(Impiegato), num_impiegati+1);
                impiegati[num_impiegati++] = nuovoImpiegato; 
                break;
            }

            case 2: {
                char cognome[64];
                printf("Inserisci cognome: ");
                scanf("%s", cognome);
                int i = cerca_impiegato(impiegati, num_impiegati, cognome);
                if (i == -1) {
                    printf("Impiegato non trovato\n");
                } else {
                    printf("%d) %s %s, %d anni, %c, %.2lf\n", i, impiegati[i].nome,
                            impiegati[i].cognome, impiegati[i].eta, impiegati[i].sesso,
                            impiegati[i].salario);
                }
                break;
            }
            
            case 3: {
                printf("Inserisci l'indice dell'impiegato da modificare: ");
                int id;
                scanf("%d", &id);
                modifica_impiegato(&impiegati[id]);
                break;
            }
            
            case 4: // Salva
                if (salva_impiegati(impiegati, num_impiegati) == 0) {
                    printf("Impiegati salvati correttamente!\n");
                } else {
                    fprintf(stderr, "Impossibile caricare i record\n");
                }
                break;
            
            case 5: // Carica
                num_impiegati = carica_impiegati(&impiegati);
                printf("Letti %d impiegati:\n", num_impiegati);
                stampa_impiegati(impiegati, num_impiegati-1);
                break;

            default:
                break;
        }

    } while (choice != 9);

    delete_array(impiegati);

    return 0;
}