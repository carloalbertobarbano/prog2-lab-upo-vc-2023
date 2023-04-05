#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* 
    Esercizio 6.3: Aggiornare la funzione upperExtract (es. 5.2) 
    in modo da restituire il risultato in una nuova stringa 
    allocata all'interno della funzione (suggerimento: si può 
    usare sprintf). 
*/
char *create_array(int size) {
    char *buf = (char*)malloc(sizeof(char) * size);
    if (buf == NULL) {
        fprintf(stderr, "Could not allocate memory!\n");
        return NULL;
    }

    return buf; 
}  

char *expand_array(char *arr, int size) {
    arr = realloc(arr, size);
    if (arr == NULL) {
        fprintf(stderr, "Could not expand memory\n");
        return NULL;
    }

    return arr;
}

void delete_array(char *arr) {
    free(arr);
}

char *upperExtract(char *str) {
    char *result = NULL;
    char *token = strtok(str, " \n\0");

    while (token != NULL) {
        if (isupper(token[0])) {
            if (result == NULL) 
                result = create_array(strlen(token));
            else
                result = expand_array(result, strlen(result) + strlen(token) - 1);

            if (result == NULL) 
                return NULL;

            sprintf(result, "%s%s", result, token);
        }
        token = strtok(NULL, " !\n\0");
    };

    return result;
}

int main() {
    char str[] = "Hello World this is a nice Day!";
    char *res = upperExtract(str);
    printf("%s\n", res);

    return 0;
}