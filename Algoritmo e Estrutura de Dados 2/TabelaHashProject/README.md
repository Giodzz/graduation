# TabelaHash
Esse é um projeto desenvolvido como parte da disciplina de Algoritmo e Estruturas de Dados 2 (AED2), com o objetivo de implementar uma Tabela Hash e as principais funções. O projeto é conduzido pelos estudantes Giordana Bucci, Guilherme Tavares e Giovana Vilas Boas.

## Especificações da criação do projeto

- **Sistemas Operacionais**: Windows 11 e MAcOS
- **IDE**: IntelliJ IDEA da JetBrains

## Informações Principais

A aplicação baseia-se na criação e utilização da Tabela Hash, que pode conter de zero a cinquenta milhões (0 - 50.000.000) de elementos com duas informações: uma *chave primária* para identificá-lo com até 8 dígitos na parte inteira e até 6 dígitos na parte decimal (chave) e *dados satélites* (dado). Foi implementada a técnica de encadeamento para o tratamento de colisões com a utlização da lista linear duplamente encadeada, assim como as seguintes operações na classe Hash:

1. **makeTable()**: cria a tabela como Lista[] tabelaHash vazia.
2. **showTable()**: apresenta todos os elementos da tabelaHash na forma "<índice na lista tabelaHash: (chave: <chave do elemento>, dado: <dados satélites>)" ou a mensagem "Tabela Vazia" caso não constar nenhuma entrada.
3. **destroyTable()**: destrói a tabela.
4. sizeTable(): retorna a quantidade de elementos presentes na tabela.
5. **insertTable(x, *dados*)**: insere na tabela um elemento com a chave primária x com seus *dados* associados.
6. **searchTable(x)**: busca na tabela um elemento pela chave primária x.
7. **searchTable(*dados*)**: busca na tabela todas as chaves primárias que possuam os *dados*.
8. **removeTable(x)**: remove da tabela a chave primária x e seus *dados* correspondentes.
9. **removeTable(*dados*)**: remove da tabela todas as chaves primárias que possuam os *dados*.

## Manual do Usuário

### Como executar o Projeto
1. Clone este repositório em sua máquina local:

   ```bash
   git clone https://github.com/Giodzz/TabelaHash.git
2. Abra o projeto em sua IDE Java preferida.
3. Execute o programa a partir da classe principal (Main).
4. Utilize o menu de usuário para manipular a Tabela Hash


### Menu no Terminal
A aplicação contém um menu com 10 opções:

0. Sair: encerra o programa.
   TabelaHash
1. Criar Tabela Vazia: cria uma tabela inicialmente sem elementos
2. Mostrar tabela: apresenta todos os elementos da tabela na forma "<índice na lista tabelaHash>: (chave: <chave do elemento>, dado: <dados satélites>)" ou a mensagem "Tabela Vazia." caso não constar nenhuma entrada.
3. Destruir tabela: remove os elementos da tabela e retorna a mensagem: "Tabela foi destruída com sucesso."
4. Mostrar Tamanho da Tabela: calcula a quantidade de elementos que tem na tabela e mostra a mensagem:
   "A Tabela tem <quantidade de elementos> elementos"
5. Inserir elemento na tabela: insere o elemento na tabela com chave e dado.
6. Buscar elemento pela chave: busca um elemento na Tabela Hash pela chave primária. Se o elemento for encontrado, esse elemento é mostrado, se não, apresenta a mensagem "Elemento não encontrado".
7. Buscar elementos pelos dados: busca todos os elementos da Tabela que possuem os dados informados
8. Remover elemento pela chave: remove da tabela o elemento que possui aquela chave primária
9. Remover elementos pelos dados: remove da tabela todos os elementos que possuem os dados especificados


