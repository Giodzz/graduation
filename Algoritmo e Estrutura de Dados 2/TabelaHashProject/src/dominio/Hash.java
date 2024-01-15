package dominio;

import java.util.Arrays;
import java.util.Scanner;

public class Hash {
    private final int linhas = 50_000;
    public Lista[] tabelaHash;

    public void makeTable() {
        this.tabelaHash = new Lista[this.linhas];
        for (int i=0; i < this.linhas; i++) {
            this.tabelaHash[i] = new Lista();
        }
    }

    public void showTable() {
        System.out.println("\n================ TABELA HASH ================");
        if (this.tabelaHash == null) {
            System.out.println("Tabela Vazia");
        }

        int c = 0;
        for (int i = 0; i < tabelaHash.length; i++) {
            Lista lista = tabelaHash[i];
            if (lista.tamanho == 0) continue;
            System.out.println(i + ": " + lista.listaToString());
            c++;
        }

        if (c == 0) System.out.println("Tabela Vazia.");

        System.out.println("=============================================");
    }


    public void destroyTable() {
        this.tabelaHash = null;
    }

    public int sizeTable() {
        int soma = 0;
        for (Lista lista : this.tabelaHash) {
            soma += lista.tamanho;
        }

        return soma;
    }

    public void insertTable(double x, String dados) {
        if (x < 0.000001 || x > 99999999.999999) {
            System.out.println("Chave primária inválida. Elemento não adicionado.");
            return;
        }

        if (this.sizeTable() >= 50_000_000) {
            System.out.println("Valor máximo de elementos alcançado. Não é possível inserir mais!");
        }

        int pos = hashFunction(x);
        this.tabelaHash[pos].adicionarNoFinal(x, dados);
    }

    public No searchTable(double x) {
        int pos = hashFunction(x);
        return this.tabelaHash[pos].buscar(x);
    }

    public No[] searchTable(String s) {
        No[] busca = null;

        for (Lista lista: this.tabelaHash) {
            if (lista.buscar(s) != null) {
                if(busca == null) busca = new No[0];
                for (No no: lista.buscar(s)) {
                    busca = Arrays.copyOf(busca, busca.length + 1);
                    busca[busca.length - 1] = no;
                }
            }
        }

        return busca;
    }

    public void removeTable(double x) {
        int pos = hashFunction(x);
        tabelaHash[pos].removerNo(x);
    }

    public void removeTable(String s) {
        No[] busca = this.searchTable(s);

        if (busca == null) {
            System.out.println("Não há elementos com essa informação");
            return;
        }

        for (No no : busca) {
            this.removeTable(no.informacao.chave);
        }
    }

    private int hashFunction(double chave) {
        int k = (int) ((chave * 1_000_000) % this.linhas);
        return k;
    }

    public void menu() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n=========== MENU ===========");
            System.out.println("0. Sair");
            System.out.println("1. Criar Tabela Vazia");
            System.out.println("2. Mostrar Tabela");
            System.out.println("3. Destruir Tabela");
            System.out.println("4. Mostrar Tamanho da Tabela");
            System.out.println("5. Inserir elemento na Tabela");
            System.out.println("6. Buscar elemento na Tabela pela chave");
            System.out.println("7. Buscar elementos na Tabela pelos dados");
            System.out.println("8. Remover elemento da Tabela pela chave");
            System.out.println("9. Remover elementos da Tabela pelos dados");

            System.out.print("Escolha a opção (0-9): ");
            int escolha = scanner.nextInt();

            if ((escolha >= 0 && escolha <= 9) && (this.tabelaHash == null && (escolha != 0 && escolha != 1))) {
                System.out.println("\nTabela ainda não criada.");
                continue;
            }

            switch (escolha) {

                case 0:
                    // Sair
                    System.out.println("Encerrando o programa.");
                    scanner.close();
                    System.exit(0);

                case 1:
                    // Criar Tabela Vazia
                    this.makeTable();
                    if (this.tabelaHash != null)
                        System.out.println("Tabela Vazia criada com sucesso");
                    else
                        System.out.println("Erro ao criar a Tabela.");
                    break;

                case 2:
                    // Mostrar Tabela
                    this.showTable();
                    break;

                case 3:
                    //Destruir a Tabela
                    this.destroyTable();
                    System.out.println("Tabela foi destruída com sucesso.");
                    break;

                case 4:
                    // Mostrar Tamanho da Tabela
                    System.out.println("A Tabela tem " + this.sizeTable() + " elementos");
                    break;

                case 5:
                    // Inserir elemento
                    System.out.print("Digite a chave (coloque vírgula como ponto flutuante): ");
                    double chaveInserir = scanner.nextDouble();
                    scanner.nextLine(); // Consumir a quebra de linha
                    System.out.print("Digite os dados: ");
                    String dadosInserir = scanner.nextLine();
                    this.insertTable(chaveInserir, dadosInserir);
                    break;

                case 6:
                    // Buscar elemento pela chave
                    System.out.print("Digite a chave: ");
                    double chaveBuscar = scanner.nextDouble();
                    No resultadoBuscaChave = searchTable(chaveBuscar);

                    if (resultadoBuscaChave != null) {
                        System.out.println("Elemento encontrado: " + resultadoBuscaChave.nodeToString());
                    } else {
                        System.out.println("Elemento não encontrado.");
                    }
                    break;

                case 7:
                    // Buscar elemento pelos dados
                    System.out.print("Digite os dados: ");
                    scanner.nextLine(); // Consumir a quebra de linha
                    String dadosBuscar = scanner.nextLine();
                    No[] resultadoBuscaDados = searchTable(dadosBuscar);

                    if (resultadoBuscaDados != null) {
                        System.out.println("Elemento(s) encontrado(s):");
                        for (No no: resultadoBuscaDados) {
                            System.out.println(no.nodeToString());
                        }
                    } else {
                        System.out.println("Não há nenhum elemento com esses dados!");
                    }
                    break;

                case 8:
                    // Remover elemento pela chave
                    System.out.print("Digite a chave (coloque vírgula como ponto flutuante): ");
                    double chaveRemover = scanner.nextDouble();
                    this.removeTable(chaveRemover);
                    break;

                case 9:
                    // Remover elementos pelos dadados
                    System.out.print("Digite o dado: ");
                    scanner.nextLine(); // consumir a quebra de linha
                    String dadosRemover = scanner.nextLine();
                    this.removeTable(dadosRemover);
                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }
}