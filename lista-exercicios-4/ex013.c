#include <stdio.h>

int main() {

    int tamanho_rota, i, el1, el2, l, c;
    int soma = 0;
    int p_rota[100];
    int rotas[6][6] = {
        {0, 63, 210, 190, -1, 190},
        {63, 0, 160, 150, 95, 10},
        {210, 160, 0, 10, 1, 10},
        {190, 150, 10, 0, 10, 20},
        {10, 95, 7, 21, 0, 80},
        {190, 2, -1, 41, 80, 0}
    };

    scanf("%d", &tamanho_rota);
    for (i=0; i<tamanho_rota; i++) {
        scanf("%d", &p_rota[i]);
    }

    for (l=0; l<tamanho_rota-1; l++) {
        el1 = p_rota[l];
        el2 = p_rota[l+1];
        if (rotas[el1][el2] != -1) soma += rotas[el1][el2];
        else {
            printf("rota invalida!\n");
            return 0;
        }
    }
    
    printf("%d\n", soma);

    return 0;
}