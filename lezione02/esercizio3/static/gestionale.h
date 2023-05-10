#ifndef _GESTIONALE_H
#define _GESTIONALE_H

struct impiegato {
    char nome[64];
    char cognome[64];
    unsigned int eta;
    char sesso;
    double salario;
};
typedef struct impiegato Impiegato;


void stampa_impiegati(Impiegato *impiegati, int num_impiegati);
Impiegato leggi_impiegato();
int cerca_impiegato(Impiegato *impiegati, int num_impiegati, char *cognome);
void modifica_impiegato(Impiegato *impiegato);

int salva_impiegati(Impiegato *impiegati, int num_impiegati);
int carica_impiegati(Impiegato *impiegati);

#endif