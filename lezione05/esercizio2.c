#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lists.h"


Nodo *invert_v2(Nodo *head, Nodo *next);

int main(int argc, char **argv) {
    srand(time(NULL));

    Nodo *head = buildlist(10);
    list_print(head);
    
    head = invert_v2(head, NULL);
    list_print(head);

    return 0;
}

Nodo *invert_v1(Nodo *head) {

}

Nodo* invert_v2(Nodo *head, Nodo *next) {
    Nodo *ptrNext = head->next;
    head->next = next;

    if (ptrNext == NULL)
        return head;
    
    return invert_v2(ptrNext, head);
}
   