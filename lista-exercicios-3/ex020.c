#include <stdio.h>
#include <string.h>
void apague_ganhe(char * vetor, int qtd_p, char * maior_v);

int main() {

    int n, d;
    char num[100000], maior[100000];

    memset(num, 0, 100000*sizeof(char));
    memset(maior, 0, 100000*sizeof(char));
    scanf("%d %d", &n, &d);
    while(n!=0 && d!=0) {
        scanf("%s", num);

        apague_ganhe(num, d, maior);

        scanf("%d %d", &n, &d);
    }

    return 0;
}

void apague_ganhe(char * vetor, int qtd_p, char * maior_v) {
    int i, pm; //pm: posição do maior
    int c = 0;
    char maior, maior_ant = '9';
    int tamanho_v = strlen(vetor);

    while (c < qtd_p) {
        maior = 0;
        for (i=0; i<tamanho_v; i++) {
            if (vetor[i] > maior) {
                if (c != 0) {
                    if (vetor[i] < maior_ant) {
                        maior = vetor[i];
                        pm = i;
                    }
                } else {
                    maior = vetor[i];
                    pm = i;
                }
                
            }
        }
        maior_v[pm] = vetor[pm];
        maior_ant = maior;
        c++;
    }


}

void apagar_zeros(int * vetor) { 
}