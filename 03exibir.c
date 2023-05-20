#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "03exibir.h"
#include "04cadastrar.h"


void imprimirTabelaProdutos(Produto *vetor_produtos, int tam)
{
    printf("|Item(Codigo)    Nome do Item       Valor(Unidade)    Estoque  |\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < tam; i++)
    {
        printf("|%6d         %-15s %.2f               %d       |\n",
               vetor_produtos[i].codigoItem, vetor_produtos[i].nome,
               vetor_produtos[i].valor, vetor_produtos[i].quantidade);
    }

    printf("------------------------------------------------------------\n");
}
