#include <stdio.h>
#include <stdlib.h>


/*
    Esercizio 6.2: Scrivere delle funzioni per gestire 
    la creazione di array dinamici (di tipo char). 
    Le funzioni create_array, expand_array, e delete_array, 
    dovranno allocare, espandere e liberare la memoria dell'array. 
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


int main() {
    char *str = create_array(10);
    sprintf(str, "hello!");
    printf("%s\n", str);

    str = expand_array(str, 50);
    sprintf(str, "hello! this string is too long");
    printf("%s\n", str);

    delete_array(str);
    
    return 0;
}