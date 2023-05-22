#include "02produtos.h"
#include "09vendas.h"

int main(){

    Produto *prod = NULL;
    int totalProd = 0;

    int opcao;

    do{
            // Escolha do Menu
        printf("Menu:\n");
        printf("[1] Produtos\n");
        printf("[2] Vendas\n");
        printf("[3] Sair\n");
        printf("Escolha uma opcao:\n>  ");
        scanf("%d", &opcao);
        getchar();
        system("cls||clear");

        switch(opcao){
            case 1:     // Escolha 1 : Produtos.
                printf("Voce selecionou: Produtos.\n");
                submenu_produtos(&prod, &totalProd);    // Chamada da Funcao SubMenu de Produtos
                system("cls||clear");
                break;
            case 2:     // Escolha 2 : Vendas.
                printf("Voce selecionou: Vendas.\n");
                menuvendas(&prod, &totalProd);          // Chamada da Funcao Menu de Vendas
                system("cls||clear");
                break;
            case 3:     // Escolha 3 : Sair do Programa [ Menu / Codigo ]
                printf("Voce selecionou: Sair\n");
                exit(1);            // Saida do Programa ( Exit [ Retorna 1 á Main ] )
                system("cls||clear");
            default:    // Nenhuma das Escolhas acima foi selecionada [ Default ]
                printf("Opcao invalida. Tente novamente.\n");
                system("cls||clear");
                break;
        }
    }while(opcao != 1 || opcao != 2 || opcao != 3);

return 0;
}
