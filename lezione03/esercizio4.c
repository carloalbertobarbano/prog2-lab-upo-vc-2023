#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct nodo {
    int data;
    struct nodo *next;
};

struct nodo* buildlist(int n);
void list_print(struct nodo *head);
void tailinsert(struct nodo *head, int x);

int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc < 2) {
        printf("Usage: %s <number of nodes>\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]); // char to int (string.h)
    struct nodo *head = buildlist(n);

    // Visualizzazione
    list_print(head);

    // Assegnazione pari-dispari
    struct nodo *head_pari = malloc(sizeof(struct nodo));
    struct nodo *head_dispari = malloc(sizeof(struct nodo));

    struct nodo *temp = head;
    int i = 0, j = 0;
    while(temp != NULL) {
        if (temp->data % 2 == 0) {
            if (i == 0)
                head_pari->data = temp->data;
            else
                tailinsert(head_pari, temp->data);
            
            i++;
        } else {
            if (j == 0)
                head_dispari->data = temp->data;
            else
                tailinsert(head_dispari, temp->data);
            j++;
        }
        
        temp = temp->next;
    }

    printf("L1 (pari): ");
    list_print(head_pari);

    printf("L2 (dispari): ");
    list_print(head_dispari);
    
    return 0;
}

struct nodo* buildlist(int n) {
    // Step 1: creazione testa
    struct nodo *head = (struct nodo*)malloc(sizeof(struct nodo));
    head->data = rand() % 51;

    struct nodo *tail = head;

    // Step 2: creazione nodi successivi
    for (int i = 0; i < n-1; i++) {
        struct nodo *temp = malloc(sizeof(struct nodo));
        temp->data = rand() % 51;

        tail->next = temp;
        tail = temp;
    }

    tail->next = NULL;

    return head;
}

void list_print(struct nodo *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void tailinsert(struct nodo *head, int x) {
    struct nodo *new_node = (struct nodo*)malloc(sizeof(struct nodo));
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