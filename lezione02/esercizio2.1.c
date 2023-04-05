#include <stdio.h>

typedef struct {
    char nome[64];
    char cognome[64];
    unsigned int eta;
    char sesso;
    double salario;
} Impiegato;


int main() {
    FILE *file = fopen("dati.tsv", "a");

    Impiegato imp; 
    printf("Inserisci nome: ");
    scanf("%s", imp.nome);
    printf("Inserisci cognome: ");
    scanf("%s", imp.cognome);
    printf("Inserisci età: ");
    scanf("%d", &imp.eta);
    printf("Inserisci sesso: ");
    scanf(" %c", &imp.sesso);
    printf("Inserisci salario: ");
    scanf("%lf", &imp.salario);

    fprintf(file, "%s\t%s\t%d\t%c\t%lf\n", imp.nome, imp.cognome,
            imp.eta, imp.sesso, imp.salario);

    fclose(file);
    return 0;
}