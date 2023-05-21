#include <stdlib.h>
#include <stdio.h>

#include "03exibir.h"
#include "04cadastrar.h"
#include "05atualizar.h"

void atualizar_produtos(int atualizar_prod){

    int tam = 0, opc;
    Produto *vetor_produtos;

    carregarProdutos(&vetor_produtos, &tam);

    imprimirTabelaProdutos(&vetor_produtos,tam);
    printf("Digite o Codigo do Produto que deseja alterar.\n");
    scanf("%d", &atualizar_prod);
    getchar();

    if(atualizar_prod == vetor_produtos->codigoItem){
    // possibilitar a atualizaçao da quantidade e valor unitario
    // do produto encontrado, e uma confirmaçao da alteraçao exibindo o antes e depois
    }else{
    printf("O Produto nao foi Encontrado.\n");
    system("pause");
    system("cls||clear");
    submenu_produtos(opc);
    }
}
