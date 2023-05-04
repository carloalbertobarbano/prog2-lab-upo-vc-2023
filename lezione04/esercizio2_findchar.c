/* Esercizio 2: Scrivere una funzione ricorsiva che restituisca 
   true (1) se una stringa contiene un determinato carattere, 
   altrimenti false (0).
*/
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int find_char(const char *str, char ch);

int main() {
    const char *str = "this is a string";
    char ch = 'b';
    int res = find_char(str, ch);
    if (res) 
        printf("The string \"%s\" contains the char \'%c\'\n", str, ch);
    else   
        printf("no\n");

    return 0;
}

int find_char(const char *str, char ch) {
    // Caso base
    if (*str == '\0')
        return FALSE;

    // Passo induttivo
    if (*str == ch)
        return TRUE;
    return find_char(++str, ch);
}