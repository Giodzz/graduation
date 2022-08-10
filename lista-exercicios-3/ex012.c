// retornar a string correspondente ao prefixo de str de tamanho n

#include <stdio.h>
char * str_prefixo(int n, char * s, char * p);

int main() {
    char str[500], *pstr, prefixo[500];
    int n, k;

    scanf("%d", &n); // despresa o \n e os espaços quando procura um int coerente

    while(n--) {
        scanf("%d%*c", &k);
        scanf("%[^\n]", str);
        pstr = str_prefixo(k, str, prefixo);
        printf("%s\n", prefixo);
    }


    return 0;
}

char * str_prefixo(int n, char * s, char * p) {
    int i;

    for (i=0; i<n; i++) {
        p[i] = s[i];
    }
    p[i] = '\0';

    return p;

}