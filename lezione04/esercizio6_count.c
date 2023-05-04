/* 
    Esercizio 6: Scrivere una funzione ricorsiva che 
    calcoli il numero di occorrenze di un carattere in 
    una stringa.
*/
#include <stdio.h>

int count_char(const char *str, char ch);

int main() {
    const char *str = "this is a string";

    char ch = 'i';
    int res = count_char(str, ch);
    if (res) 
        printf("The string \"%s\" contains the char \'%c\' %d times\n", str, ch, res);
    else   
        printf("no\n");

    return 0;
}

int count_char(const char *str, char ch) {
    // Caso base
    if (*str == '\0')
        return 0;

    // Passo induttivo
    int count = 0;
    if (*str == ch)
        count = 1;
    return count + count_char(++str, ch);
}