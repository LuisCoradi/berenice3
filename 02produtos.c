#include <stdio.h>
#include <stdlib.h>

#include "04cadastrar.h"

void submenu_produtos()
{
    int opc, tam = 0, quantidade;
    Produto *vetor_produtos = NULL;
    Produto *vetor_auxiliar = NULL; // Vetor auxiliar para armazenar temporariamente os produtos cadastrados
    int salvarAlteracoes = 0; // Variável de controle para indicar se as alterações devem ser salvas

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
            scanf("%d", &quantidade);

            vetor_auxiliar = cadastrarProduto(&vetor_auxiliar, &quantidade); // Armazenar temporariamente os produtos cadastrados
            salvarAlteracoes = 1; // Definir salvarAlteracoes como true
            system("cls||clear");
            break;
        case 3:
            printf("Selecionado: Atualizar\n");
            system("cls||clear");
            break;
        case 4:
            printf("Selecionado: Excluir\n");
            system("cls||clear");
            break;
        case 5:
            printf("Selecionado: Salvar\n");
            if (salvarAlteracoes)
            {
                // Concatenar o vetor auxiliar ao vetor de produtos
                vetor_produtos = concatenarProdutos(vetor_produtos, &tam, vetor_auxiliar, quantidade);
                salvarProdutos(vetor_produtos, tam);
                salvarAlteracoes = 0; // Resetar salvarAlteracoes para false após salvar as alterações
                printf("Alterações salvas com sucesso!\n");
                free(vetor_auxiliar); // Liberar a memória do vetor auxiliar
                vetor_auxiliar = NULL;
                quantidade = 0;
            }
            else
            {
                printf("Não há alterações a serem salvas.\n");
            }
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
