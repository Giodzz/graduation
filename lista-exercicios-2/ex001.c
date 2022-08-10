#include <stdio.h>
/**
 * @brief Funcao que alcula o fatorial de um numero n
 * @param n: um numero inteiro positivo 
 * @return unsigned long int o fatorial de n
 */
unsigned long int fat(unsigned int n);

int main() {

    int n, fatorial;
    scanf("%d", &n);
    fatorial = fat(n);
    printf("%d! = %d\n", n, fatorial);

    return 0;
}

unsigned long int fat(unsigned int n) {
    int i;
    unsigned long int fat = 1;
    for (i = 1; i<= n; i++){
        fat *= i;
    }
    return fat;

}
