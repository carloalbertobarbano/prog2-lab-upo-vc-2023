#include <stdio.h>


int main() {
    int a = 0, b = 0;

    printf("Input two integers: ");
    scanf("%d %d", &a, &b);

    int diff = a - b;
    if (diff < 0)
        diff = -diff;

    if (diff % 2 == 0) {
        printf("The difference is even (%d)\n", diff);
    } else {
        printf("The difference is odd (%d)\n", diff);
    }
    
    return 0;
}