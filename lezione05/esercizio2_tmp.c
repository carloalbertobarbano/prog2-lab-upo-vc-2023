#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


Nodo *list_invert(Nodo *head);
Nodo *list_invert_v2(Nodo *head, Nodo *next);


int main() {
    Nodo *head = buildlist(10);
    list_print(head);

    Nodo *head_inverted = list_invert_v2(head, NULL);
    list_print(head_inverted);

    return 0;
}

Nodo *list_invert(Nodo *head) {
    // Caso base: creo nuova lista per salvare nodi in ordine inverso
    if (head->next == NULL) {
        Nodo *inverted = (Nodo*)malloc(sizeof(Nodo));
        if (inverted == NULL) {
            fprintf(stderr, "Errore malloc\n");
            return NULL;
        }
        inverted->data = head->data;
        return inverted;
    }

    // Passo ricorsivo: inserisco gli elementi in coda (nella nuova lista)
    // in ordine iverso
    Nodo *inverted2 = list_invert(head->next);
    tailinsert(inverted2, head->data);
    return inverted2;
}

Nodo* list_invert_v2(Nodo *head, Nodo *next) {
    // Caso base
    if (head->next == NULL) {
        head->next = next;
        return head;
    }

    // A, A.next -> B; B.next -> C 
    // inv(A, NULL) 
    // inv(B, A)
    // inv(C, B)
    // C->next = B
    // B->next = A
    // A->next = NULL

    // Passo ricorsivo
    Nodo *res = list_invert_v2(head->next, head);
    head->next = next;
    return res;
}