#include <stdio.h>
#include <string.h>

int main() {

    int n, d;
    char num[10], maior[10]; //mudar para 100000

    scanf("%d %d", &n, &d);
    memset(num, 0, 10*sizeof(char));
    while (n||d) {
        scanf("%s", num);

        apague_ganhe(num, d, maior);

        scanf("%d %d", &n, &d);
    }

    return 0;
}

void apague_ganhe(char * num, int qtd_r, char * maior_num) {
    int i;
    int tamanho_v = strlen(num);
    char maior='0';
    char maior_ant;
    char pos_maiores[10], maiores[10];

    for (i=0, i<tamanho_v-1;)

}