// SOURCE FILE

#include <stdio.h>
#include <stdlib.h>
#include "esercizio8.1.h"


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