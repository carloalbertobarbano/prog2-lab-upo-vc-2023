#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


int check_palindrome(Nodo *head, Nodo *inv);
Nodo *check_palindrome_v2(Nodo *head, int p, int len, int *result);

int main() {
    Nodo *head = buildlist(10);
    list_print(head);

    int arr[] = {1, 2, 3, 4, 10, 4, 3, 2, 1};
    Nodo *head_pal = list_from_array(arr, 9);
    list_print(head_pal);

    // Soluzione con inversione della lista
    Nodo *inverted1 = list_invert(head);
    Nodo *inverted2 = list_invert(head_pal);

    printf("Lista 1 è palindroma: %d\n", check_palindrome(head, inverted1));
    printf("Lista 2 è palindroma: %d\n", check_palindrome(head_pal, inverted2));

    // Soluzione senza inversione della lista
    int res = 1;
    check_palindrome_v2(head, 0, 10, &res);
    printf("Lista 1 è palindroma: %d\n", res);

    res = 1;
    check_palindrome_v2(head_pal, 0, 9, &res);
    printf("Lista 2 è palindroma: %d\n", res);
    
    return 0;
}

int check_palindrome(Nodo *head, Nodo *inv) {
    // Caso base
    if (head == NULL && inv == NULL) return 1;

    // Passo ricorsivo
    return (head->data == inv->data) && check_palindrome(head->next, inv->next);

    /*
    if (head->data != inv->data)
        return 0;
    return check_palindrome(head->next, inv->next);
    */
}


/* 
    Visito la lista fino a metà; ottengo un puntatore alla 
    sotto lista destra (da metà in poi), e confronto a coppie
    i valori tra prima metà (in ordine inverso) e seconda metà 
*/
Nodo *check_palindrome_v2(Nodo *head, int p, int len, int *result) {
    Nodo *half_right;

    if ((len % 2 == 0) && (p+1 == len/2)) { // se la lista ha lunghezza pari
        half_right = head->next;
    } else if ((len % 2 != 0) && (p+1 == (len-1)/2)) { // se la lista ha lunghezza dispari
        half_right = head->next->next;
    } else {
        half_right = check_palindrome_v2(head->next, p+1, len, result);
    }
    
    // 1 2 3 | 3 2 1
    // 3-3
    // 2-2
    // 1-1
    *result = *result && (head->data == half_right->data);
    return half_right->next;
}



