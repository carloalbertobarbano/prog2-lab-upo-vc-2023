#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestionale.h"
#include "array.h"


void stampa_impiegati(Impiegato *impiegati, int num_impiegati) {
    // Caso base
    if (num_impiegati < 0)
        return;

    // Passo ricorsivo
    int i = num_impiegati;
    stampa_impiegati(impiegati, --num_impiegati);
    printf("%d) %s %s, %d anni, %c, %.2lf\n", i, 
           impiegati[i].nome, impiegati[i].cognome, 
           impiegati[i].eta, impiegati[i].sesso,
           impiegati[i].salario);
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
    // Caso base: già controllati tutti
    if (num_impiegati == 0)
        return -1;

    // Passo ricorsivo: controlla impiegato corrente o i rimanenti
    if (strcmp(impiegati[num_impiegati-1].cognome, cognome) == 0)
        return num_impiegati-1;
    return cerca_impiegato(impiegati, num_impiegati-1, cognome);
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

int carica_impiegati(Impiegato **impiegati) {
    FILE *file = fopen("impiegati.txt", "r");

    if (*impiegati != NULL) {
        delete_array(*impiegati);
        *impiegati = NULL;
    }

    int i = 0;
    while (!feof(file)) {
        if (*impiegati == NULL)
            *impiegati = create_array(sizeof(Impiegato), 1);
        else
            *impiegati = expand_array(*impiegati, sizeof(Impiegato), i+1);

        fscanf(file, "%s\t%s\t%d\t%c\t%lf", 
               (*impiegati)[i].nome, (*impiegati)[i].cognome, 
               &(*impiegati)[i].eta, &(*impiegati)[i].sesso,
               &(*impiegati)[i].salario);
        i++;
    }
    fclose(file);
    return i;
}