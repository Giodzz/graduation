// Validar senha

#include <stdio.h>

int main() {

    int senha;
    char categ;

    scanf("%d %c", &senha, &categ);

    if (senha >= 100000) {
        if (categ == 'A' || categ == 'G' || categ == 'U'){
            if ((categ == 'A' && senha ==  321456) || (categ == 'G' && senha == 9510753) || (categ == 'U' && senha == 78955632)) {
                printf("ACESSO PERMITIDO A CATEGORIA %c\n", categ);
            } else {
                printf("ACESSO NEGADO\n");
            }

        } else {
            printf("CATEGORIA INVALIDA: %c\n", categ);
        }
        
    } else {
        printf("SENHA INVALIDA: %d - MINIMO 6 DIGITOS\n", senha);
    }

    return 0;
}