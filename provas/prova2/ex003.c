#include <stdio.h>

int verificar_interc(int qtd_numeros);

int main() {

    int n, contador;
    scanf("%d", &n);
    while(n!=0) {
        contador = verificar_interc(n);
        if (contador > 0) printf("Nao intercalada\n");
        else printf("Intercalada\n");
        scanf("%d", &n);
    }

    return 0;
}

int verificar_interc(int qtd_numeros) {
    int i, num, num_a = 0, c = 0, descrescente = 0, crescente = 0;
    for (i=1; i<= qtd_numeros; i++) {
        scanf("%d", &num);
        if (i == 1) { 
            num_a = num;
            continue;
        }
        if (i == 2) {
            if (num > num_a) {
                crescente = 1;                
            } else if (num < num_a) {
                descrescente = 1;
            } else c++;
        }

        if (crescente) {
            if (i%2 == 1) { // i == impar
                if (num_a <= num) c++;
            }
            if (i%2 == 0) { // i == par
                if (num_a >= num) c++;
            }
            
        } else if (descrescente) {
            if (i%2 == 0) { // i == par
                    if (num_a <= num) c++;
                }
                if (i%2 == 1) { // i == impar
                    if (num_a >= num) c++;
                }
        } else c++;
                    
        num_a = num;
    }

    return c;
}