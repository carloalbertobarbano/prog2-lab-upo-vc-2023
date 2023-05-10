#ifndef _LISTS_H
#define _LISTS_H

typedef struct nodo {
    int data;
    struct nodo *next;
} Nodo;

Nodo* buildlist(int n);
void list_print(Nodo *head);
void tailinsert(Nodo *head, int x);
int list_count(Nodo *head);
Nodo *list_invert(Nodo *head);
Nodo *list_from_array(int *arr, int n);

#endif