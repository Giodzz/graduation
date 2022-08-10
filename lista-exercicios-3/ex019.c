#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * @brief Converte a string str para o valor inteiro correspondente
 * 
 * @param str string contendo um número inteira
 * @return long int o número inteiro correspondente
 */
long int string2int(const char * string);

int main() {

    long int int_corres;
    char str[129];

    memset(str, 0, 129*sizeof(char));
    while (scanf("%s", str) != EOF) {
        int_corres = string2int(str);
        printf("%ld %ld\n", int_corres, int_corres*2);
    }

    return 0;
}

long int string2int(const char * string) {
    int i;
    int n = 0, p = 0;
    int tamanho_v = strlen(string);

    for (i=tamanho_v-1; i>=0; i--) {
        if (i==0 && string[i]=='-') n = -n;
        else n += ((int)string[i] - 48)*pow(10, p);
        p++;
    }
    
    return n;
}