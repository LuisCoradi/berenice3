#include "02produtos.h"
#include "tipos.h"
#include "09vendas.h"

void menuvendas(Produto **prod, int *totalprod){

    int opc3;

    do{
        printf("SubMenu Vendas:\n");
        printf("[1] Realizar Venda\n");
        printf("[2] Relatorio de Vendas\n");
        printf("[3] Voltar\n");
        printf("Escolha uma opcao:\n>  ");
        scanf("%d", &opc3);
        getchar();
        system("cls||clear");

        switch(opc3){
            case 1:
                printf("Voce selecionou: Realizar Venda.\n");
                realizarVendas(prod, totalprod);
                system("cls||clear");
                break;
            case 2:
                printf("Voce selecionou: Relatorio de Vendas.\n");
                relatVenda(prod, totalprod);
                system("cls||clear");
                break;
            case 3:
                printf("Voce selecionou: Voltar\n");
                main();
                system("cls||clear");
            default:
                printf("Opcao invalida. Tente novamente.\n");
                system("cls||clear");
                break;
        }
    }while(opc3 != 1 || opc3 != 2 || opc3 != 3);

return 0;
}
