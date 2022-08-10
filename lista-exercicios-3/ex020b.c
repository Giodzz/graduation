#include <stdio.h>
#include <string.h>
void apague_ganhe(char * vetor_num, int qtd_num, char * maior_num);

int main() {

    int n, d;
    char num[10], maior[10];
    scanf("%d %d", &n, &d);

    while (n || d) {
        memset(num, 0, 10*sizeof(char));
        memset(maior, 0, 10*sizeof(char));
        scanf("%s", num);
        apague_ganhe(num, d, maior);
        printf("%s\n", maior);
        scanf("%d %d", &n, &d);
    }

    return 0;
}

void apague_ganhe(char * vetor_num, int qtd_num, char * maior_num) {
    int i, k, pm; 
    int c=0;
    int tamanho_v = strlen(vetor_num);
    char pos, pos_ant, maior_ant, maior='0', t1, t2;
    char maiores[10], pos_maiores[10];

    memset(maiores, 0, 10*sizeof(char));
    memset(pos_maiores, 0, 10*sizeof(char));

    while (c<qtd_num) {
        maior = '0';
        for (i=0; i<tamanho_v; i++) {
            if (c==0) {
                if (vetor_num[i] > maior) {
                    maior = vetor_num[i];
                    pos = (char) i;
                }
            } else {
                if (vetor_num[i] > maior && vetor_num[i] <= maior_ant && i!=pos_ant) {
                    maior = vetor_num[i];
                    pos = (char) i;
                }
            }
        }

        maiores[c] = maior;
        pos_maiores[c] = pos;
        maior_ant = maior;
        pos_ant = pos;
        c++;
    }

    // ordenar pos_maiores e mudar o vetor maiores junto
    for (i=0; i<c-1; i++) {
        pm = i;
        for (k=i+1; k<c; k++) {
            if (pos_maiores[k] < pos_maiores[i]) pm = k;
        }       

        t1 = pos_maiores[i];
        t2 = maiores[i];
        pos_maiores[i] = pos_maiores[pm];
        maiores[i] = maiores[pm];
        pos_maiores[pm] = t1;
        maiores[pm] = t2;
    }

    for (i=0; i<c; i++) {
        maior_num[i] = maiores[i];
    }
}