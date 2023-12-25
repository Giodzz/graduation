#include "estoque.h" //arquivo header 

int main(void) {
   
   char ans;
   No * busca = NULL;
   Lista * lista_geral = criar_lista_vazia();
   
   //criação das categorias de produtos
   Lista * carnes = criar_lista_vazia();
   Lista * limpeza = criar_lista_vazia();
   Lista * higiene = criar_lista_vazia();
   Lista * papelaria = criar_lista_vazia();
   Lista * padaria = criar_lista_vazia();
   Lista * hortifruti = criar_lista_vazia();
   Lista * vetor[6] = {carnes, limpeza, higiene, papelaria, padaria, hortifruti};
   //                    0        1        2         3         4         5 
   
   do {
      menu(); //exibicao do rol de opcoes a serem selecionadas
      scanf("%c%*c", &ans);

      switch (ans) {
         case '1':
            printf("Voce escolheu adicionar um produto!\n");
            add_produto(lista_geral, vetor);
            break;

         case '2':
            printf("Voce escolheu remover um produto!\n");
            remover_produto(lista_geral, vetor);
            break;

         case '3':
            printf("Voce escolheu visualizar nosso estoque!\n");
            imprimir(lista_geral);
            break;
            
         case '4':
            printf("Voce escolheu buscar por um produto!\n");
            busca = buscar(lista_geral);
            if(busca!=NULL) printf("Nome: %s, Preco: %.2lf, Quantidade: %d, Categoria: %d", busca->nome, busca->preco, busca->qtd, busca->cat); 
            else printf("O produto nao foi encontrado!\nAdicione-o pelo comando 1.\n");
            break;
            
         case '5':
            if(lista_geral->tamanho==0){
                printf("\nErro! Nao ha elementos no estoque para serem ordenados.\n");
                break;
            }
            printf("Voce escolheu ordenar os produtos com base no preco!\n");
            ordenacao_preco(lista_geral);
            break;
            
         case '6':
            if(lista_geral->tamanho==0){
                printf("\nErro! Nao ha elementos no estoque para realizar uma compra.\n");
                break;
            }
            printf("Voce escolheu calcular o valor da compra!\n");
            valor_da_compra(lista_geral);
            break;

         case 'S':
            printf("Ate a proxima!\n");
            break;

         default:
            printf("Opcao invalida!\n");
            break;
      }

   } while (ans != 'S'); //'S' e o comando de saida

   return 0;
}
