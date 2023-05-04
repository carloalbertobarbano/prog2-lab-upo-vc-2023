#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo {
    int data;
    struct nodo *next;
};

struct nodo* buildlist(int n);
void list_print(struct nodo *head);
float list_mean(struct nodo *head);


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <number of nodes>\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]); // char to int (string.h)
    struct nodo *head = buildlist(n);

    // Visualizzazione
    list_print(head);

    // Valor medio
    printf("The average value is: %.2f\n", list_mean(head));

    // Scrittura su file
    FILE *fileOut = fopen("lista.txt", "w");
    struct nodo *temp = head;
    while (temp != NULL) {
        fprintf(fileOut, "%d\n", temp->data);
        temp = temp->next;
    }
    fclose(fileOut);

    
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

float list_mean(struct nodo *head) {
    float sum = 0.0f;
    int i = 0;

    while( head != NULL ) {
        sum += head->data;
        i++;
        head = head->next;
    }

    return sum / i;
    /*
    for(; head != NULL; head = head->next) {
        // Do something
    }*/
}