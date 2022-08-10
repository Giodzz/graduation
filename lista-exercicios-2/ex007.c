#include <stdio.h>

void print_bytes(const void * end_byte, int n);
void p_bit(unsigned char * byte);

int main() {

    double n;
    scanf("%lf", &n);
    unsigned char uc = n;
    print_bytes(&uc, sizeof(unsigned char));
    unsigned short us = n;
    print_bytes(&us,sizeof(unsigned short));
    unsigned int ui = n;
    print_bytes(&ui,sizeof(unsigned int));
    float f = n;
    print_bytes(&f,sizeof(float));
    print_bytes(&n,sizeof(double));


    return 0;
}

void print_bytes(const void * end_byte, int n) {
    int i;
    unsigned char *pc = (unsigned char *) end_byte; // 1 byte
    for (i = 1; i<= n; i++) {
        p_bit(pc);
        printf(" ");
        pc++;
    }
    printf("\n");
}

void p_bit(unsigned char * byte) { // lendo o conteúdo do ponteiro passado no parâmetro
    unsigned char B = *byte;
    int p = 128;
    int i;
    for (i = 1; i <= 8; i++) {
        printf("%d", B/p); // divisao inteira, arredonda
        B %= p;
        p /= 2;
    }
}