#include <stdio.h>
#include <stdlib.h>

#include "02produtos.h"

void exibirMenu(int opcao){
    int opc;
    do{
        printf("Menu:\n");
        printf("[1] Produtos\n");
        printf("[2] Vendas\n");
        printf("[3] Sair\n");
        printf("Escolha uma opcao:\n>  ");
        scanf("%d", &opcao);
        getchar();
        system("cls||clear");

        switch(opcao) {
            case 1:
                printf("Você escolheu a Opcao 1.\n");
                submenu_produtos(opc);
                system("cls||clear");
                break;
            case 2:
                printf("Você escolheu a Opcao 2.\n");
                // Faça algo relacionado à opção 2
                system("cls||clear");
                break;
            case 3:
                printf("Saindo...\n");
                system("cls||clear");
                exit(1);
            default:
                printf("Opcao invalida. Tente novamente.\n");
                system("cls||clear");
                break;
        }
    }while(opcao != 1 || opcao != 2 || opcao != 3);
}
