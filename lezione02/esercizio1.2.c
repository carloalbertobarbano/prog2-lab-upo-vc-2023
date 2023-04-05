#include <stdio.h>

/* 
    Esercizio 1.2: Definire una struttura studente 
    con i campi nome, cognome, voto_esame1, voto_esame2 e media. 
    Chiedere all'utente di inserire i dati di 3 studenti 
    e calcolare la media dei voti di ogni studente e stamparla 
    a video insieme al nome.
*/
typedef struct {
    char nome[64];
    char cognome[64];
    float voto_esame1;
    float voto_esame2;
    float media;
} Studente;


int main() {
    Studente studenti[3];

    for (int i = 0;i < 3; i++) {
        printf("---\nInserisci nome: ");
        scanf("%s", studenti[i].nome);
        printf("Inserisci cognome: ");
        scanf("%s", studenti[i].cognome);

        printf("Voto esame 1: ");
        scanf("%f", &studenti[i].voto_esame1);
        printf("Voto esame 2: ");
        scanf("%f", &studenti[i].voto_esame2);

        studenti[i].media = 0.5 * (studenti[i].voto_esame1 + studenti[i].voto_esame2);
    }

    printf("\n --- MEDIE ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Studente: %s %s, media: %.2f\n", studenti[i].nome, studenti[i].cognome, 
               studenti[i].media);
    }

    return 0;
}