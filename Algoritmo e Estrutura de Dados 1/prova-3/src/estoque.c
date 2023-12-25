 #include "estoque.h"

void menu(void) { // funcao que exibe um rol de opcoes para o usuario
   printf("\n========== MENU ===========\n");
   printf("[ 1] Adicionar produto\n");
   printf("[ 2] Remover produto\n");
   printf("[ 3] Exibir estoque\n");
   printf("[ 4] Buscar produto\n");
   printf("[ 5] Ordenar produtos em funcao do preco\n");
   printf("[ 6] Calcular valor da compra\n");
   printf("[ S] Sair\n");
   printf("===========================\n");
   printf("Digite uma opcao: ");
}

Lista * criar_lista_vazia(void) { // funcao que cria uma lista, vazia, que ira estocar produtos
   Lista * lista = NULL;
   lista = (Lista *) malloc(sizeof(Lista));

   if (lista == NULL) return NULL;

   lista->inicio = NULL;
   lista->fim = NULL;
   lista->tamanho = 0;
   return lista;
}

No * criar_no(double p, int q, int c, char *nome){ //funcao que cria os nos relativos as listas de produtos
   No * no = NULL;
   no = (No *) malloc(sizeof(No));

   if (no == NULL) return NULL;

   no->preco = p;
   no->qtd = q;
   no->cat = c;

   no->nome = NULL;
   no->nome = (char *) malloc((strlen(nome)+1)*sizeof(char));
   strcpy(no->nome, nome);
   
   no->prox = NULL;
   no->ant = NULL;

   return no;

}

void add_no_final(Lista * lista, No * no) { //funcao que adiciona, ao final da lista, um produto recem-adicionado
   if (lista == NULL) return;

   if (lista->inicio == NULL) { // inicio da lista
      lista->inicio = no;
      lista->fim = no;

   } else {
      no->ant = lista->fim;
      lista->fim->prox = no;
      lista->fim = no;
   }

   lista->tamanho++;
}

void remover_elemento(Lista * lista, char * nome) { //funcao que remove da lista o produto escolhido
    No *remover = NULL;
    No *aux;
    
    if(lista->inicio != NULL){
        if(strcmp(lista->inicio->nome, nome) == 0){
            remover = lista->inicio;
            lista->inicio = remover->prox;
            if(lista->inicio != NULL)
                lista->inicio->ant = NULL;
           
        } else {
            aux = lista->inicio;
            while(aux->prox != NULL && strcmp(aux->prox->nome, nome) != 0)
                aux = aux->prox;
            
            if(aux->prox != NULL){
                remover = aux->prox;
                aux->prox = remover->prox;
                if(aux->prox != NULL)
                    aux->prox->ant = aux;
                
            }
        }
    }
}

void remover_produto(Lista * lista_geral, Lista * vetor[]) { //funcao que "chama" a funcao remover_elemento para lista geral e especifica
    No * remover = NULL;
    remover = buscar(lista_geral);
   
   if(lista_geral->inicio == NULL) {
      printf("Nosso estoque esta vazio!\n");
      printf("Adicione itens pela opcao 1.\n");
      return;
    }

    if(remover == NULL) {
      printf("Nao temos este item em nosso estoque!");
      return;
    }

    remover_elemento(lista_geral, remover->nome);
    remover_elemento(vetor[remover->cat], remover->nome);
    lista_geral->tamanho--;
    vetor[remover->cat]->tamanho--;
    free(remover);
 
    printf("Produto removido com sucesso!\n");
}

No *buscar(Lista *lista){ // funcao que realiza a busca por um produto dentro do inventario cadastrado
    No * no = NULL;
    No * aux;
    char nome[100];
    printf("Atencao: o sistema diferencia letras maiusculas e minusculas!\nEscreva atentamente.\n\n"); //para prevenir possiveis erros
    printf("Nome do produto: ");
    scanf("%[^\n]%*c", nome);

    aux = lista->inicio;
    while(aux && strcmp(aux->nome, nome) != 0)
        aux = aux->prox;

    if(aux)
        no = aux;
    return(no);
}

void add_produto(Lista * lista_geral, Lista * vetor[]){ //cria o produto requerido, e ao final chama a funcao que adiciona o item ao final
    int cat, qtd;
    double preco;
    char nome[100];
    No * produto = NULL;
    
    printf("[0] Carnes\n[1] Limpeza\n[2] Higiene\n[3] Papelaria\n[4] Padaria\n[5] Hortifruti\n");
    printf("Escolha a o tipo de produto: ");
    scanf("%d%*c", &cat);

    printf("Insira o nome do produto: ");
    scanf("%[^\n]%*c", nome);

    printf("Insira o preco do produto: ");
    scanf("%lf%*c", &preco);

    printf("Insira a quantidade disponivel em estoque: ");
    scanf("%d%*c", &qtd);

    produto = criar_no(preco, qtd, cat, nome);
    add_no_final(vetor[cat], produto);
    add_no_final(lista_geral, produto);

    printf("\nProduto adicionado com sucesso\n");
}

void ordenacao_preco(Lista * lista){
    int op;

    printf("\n\nEscolha:\n[1] para ordenar em ordem crescente\n[2] para ordenar em ordem decrescente\n\n");
    scanf("%d%*c", &op);

    switch (op){
    case 1:
        ordena_preco_cres(lista);
        imprimir(lista);
        break;
    
    case 2:
        ordena_preco_dec(lista);
        imprimir(lista);
        break;

    default:
        printf("\nErro! Opcao invalida.\n");
        break;
    }


}

void ordena_preco_cres(Lista * lista) { //ordena, por selection sort, o estoque em ordem crescente de preco
    No *i, *j;
    double tempPreco;
    int tempQtd, tempCat;
    char *tempNome;

    for(i = lista->inicio; i != NULL; i = i->prox) {
        for(j = i->prox; j != NULL; j = j->prox) {
            if(j->preco < i->preco) {
                tempPreco = i->preco;
                i->preco = j->preco;
                j->preco = tempPreco;
                tempQtd = i->qtd;
                i->qtd = j->qtd;
                j->qtd = tempQtd;
                tempCat = i->cat;
                i->cat = j->cat;
                j->cat = tempCat;
                tempNome = i->nome;
                i->nome = j->nome;
                j->nome = tempNome;
            }
        }
    }
}

void ordena_preco_dec(Lista * lista){ //assim como a funcao anterior, ordena por preco, mas por decrescencia de preco
 No *i, *j;
    double tempPreco;
    int tempQtd, tempCat;
    char *tempNome;

    for(i = lista->inicio; i != NULL; i = i->prox) {
        for(j = i->prox; j != NULL; j = j->prox) {
            if(j->preco > i->preco) {
                tempPreco = i->preco;
                i->preco = j->preco;
                j->preco = tempPreco;
                tempQtd = i->qtd;
                i->qtd = j->qtd;
                j->qtd = tempQtd;
                tempCat = i->cat;
                i->cat = j->cat;
                j->cat = tempCat;
                tempNome = i->nome;
                i->nome = j->nome;
                j->nome = tempNome;
            }
        }
    }

}

void valor_da_compra(Lista * lista){ //calcula o valor da compra do cliente
    int qtd_geral, qtd_indv, i;
    double valor = 0;
    char nome[100];
    No * produto = NULL;
    No * aux;

    printf("\nEscolha a quantidade de tipos de itens que o(a) senhor(a) deseja comprar: ");
    scanf("%d%*c", &qtd_geral); //escaneia o numero de itens que irá procurar

    for(i = 0; i < qtd_geral; i++){ 
        printf("Insira o nome do produto: ");
        scanf("%[^\n]%*c", nome);
        printf("Insira a quantidade que deseja comprar: ");
        scanf("%d%*c", &qtd_indv);

        aux = lista->inicio;
        while(aux && strcmp(aux->nome, nome) != 0) //buscando o produto escolhido
            aux = aux->prox;

        if(aux) //verifica se o produto existe
            produto = aux;

        if(produto != NULL){
            if(0 < qtd_indv <= produto->qtd) //verifica se existe a quantidade escolhida no estoque
                valor += (produto->preco * qtd_indv); //soma ao valor final da compra
            else {
                if(qtd_indv <= 0) printf("A quatidade deve ser maior que 0.\n");
                if(qtd_indv > produto->qtd) printf("Infelizmente nao temos essa quantidade em estoque.\n");
            }
           
        } else printf("Produto fora de estoque.\n"); //quando o produto não é encontrado é retornada essa mensagem
    }

    printf("Valor total da compra: R$%.2lf", valor);
}

void imprimir (Lista *lista) { //exibe, na tela, a lista de produtos estocados
    No * aux = lista->inicio;
    if(lista->tamanho==0){
        printf("O estoque esta vazio!\nAdicione produtos pela opcao 1.\n");
        return;
    }
    printf("\n\nEstoque:\n");
    while(aux != NULL) {
        printf("Nome: %s, Preco: %.2lf, Quantidade: %d\n", aux->nome, aux->preco, aux->qtd);
        aux = aux->prox;
    }
    printf("Tamanho: %d\n", lista->tamanho);
}
