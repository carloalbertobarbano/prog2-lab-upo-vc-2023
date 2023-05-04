/* 
    Esercizio 4: Scrivere una funzione ricorsiva che trovi 
    il numero più grande in un array di interi.
*/
#include <stdio.h>

int max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}

int max_rec2(int arr[], int p, int len, int max) {
    if (p == len)
        return max;
    
    if (arr[p] > max)
        max = arr[p];
    
    return max_rec2(arr, p+1, len, max);
}

int max_rec(int arr[], int p, int len) {
    if (p == len) {
        return 0;
    }

    return max(arr[p], max_rec(arr, p+1, len));
}

int main() {
    int arr[] = {1, 2, 5, 10, 3, 24, 101, 505};
    int v_max = max_rec2(arr, 0, sizeof(arr)/sizeof(int), 0); //max_rec(arr, 0, sizeof(arr)/sizeof(int));
    printf("Max value: %d\n", v_max);
    return 0;
}