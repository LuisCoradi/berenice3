#include "02produtos.h"
#include "tipos.h"

void salvarProdutos(Produto **vetor_produtos, int *tam) // Funcao de Salvar os Produtos no Arquivo "produtos.txt" apos finalizar as vendas
{
    FILE *arquivo = fopen("produtos.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    fprintf(arquivo, "%d\n", *tam); // Escrevendo primeiramente a quantidade de Produtos que foi vendida no Arquivo
    for (int i = 0; i < *tam; i++)
    {
        fprintf(arquivo, "%d\n", (*vetor_produtos)[i].codigoItem);  // Escrevendo no arquivo o Codigo do Produto vendido
        fprintf(arquivo, "%s\n", (*vetor_produtos)[i].nome);    // Escrevendo no arquivo o Nome do produto vendido
        fprintf(arquivo, "%.2f\n", (*vetor_produtos)[i].valor);     // Escrevendo no arquivo o valor unitario do produto vendido
        fprintf(arquivo, "%d\n", (*vetor_produtos)[i].quantidade);      // Escrevendo no arquivo a quantidade que sobrou do produto apos realizar a venda e subtracao da quantidade vendida
        fprintf(arquivo, "%d\n", (*vetor_produtos)[i].quant_vendida);       // Escrevendo no arquivo a quantidade vendida do produto selecionado
    }
    fclose(arquivo);        // fecha o arquivo
}
