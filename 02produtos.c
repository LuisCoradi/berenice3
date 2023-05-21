#include <stdio.h>
#include <stdlib.h>

#include "04cadastrar.h"

void submenu_produtos()
{
    int opc, tam = 0, quant, atualizar_prod;
    Produto *vetor_produtos = NULL;

    do
    {
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
            carregarProdutos(&vetor_produtos, &tam);
            imprimirTabelaProdutos(vetor_produtos, tam);
            system("pause");
            system("cls||clear");
            break;
        case 2:
            printf("Selecionado: Cadastrar\n");
            printf("Quantos produtos deseja cadastrar?\n");
            scanf("%d", &quant);
            cadastrarProduto(&vetor_produtos, &tam, quant);
            system("cls||clear");
            break;
        case 3:
            printf("Selecionado: Atualizar\n");
            atualizar_produtos(atualizar_prod);
            system("cls||clear");
            break;
        case 4:
            printf("Selecionado: Excluir\n");
            system("cls||clear");
            break;
        case 5:
            printf("Selecionado: Salvar\n");
            system("pause");
            system("cls||clear");
            break;
        case 6:
            printf("Selecionado: Ler\n");
            system("cls||clear");
            break;
        case 7:
            printf("Selecionado: Voltar\n");
            system("cls||clear");
            break;
        default:
            printf("Opcao invalida!\n Tente novamente.\n");
            system("pause");
            system("cls||clear");
            break;
        }
    }
    while(opc < 0 || opc > 8);

    free(vetor_produtos); // Liberar a memória do vetor de produtos
}
