#include <stdio.h>

/**
 * @brief Função que calcula os interceptos de uma reta nos eixos x e y
 * de um Plano Cartesiano e verifica a qual eixo ela é paralela
 * A reta é definida pela equação paramétrica: ax + by + c = 0
 * de forma que a, b, e c são os coeficientes da equação
 * 
 * @param a Coeficiente linear em c
 * @param b Coeficiente linear em y
 * @param c Coeficiente constante
 * @param x variavel x
 * @param y variavel y
 * @return 0 quando a reta nao é paralela a nenhum eixo, 1 quando a reta é paralela ao eixo x, 2 quando a reata é paralela ao eixo y e -1 quando a reta for invalida.
 */
int intercepto(double a, double b, double c, double *x, double *y) ;

int main() {

    int n_casos, i;
    double a, b, c, x, y;
    scanf("%d", &n_casos);
    for (i = 1; i<= n_casos; i++) {
        scanf("%lf %lf %lf", &a, &b, &c);
        intercepto(a, b, c, &x, &y);
    }

    return 0;
}

int intercepto(double a, double b, double c, double *x, double *y) {
    if(a != 0 && b != 0) {
        printf("NAO PARALELA\n");
        *y = -c/b;
        *x = (c) / (-a);
        printf("Intercepto em X: (%.2lf, 0.00)\n", *x);
        printf("Intercepto em Y: (0.00, %.2lf)\n", *y);
        return 0;
    } else if (a == 0 && b == 0) {
        printf("RETA INVALIDA\n");
        return -1;
    } else if (b == 0) {
        printf("PARALELA AO EIXO Y\n");
        *x = (c) / (-a);
        printf("Intercepto em X: (%.2lf, 0.00)\n", *x);
        return 1;
    } else if (a == 0) {
        printf("PARALELA AO EIXO X\n");
        *y = -c/b;
        printf("Intercepto em Y: (0.00, %.2lf)\n", *y);
        return 2;
    }
}