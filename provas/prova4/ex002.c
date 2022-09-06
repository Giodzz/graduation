#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int likes, rtt, menc;
} User;

int main() {

    int dim, qtd_pares, i, u1, u2, vazio, l, c, likes, rtt, menc;
    int tot_likes = 0, tot_rtt = 0, tot_menc = 0, u = 0;
    User ** matriz = NULL; // matriz de users

    scanf("%d%d", &dim, &qtd_pares);
    matriz = (User **) malloc(dim*sizeof(User *));
    if (matriz == NULL) exit(1);
    for (i=0; i<dim; i++) {
        matriz[i] = (User *) malloc(dim*sizeof(User));
    }

    for (i=0; i<qtd_pares; i++) {
        scanf("%d %d", &u1, &u2);
        scanf("%d %d %d", &matriz[u1][u2].likes, &matriz[u1][u2].rtt, &matriz[u1][u2].menc);
    }
    vazio = dim*dim - qtd_pares;

    for (l=0; l<dim; l++) {
        likes = rtt = menc = 0;
        for (c=0; c<dim; c++) {
            if (matriz[l][c].likes == 0) continue;
            likes += matriz[l][c].likes;
            rtt += matriz[l][c].rtt;
            menc += matriz[l][c].menc;
        }

        if (likes != 0) {
            printf("Usuario %d - ", l);
            printf("num. likes: %d, ", likes);
            printf("num. retweets: %d e ", rtt);
            printf("num. mencoes: %d\n", menc);
            tot_likes += likes;
            tot_rtt += rtt;
            tot_menc += menc;
            u++;
        }
    }
    printf("Slots vazios: %d\n", vazio);
    printf("Media de likes por usuario: %.2lf\n", tot_likes/(double)u);
    printf("Media de retweets por usuario: %.2lf\n", tot_rtt/(double)u);
    printf("Media de mencoes por usuario: %.2lf\n", tot_menc/(double)u);

    for (i=0; i<dim; i++) free(matriz[i]);
    free(matriz);

    return 0;
}