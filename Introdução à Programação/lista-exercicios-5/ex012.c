#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int a, b;
} tRacional;
 
/**
 * Calcula o MDC de x e y
 * @param x 
 * @param y 
 * @return int 
 */
int MDC(int x, int y);
 
/**
 * Calcula o MMC de x e y
 * @param x 
 * @param y 
 * @return int 
 */
int MMC(int x, int y);
 
/**
 * Recebe dois inteiros a e b e retorna o racional
 * @param a numerador
 * @param b denominador
 * @return tRacional 
 */
tRacional racional(int a, int b);
 
/**
 * recebe um racional e retorna o seu negativo (-r)
 * @param r numero racional
 * @return tRacional 
 */
tRacional negativo(tRacional r);
 
/**
 * Recebe dois racionais e retorna a adição de ambos (r1 + r2)
 * @param r1 fator esquerdo da soma
 * @param r2 fator direito da soma
 * @return tRacional 
 */
tRacional soma(tRacional r1, tRacional r2);
 
/**
 * Recebe dois racionais e retorna o produto de ambos (r1*r2)
 * @param r1 primeiro fator do produto
 * @param r2 segundo fator do produto
 * @return tRacional 
 */
tRacional mult(tRacional r1, tRacional r2);
 
/**
 * Recebe dois racionais e retorna o quociente de ambos (r1/r2)
 * @param r1 numerador
 * @param r2 denominador
 * @return tRacional 
 */
tRacional divs(tRacional r1, tRacional r2);
 
/**
 * Recebe um racional e reduz a fração ao máximo;
 * @param r o número racioanl a ser reduzido;
 */
void reduzFracao(tRacional * r);
 
 
int main() {
 
    char operador;
    tRacional result;
    tRacional * fracoes = NULL; //vetor de fracoes
    fracoes = (tRacional *) calloc(2, sizeof(tRacional));
 
    while(scanf("%d %d %c %d %d", &fracoes[0].a, &fracoes[0].b, &operador, &fracoes[1].a, &fracoes[1].b) != EOF) {
        
        switch (operador) {
            case '*':
                result = mult(fracoes[0], fracoes[1]);
                break;
            
            case '/':
                result = divs(fracoes[0], fracoes[1]);
                break;
            
            case '+':
                result = soma(fracoes[0], fracoes[1]);
                break;
 
            case '-':
                result = soma(fracoes[0], negativo(fracoes[1]));
                break;
        }
        
        printf("%d %d\n", result.a, result.b);
 
 
        fracoes = (tRacional *) realloc(fracoes, 2*sizeof(tRacional));
    }   
 
    free(fracoes);
    
    return 0;
}
 
int MDC(int x, int y) {
    int resto = 1;
    while (resto != 0) {
        resto = x%y;
        x=y;
        y=resto;
    }
    if (x<0) x = -x;
    return x;
}
 
int MMC(int x, int y) {
    int mmc, i=1;
 
    while (1) {
        if ((x*i)%y == 0) {
            mmc = x*i;
            break;
        }
        i++;
    }
 
    return mmc;
}
 
tRacional mult(tRacional r1, tRacional r2) {
    tRacional mult;
    mult.a = r1.a * r2.a;
    mult.b = r1.b * r2.b;
    reduzFracao(&mult);
    return mult; 
}
 
tRacional divs(tRacional r1, tRacional r2) {
    tRacional div;
    div.a = r1.a * r2.b;
    div.b = r1.b * r2.a;
    reduzFracao(&div);
    return div;
}
 
tRacional negativo(tRacional r) {
    tRacional neg;
    neg.a = (-r.a);
    neg.b = r.b;
    return neg;
}
 
tRacional soma(tRacional r1, tRacional r2) {
    tRacional soma;
    int mmc;
 
    mmc = MMC(r1.b, r2.b);
    soma.b = mmc;
    soma.a = (mmc/r1.b)*r1.a + (mmc/r2.b)*r2.a;
    reduzFracao(&soma);
 
    return soma;
}
 
void reduzFracao(tRacional * r) {
    int mdc;
    if (r->a < 0) mdc = MDC(negativo(*r).a, r->b);
    else mdc = MDC(r->a, r->b);
    r->a = r->a/mdc;
    r->b = r->b/mdc;
}