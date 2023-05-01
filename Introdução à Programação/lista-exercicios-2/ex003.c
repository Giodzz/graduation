#include <stdio.h>
/**
 * @brief Função que separa os digitos de um número de 3 dígitos
 * 
 * @param n: número de 3 dígitos
 * @param c: primeiro dígito do número n
 * @param d: segundo dígito do número n
 * @param u: terceiro dígito do número n
 * @return int os dítidos separados
 */
void separaDigitos(int n, int *c, int *d, int *u);

int main() {

    int n, c, d, u, digitos;
    scanf("%d", &n);
    separaDigitos(n, &c, &d, &u);
    printf("%d%d%d\n", u, d, c);


    return 0;
}

void separaDigitos(int n, int *pc, int *pd, int *pu) {
    *pc = n/100;
    *pd = (n%100) / 10;
    *pu = (n%10);
}
