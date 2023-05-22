#include "02produtos.h"
#include "tipos.h"

void excluirProd(Produto **vetor_produtos, int *tam)
{
    int excCod;
    int indExc = -1;

    imprimirTabelaProdutos(vetor_produtos, tam);
    printf("Qual é o codigo que deseja excluir?");
    scanf("%d",&excCod);
    getchar();

    if(!verificaCodigo(excCod, *tam, *vetor_produtos))  // chama a funcao "verificaCodigo" para verificar se o codigo existe
    {
        printf("Codigo nao encontrado.");
        return;
    }
    for (int i = 0; i<*tam; i++)
    {
        if((*vetor_produtos)[i].codigoItem == excCod)    // Passa no endereco apontado vetor_produtos o valor de (codigoItem) para a Var "excCod"
        {
            indExc = i; // Passa o Endereco aonde esta localizado no vetor o Codigo do Item selecionado para a Var (indExc)
            break;
        }
    }
    for(int i=indExc; i< (*tam)-1; i++) // For faz com que o Indice jogue para Baixo o vetor selecionado
    {
        (*vetor_produtos)[i] = (*vetor_produtos)[i+1];
    }
    *vetor_produtos = realloc((*vetor_produtos), (*tam -1) * sizeof(Produto));
    (*tam)--;

    printf("\nProduto excluído com sucesso.\n");
    system("pause");
    return;
}

