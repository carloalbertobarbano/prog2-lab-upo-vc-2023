#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


Nodo* buildlist(int n) {
    // Step 1: creazione testa
    Nodo *head = (Nodo*)malloc(sizeof(Nodo));
    head->data = rand() % 51;

    Nodo *tail = head;

    // Step 2: creazione nodi successivi
    for (int i = 0; i < n-1; i++) {
        Nodo *temp = malloc(sizeof(Nodo));
        temp->data = rand() % 51;

        tail->next = temp;
        tail = temp;
    }

    tail->next = NULL;

    return head;
}

void list_print(Nodo *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void tailinsert(Nodo *head, int x) {
    Nodo *new_node = (Nodo*)malloc(sizeof(Nodo));
    if (new_node == NULL) {
        fprintf(stderr, "Could not allocate memory\n!");
        return;
    }
    new_node->data = x;
    new_node->next = NULL;

    // Cicliamo fino alla fine della lista
    while (head->next != NULL)
        head = head->next;

    // head è ora l'ultimo nodo
    head->next = new_node;
}

int list_count(Nodo *head) {
    // Caso base 
    if (head == NULL) {
        return 0;
    }

    // Passo ricorsivo
    return 1 + list_count(head->next);
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

Nodo *list_from_array(int *arr, int n) {
    Nodo *head = malloc(sizeof(Nodo));
    head->data = arr[0];
    head->next = NULL;

    for (int i = 1; i < n; i++)
        tailinsert(head, arr[i]);
    
    return head;
}
   