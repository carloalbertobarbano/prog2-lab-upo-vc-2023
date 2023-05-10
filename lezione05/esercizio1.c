#include <stdio.h>
#include "lists.h"


int main() {
    Nodo *head = buildlist(10);
    list_print(head);
    printf("Number of nodes %d\n", list_count(head));
    
    return 0;
}