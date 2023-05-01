#include <stdio.h>
#include <math.h>
 
typedef struct _complex {
    double real, imag;
} Complex;
 
typedef struct _raizequ2{
    Complex r[2]; // [x1, x2]
} RaizEqu2;
 
/**
 * Função que calcula as raízes de uma equação de segundo grau
 * 
 * @param a coeficiente quadrado
 * @param b coeficiente linear
 * @param c constante
 * @return raizes retorna uma estrutura RaizEqu2 com dois números complexos
 */
RaizEqu2 calcula_raiz_equ_2(double a, double b, double c);
 
/**
 * Imprime numeros complexos na saida padrão do sistema.
 * A impressão segue o formato a + bi, onde a é a parte
 * real e b a imaginária. Os valores são representados
 * somente se forem diferentes de zero. No caso de a e b
 * forem zero, o valor 0 é apresentado.
 * Se o valor de b for 1 ou -1, somente o caracter
 * i ou -i é apresentado.
 * 
 * @param c Numero complexo a ser impresso
 */
void complex_print(Complex c);
 
 
 
int main() {
 
    double a, b, c;
    RaizEqu2 raizes;
    scanf("%lf %lf %lf", &a, &b, &c);
    raizes = calcula_raiz_equ_2(a, b, c);
    printf("x1 = ");
    complex_print(raizes.r[0]);
    printf("x2 = ");
    complex_print(raizes.r[1]);
 
    return 0;
}
 
RaizEqu2 calcula_raiz_equ_2(double a, double b, double c) {
    RaizEqu2 raiz;
    int delta;
    delta = b*b - 4*a*c;
    if (delta == 0) {
        raiz.r[0].real = -b/(2*a); 
        raiz.r[0].imag = 0;
        raiz.r[1] = raiz.r[0]; // x1 == x2 (não importa o tipo de dado na hora da atribuição, importa apenas a memória)
 
    } else if (delta > 0) {
        raiz.r[0].real = (-b + sqrt(delta))/(2*a);
        raiz.r[1].real = (-b - sqrt(delta))/(2*a);
        raiz.r[0].imag = raiz.r[1].imag = 0;
 
    } else if (delta < 0) {
        raiz.r[0].real = raiz.r[1].real = -b/(2*a);
        raiz.r[0].imag = + (sqrt(-delta))/(2*a); //*i
        raiz.r[1].imag = - sqrt(-delta)/(2*a); //*i
    }
 
    return raiz;
}
 
void complex_print(Complex c) {
    if (c.imag != 0) {
        if (c.imag == 1) {
            if (c.real != 0) printf("%.2lf+i\n", c.real);
            else printf("i\n");
 
        } else if (c.imag == -1) {
            if (c.real != 0) printf("%.2lf-i\n", c.real);
            else printf("-i\n");
 
        } else {
            if (c.real != 0) printf("%.2lf%+.2lfi\n", c.real, c.imag);
            else printf("%.2lfi\n", c.imag);
        }
 
    } else {
        if (c.real != 0) printf("%.2lf\n", c.real);
        else printf("0.00\n");
    }
}