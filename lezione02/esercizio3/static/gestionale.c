#include <stdio.h>
#include <string.h>
#include "gestionale.h"


void stampa_impiegati(Impiegato *impiegati, int num_impiegati) {
    for (int i = 0; i < num_impiegati; i++) {
        printf("%d) %s %s, %d anni, %c, %.2lf\n", i, impiegati[i].nome,
               impiegati[i].cognome, impiegati[i].eta, impiegati[i].sesso,
               impiegati[i].salario);
    }
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

int salva_impiegati(Impiegato *impiegati, int num_impiegati) {
    FILE *file = fopen("impiegati.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing\n");
        return -1;
    }

    for (int i = 0; i < num_impiegati; i++) {
        if (fprintf(file, "%s\t%s\t%d\t%c\t%.2lf", 
                    impiegati[i].nome, impiegati[i].cognome, 
                    impiegati[i].eta, impiegati[i].sesso,
                    impiegati[i].salario) < 0) {
            fprintf(stderr, "Could not write to file");
            return -1;
        }

        // Evita che venga inserita una riga nuova vuota alla fine del file
        if (i < num_impiegati-1)
            fprintf(file, "\n");
    }

    fclose(file);
}

int carica_impiegati(Impiegato *impiegati) {
    FILE *file = fopen("impiegati.txt", "r");

    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%s\t%s\t%d\t%c\t%lf", 
               impiegati[i].nome, impiegati[i].cognome, 
               &impiegati[i].eta, &impiegati[i].sesso,
               &impiegati[i].salario);
        i++;
    }
    fclose(file);
    return i;
}