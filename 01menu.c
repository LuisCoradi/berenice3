#include "02produtos.h"
#include "tipos.h"

void submenu_produtos(Produto **prod, int *totalprod)
{

    //Produto **prod = qualquer coisa que passar na chamada da variavel

    int opc;
    Produto *vetor_produtos = NULL;  // Struct apontando para vetor_produtos que inicia com Valor NULL

    do
    {       // Escolhas SubMenu Produtos
        printf("Sub-Menu Produtos\n");
        printf("[1] Exibir\n");
        printf("[2] Cadastrar\n");
        printf("[3] Atualizar\n");
        printf("[4] Excluir\n");
        printf("[5] Salvar\n");
        printf("[6] Ler\n");
        printf("[7] Voltar\n");
        printf("Escolha uma opcao:\n>  ");
        scanf("%d", &opc);
        getchar();
        system("cls||clear");

        switch(opc)
        {
        case 1:
            printf("Selecionado: Exibir\n");
            imprimirTabelaProdutos(prod, totalprod);    // Chamada da Funcao para Imprimir Tabela de Produtos
            system("pause");        // funcao de "pause" no sistema [ cmd ]
            system("cls||clear");       // funcao de "limpar/clear" no sistema [ cmd ]
            break;
        case 2:
            printf("Selecionado: Cadastrar\n");
            cadastrarProduto(prod, totalprod);      // Chamada da Funcao para Cadastrar os Produtos
            system("cls||clear");
            break;
        case 3:
            printf("Selecionado: Atualizar\n");
            atualizar_produtos(prod, totalprod);        // Chamada da Funcao para Atualizar os Produtos
            system("cls||clear");
            break;
        case 4:
            printf("Selecionado: Excluir\n");
            excluirProd(prod, totalprod);       // Chamada da Funcao para Excluir os Produtos
            system("cls||clear");
            break;
        case 5:
            printf("Selecionado: Salvar\n");
            salvarProdutos(prod, totalprod);        // Chamada da Funcao para Salvar os Produtos
            system("pause");
            system("cls||clear");
            break;
        case 6:
            printf("Selecionado: Ler\n");
            carregarProdutos(prod, totalprod);      // Chamada da Funcao Carregar os Produtos
            system("cls||clear");
            break;
        case 7:
            printf("Selecionado: Voltar\n");
            main();     // Chamada a [ Funcao Main ] Retorna a Main ( Menu Principal )
            system("cls||clear");
            break;
        default:
            printf("Opcao invalida!\n Tente novamente.\n");
            system("pause");        // Se nao for selecionado nenhuma das alternatia acima = DEFAULT
            system("cls||clear");
            break;
        }
    }
    while(opc < 0 || opc > 8);

    free(vetor_produtos); // Liberar a memória do vetor de produtos
}
