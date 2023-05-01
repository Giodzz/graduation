#include <stdio.h>
#include <string.h>
int contar_vogais(char * vetor, int tamanho_v);
int contar_consoantes(char * vetor, int tamanho_v);
 
int main() {
 
    int c, n_testes, vogais, consoantes, letras;
    char string[10000];
    scanf("%d%*c", &n_testes);
    for (c=0; c<n_testes; c++) {
        memset(string, 0, 10000*sizeof(char)); // zerar vetor
        scanf("%[^\n]%*c", string); //não precisa de &
        vogais = contar_vogais(string, strlen(string));
        consoantes = contar_consoantes(string, strlen(string));
        letras = vogais + consoantes;
        printf("Letras = %d\n", letras);
        printf("Vogais = %d\n", vogais);
        printf("Consoantes = %d\n", consoantes);
    }
 
    return 0;
}
 
int contar_vogais(char * vetor, int tamanho_v) {
    int i, c, total_vogais = 0;
    char letra, vogal;
    char vogais[11] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
 
    for (i=0; i<tamanho_v; i++) {
        letra = vetor[i];
        for (c=0; c<10; c++) {
            vogal = vogais[c];
            if (letra == vogal) total_vogais += 1;
        }
    }
 
    return total_vogais;
}
 
int contar_consoantes(char * vetor, int tamanho_v) {
    int i, c, total_consoantes = 0;
    char letra, consoante;
    char consoantes[43] = {'b', 'B', 'c', 'C', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z'};
 
    for (i=0; i<tamanho_v; i++) {
        letra = vetor[i];
        for (c=0; c<42; c++) {
            consoante = consoantes[c];
            if (letra == consoante) total_consoantes += 1;
        }
    }
 
    return total_consoantes;
}