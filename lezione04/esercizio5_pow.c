/* 
    Esercizio 5: Scrivere una funzione ricorsiva 
    che calcoli la potenza di un numero.
*/
#include <stdio.h>

// a^b = a * a^(b-1)
// a^0 = 1
int power_rec(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power_rec(base, exp-1);
}

int main() {
    int base = 2, exp = 8;
    int res = power_rec(base, exp);
    printf("%d^%d = %d\n", base, exp, res);
}