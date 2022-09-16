#include <stdio.h>
#include <math.h>

int main() {

    double n1, n2;
    char o;

    scanf("%lf%c%lf", &n1, &o, &n2);

    switch (o) {
        // operadores aritméticos
        case '+':
            printf("%.2lf\n", n1+n2);
            break;

        case '-':
            printf("%.2lf\n", n1-n2);
            break;

        case '*':
            printf("%.2lf\n", n1*n2);
            break;

        case '/':
            printf("%.2lf\n", n1/n2);
            break;
        
        case '%':
            printf("%d\n", ((int) n1) % ((int) n2));
            break;

        case '~':
            printf("%.2lf\n", pow(n1, n2));
            break;
        
        // operadores realcionais
        case '=':
            if (n1 == n2) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;

        case '!':
            if (n1 != n2) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;

        case '<':
            if (n1 < n2) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;

        case '>':
            if (n1 > n2) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;
        
        // operadores lógicos
        case '^':
            if (n1 && n2) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;
        
        case 'v':
            if (n1 || n2) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;

        case '#': // x trocado por #
            // ou exclusivo - é verdadeiro quando são diferentes (VF ou FV)
            if ((n1 == 0 && n2 != 0) || (n1 != 0 && n2 == 0)) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;

        default:
            printf("Operador inexistente\n");
            break;
    }
    return 0;
}