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
    struct nodo *head1 = buildlist(n);
    struct nodo *head2 = buildlist(n);

    // Visualizzazione
    printf("L1: ");
    list_print(head1);

    printf("L2: ");
    list_print(head2);

    struct nodo *head_sum = malloc(sizeof(struct nodo));

    struct nodo *temp1 = head1;
    struct nodo *temp2 = head2;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            head_sum->data = temp1->data + temp2->data;
        } else {
            tailinsert(head_sum, temp1->data+temp2->data);
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    list_print(head_sum);


    temp1 = head1;
    while (temp1 != NULL) {
        struct nodo *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

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