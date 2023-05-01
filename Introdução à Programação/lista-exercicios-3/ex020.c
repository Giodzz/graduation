#include <stdio.h>
#include <string.h>
void apague_ganhe(char * num, int qtd_r);
 
int main() {
 
    int n, d;
    char num[100000];
    
    memset(num, 0, 100000*sizeof(char));
    scanf("%d %d", &n, &d);
    while (n&&d) {
        scanf("%s", num);
        apague_ganhe(num, d);
        scanf("%d %d", &n, &d);
    }
 
    return 0;
}
 
void apague_ganhe(char * num, int qtd_r) {
    int i;
    int tamanho_v = strlen(num), pos = -1;
    char maior = '0';
 
    while (qtd_r) {
        maior = '0';
 
        for (i=pos+1; i<tamanho_v-(qtd_r-1); i++) {
            if (num[i] > maior) {
                maior = num[i];
                pos = i;
            }
        }
 
        printf("%c", maior);
        qtd_r--;
    }
    printf("\n");
 
}