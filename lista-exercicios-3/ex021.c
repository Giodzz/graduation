#include <stdio.h>
void fill_vetor(int * vetor);
int mega_sena(int * comp, int * ref);

int main() {

    int i, n_apostas;
    int sena = 0, quina = 0, quadra = 0;
    int sorteados[6], aposta[6];
    
    fill_vetor(sorteados);

    scanf("%d", &n_apostas);
    while (n_apostas--) {
        fill_vetor(aposta);
        switch (mega_sena(aposta, sorteados)) {
            case 4:
                quadra++;
                break;

            case 5:
                quina++;
                break;

            case 6:
                sena++;
                break;
        }
    }

    if (sena>0) printf("Houve %d acertador(es) da sena\n", sena);
    else printf("Nao houve acertador para sena\n");

    if (quina>0) printf("Houve %d acertador(es) da quina\n", quina);
    else printf("Nao houve acertador para quina\n");

    if (quadra>0) printf("Houve %d acertador(es) da quadra\n", quadra);
    else printf("Nao houve acertador para quadra\n");

    return 0;
}

void fill_vetor(int * vetor) {
    int i;
    for (i=0; i<6; i++) {
        scanf("%d", &vetor[i]);
    }
}

int mega_sena(int * comp, int * ref) {
    int i, k;
    int acertos = 0;

    for (i=0; i<6; i++) {
        for (k=0; k<6; k++) {
            if (comp[i] == ref[k]) acertos++;
        }
    }
    return acertos;
}