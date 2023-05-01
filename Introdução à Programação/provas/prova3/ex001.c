#include <stdio.h>
#include <string.h>
int aliteracoes(char * string);

int main() {

    char str[10000];

    while (scanf("%[^\n]%*c", str) != EOF) {
        aliteracoes(str);
    }       

    return 0;
}

int aliteracoes(char * string) {
    int i;
    int letras = 0, aliteracoes = 0, contador = 0;
    char p_letra, p_letra_ant=' ';

    for (i=0; i<=strlen(string); i++) {
        if (string[i] == ' ' || string[i] == '\0') {
            p_letra = string[i-letras];
            if (p_letra >= 'A' && p_letra <= 'Z') p_letra = p_letra + 32;
            if (p_letra == p_letra_ant) {
                contador++;
                if (string[i] == '\0') aliteracoes++;
            } else if (contador > 0) {
                contador = 0;
                aliteracoes++;
            }
            p_letra_ant = p_letra;
            letras = 0;
            continue;
        }
        letras++;
    }

    printf("%d\n", aliteracoes);
    return aliteracoes;
}