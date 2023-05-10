#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

Nodo *list_delete(Nodo *head);

int main() {
    Nodo *head = buildlist(10);
    list_print(head);

    list_delete(head);
    list_print(head);

    return 0;
}

Nodo *list_delete(Nodo *head) {
    if (head == NULL)
        return NULL;
    
    head->next = list_delete(head->next);

    if (head->data % 2 != 0) {
        Nodo *new_node = head->next;
        free(head);
        return new_node;
    }
    return head;
}