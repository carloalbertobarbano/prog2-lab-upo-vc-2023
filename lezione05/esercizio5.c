#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


Nodo *list_from_array(int *arr, int n);
int check_palindrome(Nodo *head, Nodo *inv);

Nodo *check_palindrome_v2(Nodo *head, int p, int len, int *result) {
    Nodo *half_right;
    if (p+1 == len/2) {
        half_right = head->next;
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

int main() {
    Nodo *head = buildlist(10);
    list_print(head);

    int arr[] = {1, 2, 3, 4, 4, 3, 2, 1};
    Nodo *head_pal = list_from_array(arr, 8);
    list_print(head_pal);

    Nodo *inverted1 = list_invert(head);
    Nodo *inverted2 = list_invert(head_pal);

    printf("Lista 1 è palindroma: %d\n", check_palindrome(head, inverted1));
    printf("Lista 2 è palindroma: %d\n", check_palindrome(head_pal, inverted2));

    int res = 1;
    check_palindrome_v2(head, 0, 10, &res);
    printf("Lista 1 è palindroma: %d\n", res);

    res = 1;
    check_palindrome_v2(head_pal, 0, 8, &res);
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



Nodo *list_from_array(int *arr, int n) {
    Nodo *head = malloc(sizeof(Nodo));
    head->data = arr[0];
    head->next = NULL;

    for (int i = 1; i < n; i++)
        tailinsert(head, arr[i]);
    
    return head;
}