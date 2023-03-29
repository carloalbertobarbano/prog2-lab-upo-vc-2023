#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*
    Esercizio 5.2: Scrivere una funzione upperExtract 
    che accetta una stringa come argomento e restituisce 
    una nuova stringa (attraverso parametro) che contiene 
    solo le parole che iniziano con una lettera maiuscola 
    della stringa originale. Utilizzare le funzioni strtok() 
    e isupper() di string.h e ctype.h
*/
void upperExtract(char *str, char *out) {
    /* 
        Con strtok(str, tok) divido la stringa
        in sottostringhe delimitate da qualsiasi 
        carattere che compare in tok. 
        strtok ritorna NULL quando la stringa in input
        è terminata.
    */
    char *token = strtok(str, " \n\0");

    while (token != NULL) {
        if (isupper(token[0])) {
            strcpy(out, token);
            out += strlen(token);
        }

        /* 
            Con NULL indico a strtok di continuare
            a splittare la stringa precedente.
         */
        token = strtok(NULL, " !\n\0");
    };
}

int main() {
    char str[] = "Hello World this is a nice Day!";
    char buf[31];
    
    upperExtract(str, buf);
    printf("%s\n", buf);

    return 0;
}