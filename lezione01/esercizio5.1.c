#include <stdio.h>
#include <string.h>


/*
    Esercizio 5.1: Scrivere una funzione oddExtract 
    che accetta una stringa come argomento e restituisce 
    una nuova stringa (attraverso parametro) che contiene 
    solo i caratteri in posizione dispari della stringa originale.
*/
void oddExtract(char *s1, char *s2) {
    int j = 0;
    for (size_t i = 1; i < strlen(s1); i += 2) {
        s2[j] = s1[i];
        j++;
    }
    s2[j] = '\0';
}

// Versione con sintassi puntatori
void oddExtractPtr(char *s1, char *s2) {
    for (size_t i = 1; i < strlen(s1); i += 2) {
        *(s2++) = s1[i];
    }
    *s2 = '\0';
}

int main() {
    char str1[] = "Hello, World!";
    char str2[30];

    oddExtractPtr(str1, str2);
    printf("Odd string: %s\n", str2);

    return 0;
}