#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[64];
    char cognome[64];
    unsigned int eta;
    char sesso;
    double salario;
} Impiegato;


Impiegato leggi_impiegato();
int cerca_impiegato(Impiegato *impiegati, int num_impiegati, char *cognome);
void modifica_impiegato(Impiegato *impiegato);

void salva_impiegati(Impiegato *impegati);
int carica_impiegati(Impiegato *impiegati);

int main() {
    Impiegato impiegati[50];
    int num_impiegati = 0;

    int choice = 0;
    do {
        printf("\n---- Scegli un'operazione:\n");
        printf("0 - Visualizza tutti i record\n");
        printf("1 - Inserisci un nuovo impiegato\n");
        printf("2 - Ricerca\n");
        printf("3 - Modifica\n");
        printf("9 - Esci\n");

        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: 
                printf("\n--- RECORD SALVATI (%d) ---\n", num_impiegati);
                for (int i = 0; i < num_impiegati; i++) {
                    printf("%d) %s %s, %d anni, %c, %.2lf\n", i, impiegati[i].nome,
                           impiegati[i].cognome, impiegati[i].eta, impiegati[i].sesso,
                           impiegati[i].salario);
                }
                break;

            case 1: {
                Impiegato nuovoImpiegato = leggi_impiegato();  
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
            
            default:
                break;
        }

    } while (choice != 9);

    return 0;
}


Impiegato leggi_impiegato() {
    Impiegato imp;
    printf("Inserisci il nome: ");
    scanf("%s", imp.nome);

    printf("Inserisci il cognome: ");
    scanf("%s", imp.cognome);

    printf("Inserisci l'età: ");
    scanf("%d", &imp.eta);

    printf("Inserisci il sesso: ");
    scanf(" %c", &imp.sesso);

    printf("Inserisci il salario: ");
    scanf("%lf", &imp.salario);

    return imp;
}

int cerca_impiegato(Impiegato *impiegati, int num_impiegati, char *cognome) {
    for (int i = 0; i < num_impiegati; i++) {
        if (strcmp(impiegati[i].cognome, cognome) == 0) {
            return i;
        }
    }
    return -1;
}

void modifica_impiegato(Impiegato *impiegato) {
    Impiegato imp = leggi_impiegato();
    *impiegato = imp;
}