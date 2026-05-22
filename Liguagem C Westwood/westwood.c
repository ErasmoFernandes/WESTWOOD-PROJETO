// ======================================
// PROJETO - WESTWOOD
// Grupo:
// André Richard Rios Escobar
// Issac Batista de Melo
// Ryan Domingues da Cruz
// Rudnei Henrique Perreira Silva
// Pedro Henrique Felix Morgado
// Erasmo Carlos Junior Fernandes
// Ailton Perreira da Silva
// Eduardo Dantas da Silva
// Parte desenvolvida: Sistema em Linguagem C
// Responsáveis pela parte C:
// André Richard Rios Escobar e Issac Batista de Melo
// ======================================

#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 10
#define MAX_PRODUTOS 10
#define MAX_VENDAS 20

// Estrutura para armazenar os dados do cliente
struct Cliente {
    char nome[50];
    int idade;
    char cpf[15];
    char telefone[20];
    char endereco[100];
};

// Estrutura para armazenar os produtos
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

// Estrutura para registrar as vendas
struct Venda {
    int idCliente;
    int idProduto;
    int quantidade;
};

// Função usada para limpar o buffer do teclado
void limparBuffer() {
    while(getchar() != '\n');
}

int main() {

    // Vetores para armazenar clientes, produtos e vendas
    struct Cliente clientes[MAX_CLIENTES];
    struct Produto produtos[MAX_PRODUTOS];
    struct Venda vendas[MAX_VENDAS];

    int totalClientes = 0;
    int totalProdutos = 0;
    int totalVendas = 0;

    // Armazena o valor total de todas as vendas
    float totalGeralVendas = 0;

    int opcao;

    do {

        printf("\n============================\n");
        printf("        WESTWOOD\n");
        printf("============================\n");

        printf("1 - Cadastrar Cliente\n");
        printf("2 - Cadastrar Produto\n");
        printf("3 - Listar Clientes\n");
        printf("4 - Listar Produtos\n");
        printf("5 - Realizar Venda\n");
        printf("6 - Listar Vendas\n");
        printf("0 - Sair\n");

        printf("Escolha: ");

        scanf("%d", &opcao);

        limparBuffer();

        switch(opcao) {

            case 1:

                if (totalClientes >= MAX_CLIENTES) {

                    printf("Limite de clientes atingido!\n");

                    break;
                }

                printf("Nome: ");
                fgets(clientes[totalClientes].nome, 50, stdin);

                clientes[totalClientes].nome[
                    strcspn(clientes[totalClientes].nome, "\n")
                ] = '\0';

                printf("Idade: ");
                scanf("%d", &clientes[totalClientes].idade);

                limparBuffer();

                printf("CPF: ");
                fgets(clientes[totalClientes].cpf, 15, stdin);

                clientes[totalClientes].cpf[
                    strcspn(clientes[totalClientes].cpf, "\n")
                ] = '\0';

                printf("Telefone: ");
                fgets(clientes[totalClientes].telefone, 20, stdin);

                clientes[totalClientes].telefone[
                    strcspn(clientes[totalClientes].telefone, "\n")
                ] = '\0';

                printf("Endereco: ");
                fgets(clientes[totalClientes].endereco, 100, stdin);

                clientes[totalClientes].endereco[
                    strcspn(clientes[totalClientes].endereco, "\n")
                ] = '\0';

                totalClientes++;

                printf("Cliente cadastrado com sucesso!\n");

                break;

            case 2:

                if (totalProdutos >= MAX_PRODUTOS) {

                    printf("Limite de produtos atingido!\n");

                    break;
                }

                printf("Nome do produto: ");
                fgets(produtos[totalProdutos].nome, 50, stdin);

                produtos[totalProdutos].nome[
                    strcspn(produtos[totalProdutos].nome, "\n")
                ] = '\0';

                printf("Preco: ");
                scanf("%f", &produtos[totalProdutos].preco);

                printf("Quantidade: ");
                scanf("%d", &produtos[totalProdutos].quantidade);

                limparBuffer();

                totalProdutos++;

                printf("Produto cadastrado com sucesso!\n");

                break;

            case 3:

                if (totalClientes == 0) {

                    printf("Nenhum cliente cadastrado!\n");

                } else {

                    for(int i = 0; i < totalClientes; i++) {

                        printf("\nCliente %d\n", i + 1);

                        printf("Nome: %s\n", clientes[i].nome);
                        printf("Idade: %d\n", clientes[i].idade);
                        printf("CPF: %s\n", clientes[i].cpf);
                        printf("Telefone: %s\n", clientes[i].telefone);
                        printf("Endereco: %s\n", clientes[i].endereco);
                    }
                }

                break;

            case 4:

                if (totalProdutos == 0) {

                    printf("Nenhum produto cadastrado!\n");

                } else {

                    for(int i = 0; i < totalProdutos; i++) {

                        printf("\nProduto %d\n", i + 1);

                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Preco: R$ %.2f\n", produtos[i].preco);
                        printf("Quantidade em estoque: %d\n",
                               produtos[i].quantidade);
                    }
                }

                break;

            case 5: {

                char continuar;
                int idC;

                if (totalClientes == 0 || totalProdutos == 0) {

                    printf("Cadastre clientes e produtos primeiro!\n");

                    break;
                }

                printf("\n======= CLIENTES =======\n");

                for(int i = 0; i < totalClientes; i++) {

                    printf("%d - %s\n",
                           i + 1,
                           clientes[i].nome);
                }

                printf("Escolha o cliente (ID): ");

                scanf("%d", &idC);

                limparBuffer();

                idC--;

                if (idC < 0 || idC >= totalClientes) {

                    printf("Cliente invalido!\n");

                    break;
                }

                do {

                    int idP, qtd;

                    if (totalVendas >= MAX_VENDAS) {

                        printf("Limite de vendas atingido!\n");

                        break;
                    }

                    printf("\nCliente atual: %s\n",
                           clientes[idC].nome);

                    printf("\n======= PRODUTOS =======\n");

                    for(int i = 0; i < totalProdutos; i++) {

                        printf("%d - %s (Estoque: %d)\n",
                               i + 1,
                               produtos[i].nome,
                               produtos[i].quantidade);
                    }

                    printf("Escolha o produto (ID): ");

                    scanf("%d", &idP);

                    printf("Quantidade: ");

                    scanf("%d", &qtd);

                    limparBuffer();

                    idP--;

                    if (idP < 0 || idP >= totalProdutos) {

                        printf("Produto invalido!\n");
                    }

                    else if (qtd <= 0) {

                        printf("Quantidade invalida!\n");
                    }

                    else if (qtd > produtos[idP].quantidade) {

                        printf("Estoque insuficiente!\n");
                    }

                    else {

                        // Atualiza o estoque após a venda
                        produtos[idP].quantidade -= qtd;

                        // Calcula o valor da venda
                        float valorVenda =
                            qtd * produtos[idP].preco;

                        // Soma ao total geral vendido
                        totalGeralVendas += valorVenda;

                        vendas[totalVendas].idCliente = idC;
                        vendas[totalVendas].idProduto = idP;
                        vendas[totalVendas].quantidade = qtd;

                        totalVendas++;

                        printf("\nVenda realizada com sucesso!\n");

                        printf("Valor da venda: R$ %.2f\n",
                               valorVenda);

                        printf("Estoque restante: %d\n",
                               produtos[idP].quantidade);

                        printf("Total geral vendido: R$ %.2f\n",
                               totalGeralVendas);
                    }

                    printf("\nDeseja continuar comprando para o mesmo cliente? (s/n): ");

                    scanf(" %c", &continuar);

                    limparBuffer();

                } while((continuar == 's' || continuar == 'S')
                        && totalVendas < MAX_VENDAS);

                break;
            }

            case 6:

                if (totalVendas == 0) {

                    printf("Nenhuma venda realizada!\n");

                } else {

                    for(int i = 0; i < totalVendas; i++) {

                        int c = vendas[i].idCliente;
                        int p = vendas[i].idProduto;

                        printf("\nVenda %d\n", i + 1);

                        printf("Cliente: %s\n",
                               clientes[c].nome);

                        printf("Produto: %s\n",
                               produtos[p].nome);

                        printf("Quantidade: %d\n",
                               vendas[i].quantidade);

                        printf("Total: R$ %.2f\n",
                               vendas[i].quantidade *
                               produtos[p].preco);
                    }

                    printf("\n=================================\n");

                    printf("TOTAL GERAL DE VENDAS: R$ %.2f\n",
                           totalGeralVendas);

                    printf("=================================\n");
                }

                break;

            case 0:

                printf("Saindo do sistema...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}