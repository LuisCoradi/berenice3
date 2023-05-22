#include "02produtos.h"
#include "tipos.h"

void carregarProdutos(Produto **vetor_produtos, int *tam)
{

    // Limpar o vetor de produtos atual
    free(*vetor_produtos);
    *vetor_produtos = NULL;
    *tam = 0;

    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Arquivo de produtos não encontrado.\n");
        return;
    }

    fscanf(arquivo,"%d\n", &(*tam));

    *vetor_produtos = (Produto*) malloc(*tam * sizeof(Produto));
    if(*vetor_produtos == NULL){
        printf("Erro ao alocar memoria");
        return;
    }
    for (int i =0; i < *tam; i++){
        fscanf(arquivo, "%d\n", &(*vetor_produtos)[i].codigoItem);
        fgets((*vetor_produtos)[i].nome,sizeof((*vetor_produtos)[i].nome), arquivo);
        (*vetor_produtos)[i].nome[strcspn((*vetor_produtos)[i].nome, "\n")] = '\0';
        fscanf(arquivo, "%f\n", &(*vetor_produtos)[i].valor);
        fscanf(arquivo, "%d\n", &(*vetor_produtos)[i].quantidade);
        fscanf(arquivo, "%d\n", &(*vetor_produtos)[i].quant_vendida);

    }
    fclose(arquivo);
}
