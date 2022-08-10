// Composição Inteira
 
#include <stdio.h>
 
int main() {
    int n1, n2, n3, num, quadrado;
    scanf("%d\n", &n1);
    scanf("%d\n", &n2);
    scanf("%d\n", &n3);
 
    num = 100*n1 + 10*n2 + n3; 
    quadrado = num * num;
 
    if (n1 >= 10 || n2 >= 10 || n3 >= 10) {
        printf("DIGITO INVALIDO");
    } else {
        printf("%d, %d", num, quadrado);
    }
    
 
    return 0;
}