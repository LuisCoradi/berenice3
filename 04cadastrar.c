#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "04cadastrar.h"

void salvarProdutos(Produto *vetor_produtos, int tam)
{
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }

    for (int i = 0; i < tam; i++)
    {
        fprintf(arquivo, "%i\n", vetor_produtos[i].codigoItem);
        fprintf(arquivo, "%s\n", vetor_produtos[i].nome);
        fprintf(arquivo, "%.2f\n", vetor_produtos[i].valor);
        fprintf(arquivo, "%d\n", vetor_produtos[i].quantidade);
    }

    fclose(arquivo);
}

void carregarProdutos(Produto **vetor_produtos, int *tam)
{
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Arquivo de produtos não encontrado.\n");
        return;
    }

    // Limpar o vetor de produtos atual
    free(*vetor_produtos);
    *vetor_produtos = NULL;
    *tam = 0;

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        Produto novo_produto;
        sscanf(linha, "%i", &novo_produto.codigoItem);
        fgets(linha, sizeof(linha), arquivo);
        strcpy(novo_produto.nome, linha);
        novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0';
        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%f", &novo_produto.valor);
        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%d", &novo_produto.quantidade);


        (*tam)++;
        *vetor_produtos = realloc(*vetor_produtos, (*tam) * sizeof(Produto));
        (*vetor_produtos)[(*tam) - 1] = novo_produto;
    }

    fclose(arquivo);
}


void cadastrarProduto(Produto **vetor_produtos, int *tam, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        // Incrementar o tamanho do vetor
        (*tam)++;

        // Realocar memória para o novo tamanho do vetor
        *vetor_produtos = realloc(*vetor_produtos, (*tam) * sizeof(Produto));

        // Preencher os dados do novo produto
        Produto novo_produto;
        printf("Digite o codigo do produto: ");
        scanf("%d", &novo_produto.codigoItem);
        getchar();
        printf("Digite o nome do produto: ");
        fgets(novo_produto.nome, sizeof(novo_produto.nome), stdin);
        novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0';  // Remover a quebra de linha do final
        printf("Digite o preco do produto: ");
        scanf("%f", &novo_produto.valor);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &novo_produto.quantidade);

        // Adicionar o novo produto ao final do vetor
        (*vetor_produtos)[(*tam) - 1] = novo_produto;

        // Salvar os produtos no arquivo
        salvarProdutos(*vetor_produtos, *tam);

        printf("Produto cadastrado com sucesso!\n");
    }
}
