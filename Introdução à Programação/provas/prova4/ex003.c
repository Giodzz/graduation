#include <stdio.h>
#include <stdlib.h>

typedef struct _cartela {
    int numJogo;
    int numero[6];
} Cartela;



int main() {

    int qtd_apostas, numConcurso, i, k, j, c, cont = 0;
    Cartela * cartelas = NULL;
    int sorteados[6];
    int * acertos = NULL;

    scanf("%d", &qtd_apostas);
    cartelas = (Cartela *) malloc(qtd_apostas*sizeof(Cartela));

    // entrada de informações
    for (i=0; i<qtd_apostas; i++) {
        scanf("%d", &cartelas[i].numJogo);
        for (k=0; k<6; k++) {
            scanf("%d", &cartelas[i].numero[k]);
        }
    }

    // lendo os numeros sorteados
    scanf("%d", &numConcurso);
    for (i=0; i<6; i++) {
        scanf("%d", &sorteados[i]);
    }

    // descobrir se fez quadra, quina ou sena
    for (i=0; i<qtd_apostas; i++) {
        // cartela[i]
        c=0;
        for (k=0; k<6; k++) {
            for (j=0; j<6; j++) {
                if (cartelas[i].numero[k] == sorteados[j]) {
                    acertos = (int *) realloc(acertos, (c+1)*sizeof(int));
                    acertos[c] = cartelas[i].numero[k];
                    c++;
                }
            }
        }

        switch (c) {
            case 4:
                printf("QUADRA %d: ", cartelas[i].numJogo);
                for (k=0; k<4; k++) {
                    printf("%d", acertos[k]);
                    if (k<3) printf(" ");
                }
                printf("\n");
                cont++;
                break;
            
            case 5:
                printf("QUINA %d: ", cartelas[i].numJogo);
                for (k=0; k<5; k++) {
                    printf("%d", acertos[k]);
                    if (k<4) printf(" ");
                }
                printf("\n");
                cont++;
                break;

            case 6:
                printf("SENA %d: ", cartelas[i].numJogo);
                for (k=0; k<6; k++) {
                    printf("%d", acertos[k]);
                    if (k<5) printf(" ");
                }
                cont++;
                printf("\n");
                break;
        }
    }

    if (cont == 0) printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", numConcurso);

    free(cartelas);
    return 0;
}