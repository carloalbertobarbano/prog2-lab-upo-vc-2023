#include <stdio.h>
#include <string.h>

/* 
    Esercizio 7.3: Scrivere un programma che legga da un 
    file di testo una serie di parole e conti quante 
    volte compare una determinata parola all'interno del file.
*/
int main() {
    char *parola = "ciao";
    int matches = 0;

    FILE *file = fopen("parole.txt", "r");
    
    /* Opzione 1: fscanf/feof */
    while (!feof(file)) {
        // Leggo una stringa
        char buf[64];
        fscanf(file, "%s", buf);

        // Controllo match con "parola"
        if (strcmp(parola, buf) == 0) {
            // Aumento il numero di match
            matches++;
        }
    }

    printf("La parola %s compare %d volte\n", parola, matches);

    /* Opzione 2: fgets/strtok */
    fseek(file, 0, SEEK_SET); // resetto cursore all'inizio del file

    char line[256];
    fgets(line, 256, file); // leggo tutta la linea (fino a '\n')
    printf("Ho letto la stringa: %s\n", line);

    char *token = strtok(line, " \n\0");
    matches = 0;
    while (token != NULL) {
        if (strcmp(parola, token) == 0) {
            matches++;
        }
        token = strtok(NULL, " \n\0");
    }
    printf("La parola %s compare %d volte (strtok)\n", parola, matches);

    fclose(file);
    return 0;
}