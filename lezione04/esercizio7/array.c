#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void *create_array(size_t size, int n) {
    void *buf = malloc(size * n);
    if (buf == NULL) {
        fprintf(stderr, "Could not allocate memory!\n");
        return NULL;
    }

    return buf; 
}  

void *expand_array(void *arr, size_t size, int n) {
    arr = realloc(arr, size * n);
    if (arr == NULL) {
        fprintf(stderr, "Could not expand memory\n");
        return NULL;
    }

    return arr;
}

void delete_array(void *arr) {
    free(arr);
}