#include <stdio.h>

/* 
    Esercizio 7.2: Scrivere un programma che legga da un 
    file di testo una serie di numeri interi, li inserisca 
    in un array e li scriva su un altro file in ordine 
    inverso (usando le primitive fscanf e fwrite).
*/
int main() {
    int numeri[10];
    int tot = 0; 

    FILE *file = fopen("numeri.txt", "r");
    while (!feof(file)) {
        int n;
        fscanf(file, "%d", &n);

        numeri[tot++] = n;
    }
    fclose(file);

    FILE *fileOut = fopen("numeri_inversi.txt", "w");
    FILE *fileOutB = fopen("numeri_inversi.bin", "wb");

    for (int i = tot-1; i >= 0; i--) {
        fprintf(fileOut, "%d ", numeri[i]);
        fwrite(&numeri[i], sizeof(int), 1, fileOutB);
    }
    fclose(fileOutB);
    fclose(fileOut);
    
    return 0;
}