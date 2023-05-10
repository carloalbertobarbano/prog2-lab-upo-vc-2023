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

/* 
    Inversione della lista con creazione di lista secondaria
*/
Nodo *list_invert(Nodo *head) {
    /* Caso base: ho raggiunto la coda della lista. 
       La coda diventa la nuova head; creo una nuova lista (inverted) 
       per salvare nodi in ordine inverso
    */
    
    if (head->next == NULL) {
        Nodo *inverted = (Nodo*)malloc(sizeof(Nodo));
        if (inverted == NULL) {
            fprintf(stderr, "Errore malloc\n");
            return NULL;
        }
        inverted->data = head->data;
        return inverted;
    }

    /* Passo ricorsivo: inserisco gli elementi in coda (nella nuova lista)
       in ordine iverso */
    Nodo *inverted2 = list_invert(head->next);
    tailinsert(inverted2, head->data);
    return inverted2;
}

/* Versione tail-recursion: inversione della lista in-place. 
   L'argomento "next" indica quale nodo dovrà diventare il next di "head" */
Nodo* list_invert_v2(Nodo *head, Nodo *next) {
    Nodo *ptrNext = head->next;
    head->next = next;

    /* La coda (che aveva head->next == NULL) diventa 
       la nuova head (caso base)*/
    if (ptrNext == NULL)
        return head;
    
    /* Passo ricorsivo: inverto il link tra nodo corrente (head) 
       e nodo successivo (head->next originale) */
    return list_invert_v2(ptrNext, head);
}
