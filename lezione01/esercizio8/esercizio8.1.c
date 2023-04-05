#include <stdio.h>
#include <stdlib.h>
#include "esercizio8.1.h"

/*
    Esercizio 8.1: Scrivere esercizio 6.2 su piu files
    (esempio con char*)
*/
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
