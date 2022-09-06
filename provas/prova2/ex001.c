#include <stdio.h>

int sortear_pessoa(int qtd_numeros);

int main() {

    int n, sorteado, c=1;
    scanf("%d", &n);
    while (n!=0) {
        sorteado = sortear_pessoa(n);
        printf("Teste %d\n", c);
        if (sorteado == 0) printf("Sem vencedor\n");
        else printf("%d\n", sorteado); //\n
        scanf("%d", &n);
        c++;
    }

    return 0;
}

int sortear_pessoa(int qtd_numeros) {
    int i, sorteado = 0, num;
    for (i = 1; i <= qtd_numeros; i++) {
        scanf("%d", &num);
        if (num == i) {
            sorteado = i;
        }
    }
    return sorteado;
}   