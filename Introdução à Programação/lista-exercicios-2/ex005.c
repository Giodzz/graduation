#include <stdio.h>
#include <math.h>

/**
 * @brief função que caçcuça as raizes de uma equação de grau 2
 * @param a: coeficiente quadrado
 * @param b: coeficiente linear
 * @param c: coeficiente constante
 * @param x1: ponteiro para a primeira raiz
 * @param x2: ponteiro para segunda raiz
 * @return int 1 para raiz unica
 *             2 para raizes distintas
 *             0 para raizes imaginarias
 *            -1 para coefiientes inválidos (não forma uma equação)
 */
int reaizesEq2Grau(double a, double b, double c, double * x1, double * x2);

int main() {

    double a, b, c;
    double x1, x2;
    int r;
    scanf("%lf %lf %lf", &a, &b, &c);
    r = reaizesEq2Grau(a, b, c, &x1, &x2);
    if (r == 1) {
        printf("RAIZ UNICA\n");
        printf("X1 = %.2lf\n", x1);
    } else if (r == 2) {
        printf("RAIZES DISTINTAS\n");
        if (x1 < x2){
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n", x2);
        } else {
            printf("X1 = %.2lf\n", x2);
            printf("X2 = %.2lf\n", x1);
        }
        
    } else printf("RAIZES IMAGINARIAS\n");

    return 0;
}


int reaizesEq2Grau(double a, double b, double c, double * x1, double * x2) {
    double delta = b*b - 4*a*c;

    if (a == 0) {
        if (b != 0) {
            *x1 = -c / b;
            return 1;
        } else {
            return -1;
        }
    }

    if (delta == 0) {
        *x1 = -b/(2*a); // conteudo de x1
        return 1;
    } else if (delta > 0) {
        *x1 = (-b + sqrt(delta)) / (2*a); // conteudo de x1
        *x2 = (-b - sqrt(delta)) / (2*a); // conteudo de x2
        return 2;
    } else {
        return 0;
    }
}
