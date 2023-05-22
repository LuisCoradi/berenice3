#include "02produtos.h"
#include "tipos.h"

void atualizar_produtos(Produto **vetor_produtos, int *tam)
{
    int atualizar_prod;
    imprimirTabelaProdutos(vetor_produtos, tam);

    printf("Digite o Codigo do Produto que deseja alterar.\n");
    scanf("%d", &atualizar_prod);
    getchar();

    int produto_encontrado = 0;
    for (int i = 0; i < *tam; i++)
    {
        if (((*vetor_produtos)[i].codigoItem) == atualizar_prod)
        {
            printf("Produto encontrado:\n");
            printf("Codigo: %d\n", (*vetor_produtos)[i].codigoItem);
            printf("Nome: %s\n", (*vetor_produtos)[i].nome);
            printf("Valor: %.2f\n", (*vetor_produtos)[i].valor);
            printf("Quantidade: %d\n", (*vetor_produtos)[i].quantidade);

            // Possibilitar a atualização da quantidade e valor unitário do produto

            printf("Digite a nova quantidade: ");
            scanf("%d", &(*vetor_produtos)[i].quantidade);
            getchar();
            while((*vetor_produtos)[i].quantidade < 0)
            {
                printf("Quantidade invalida! Digite uma Quantidade valida\n");
                scanf("%d", &(*vetor_produtos)[i].quantidade);
                getchar();
            }

            printf("Digite o novo valor: ");
            scanf("%f", &(*vetor_produtos)[i].valor);
            getchar();
            while((*vetor_produtos)[i].valor <= 0)
            {
                printf("Valor invalido! Digite um Valor Valido\n");
                scanf("%f", &(*vetor_produtos)[i].valor);
                getchar();
            }

            produto_encontrado = 1;
            break;
        }
    }

    if (produto_encontrado)
    {

        printf("Produto atualizado com sucesso!\n");
        system("pause");
        system("cls||clear");


    }
    else
    {

        printf("O Produto nao foi Encontrado.\n");
        system("pause");
        system("cls||clear");
        submenu_produtos(vetor_produtos, tam);


    }
}
