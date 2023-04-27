// media de pares e impares

#include <stdio.h>

int main() {

    // tem que definir todas as variaveis
    int n = 1, soma_par = 0, soma_impar = 0, cp = 0, ci = 0;
    double mp = 0, mi = 0;


    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        if (n%2 == 0) {
            soma_par += n;
            cp++;
        } else {
            soma_impar += n;
            ci++;
        }
    }
    
    // testando divisao por zero
    if (cp != 0) mp = soma_par / (double) cp;
    if (ci != 0) mi = soma_impar / (double) ci;
        
    printf("MEDIA PAR: %lf\n", mp);
    printf("MEDIA IMPAR: %lf", mi);


    return 0;
}
