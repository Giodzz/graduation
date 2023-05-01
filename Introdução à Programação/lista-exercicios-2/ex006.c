#include <stdio.h>
/**
* Função que calcula a raiz quadrada de n.
* @param n um numero real qualquer
* @param p precisão do cálculos
* @return a raiz quadrada de n
*/
double raiz(double n, double p);
/**
* Valor absoluto de um numero qualquer
* @param n um número real qualquer
* @return o valor absoluto de n
*/
double absoluto(double n);

int main() {

    double n, e;
    scanf("%lf%lf", &n, &e);
    raiz(n, e);


    return 0;
}

double raiz(double n, double p) {
    double r = 1, en = 1;
    double rant = 1;
    while (en > p){
        r = (rant + (n/rant))/2;
        en = absoluto(n - r*r);
        printf("r: %.9lf, err: %.9lf\n", r, en);
        rant = r;
    }
    return r;

}

double absoluto(double n) {
    if (n < 0) n = -n;
    return n;
}
