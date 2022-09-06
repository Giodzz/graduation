#include <stdio.h>
#include <stdlib.h>

typedef struct _funcionario {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} Funcionario;

int main() {

    int qtd_func, i, c; 
    int soma_id = 0, soma_fi = 0;
    double media_id, media_fi;
    Funcionario * func = NULL;

    scanf("%d", &qtd_func);
    func = (Funcionario *) malloc(qtd_func*sizeof(Funcionario));

    // entrada de informações
    for (i=0; i<qtd_func; i++) {
        scanf("%d %d %d %c %lf", &func[i].matricula, &func[i].idade, &func[i].numFilhos, &func[i].sexo, &func[i].salario);
        soma_id += func[i].idade;
        soma_fi += func[i].numFilhos;
    }  

    media_id = soma_id/qtd_func;
    media_fi = soma_fi/qtd_func;

    // impressao 1
    c=0;
    for (i=0; i<qtd_func; i++) {
        if (func[i].idade > media_id && func[i].salario > 3*1200.00) c++;
    }
    printf("%d ", c);

    // impressao 2 
    c = 0;
    for (i=0; i<qtd_func; i++) {
        if (func[i].sexo == 'F' && func[i].numFilhos > media_fi) c++;
    }
    printf("%d ", c);

    // impressão 3
    c = 0;
    for (i=0; i<qtd_func; i++) {
        if (func[i].sexo == 'M' && func[i].numFilhos > media_fi) c++;
    }
    printf("%d ", c);

    //impressao 4
    c = 0;
    for (i=0; i<qtd_func; i++) {
        if (func[i].idade > 47 && (func[i].salario/(func[i].numFilhos+1)) < 2*1200.00) c++;
    }
    printf("%d\n", c);


    free(func);
    return 0;
}