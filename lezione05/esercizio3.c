#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

Nodo *list_delete(Nodo *head, int val);

int main() {
    Nodo *head = buildlist(10);
    list_print(head);

    list_delete(head, 32);
    list_print(head);

    return 0;
}

Nodo *list_delete(Nodo *head, int val) {
    if (head == NULL)
        return NULL;
    
    if (head->data == val) {
        Nodo *new_node = head->next;
        free(head);
        return new_node;
    }

    head->next = list_delete(head->next, val);
    return head;
}