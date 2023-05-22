#include "02produtos.h"
#include "tipos.h"
#include "09vendas.h"

void realizarVendas(Produto **vetor_produtos, int *tam)
{
    int codItem,cItemID,op,qntVenda;
    float vlrVista,vlrPrazo;
    bool loop=true;


    imprimirTabelaProdutos(vetor_produtos, tam);

    while(loop == true) {
        printf("\nCodigo do produto que deseja vender: ");
        scanf("%d", &codItem);
        getchar();


        if(!verificaCodigo(codItem, *tam, *vetor_produtos)) {
            printf("codigo nao encontrado. Digite um codigo valido.\n");
        } else {
            loop=false;
        }
    }

    for(int i=0; i< *tam; i++) {
        if(codItem == (*vetor_produtos)[i].codigoItem) {
            cItemID=i;
            break;
        }
    }

    loop=true;
    while(loop==true) {
        printf("\nQuantia de produtos que deseja vender: ");
        scanf("%d", &qntVenda);
        getchar();


        if((qntVenda>(*vetor_produtos)[cItemID].quantidade || qntVenda <= 0)) {
            printf("Opcao insuficiente ou Invalida, tente novamente: \n");

        } else {
            loop=false;
        }
    }

    vlrVista=qntVenda * (*vetor_produtos)[cItemID].valor;

    printf("\tQuantidade: %d \n", qntVenda);
    printf("\tValor unitario: R$ %.2f \n", (*vetor_produtos)[cItemID].valor);
    printf("\tValor liquido: R$ %.2f \n", vlrVista);
    printf("\n");

    loop=true;
    while(loop==true) {
        printf("\tDigite a forma de pagamento \n");
        printf("\t1-A Vista \n");
        printf("\t2-A Prazo \n");
        scanf("%d", &op);
        getchar();

        switch(op) {
        case 1:
            avista(vetor_produtos, tam, &vlrVista, &vlrPrazo);
            loop=false;
            break;
        case 2:
            aprazo(vetor_produtos, tam,&vlrVista, &vlrPrazo);
            loop=false;
            break;
        default:
            printf("Opcao Invalida, tente novamente: \n");
            break;
        }

        (*vetor_produtos)[cItemID].quant_vendida += qntVenda;
        (*vetor_produtos)[cItemID].quantidade -= qntVenda;
        salvarProdutos(vetor_produtos, tam);
        salvarVendas(vetor_produtos,tam);

    }
}

void avista(Produto **vetor_produtos, int *tam, float *vlrVista, float *vlrPrazo)
{
    int op;
    float vrPago,Troco;
    bool loop=true;


    if(*vlrVista<=50) {
        *vlrPrazo=*vlrVista*0.95;
        printf("\tDesconto liberado de %%5 \n");

    } else if (*vlrVista>50 && *vlrVista<100) {
        *vlrPrazo=*vlrVista*0.90;
        printf("\tDesconto liberado de 10%% \n");
    } else {
        *vlrPrazo=*vlrVista*0.82;
        printf("\tDesconto liberado de 18%% \n");
    }

    printf("\tValor final: R$ %.2f\n", *vlrPrazo);

    while(loop==true) {
        printf("\tVai ser necessario troco? \n");
        printf("\t1-Sim 2-Nao \n");
        scanf("%d", &op);
        getchar();
        switch(op) {
        case 1:
            while(loop==true) {
                printf("\tDigite o valor pago\n");
                scanf("%f", &vrPago);
                getchar();
                if(vrPago<*vlrPrazo || vrPago==0) {
                    printf("\tValor pago invalido tente novamente\n");
                } else {
                    Troco=vrPago-*vlrPrazo;
                    printf("\tCUPOM\n");
                    printf("\tValor Liquido: %.2f\n", *vlrVista);
                    printf("\tValor Final: %.2f\n", *vlrPrazo);
                    printf("\tTroco: %.2f\n", Troco);
                    system("pause");
                    loop=false;
                }
            }

            break;
        case 2:
            printf("\tCUPOM\n");
            printf("\tValor Liquido: %.2f\n", *vlrVista);
            printf("\tValor Final: %.2f\n", *vlrPrazo);
            loop=false;
            system("pause");
            break;
        default:
            break;

        }
    }
}
void aprazo(Produto **vetor_produtos, int *tam, float *vlrVista, float *vlrPrazo)
{
    bool loop=true;
    int parc1;
    float vlrParc1;
    printf("\tValor total R$ %0.2f \n", *vlrVista);
    printf("\tAte 3x 5%% de juros \n");
    printf("\tA cima de 3x 8 %% de juros \n");

    while(loop==true){
        printf("\tDigite a quantidade de parc1elas \n");
        scanf("%i", &parc1);
        getchar();

        if(parc1<1) {
            printf("\tQuantidade invalida \n");
        } else {
            if (parc1<=3) {
                vlrParc1=(*vlrVista/parc1)*1.05;
            } else {
                vlrParc1=(*vlrVista/parc1)*1.08;
            }
            *vlrPrazo=vlrParc1*parc1;
            printf("\tValor da parc1ela %0.2f \n", vlrParc1);
            printf("\tQuantidade de parcelas %i \n", parc1);
            printf("\tValor da venda: R$%0.2f \n", *vlrVista);
            printf("\tValor final R$%0.2f \n", *vlrPrazo);
            system("pause");
            loop=false;
        }
    }
}

void relatVenda(Produto **vetor_produtos, int *tam){
    for(int i=0; i < *tam; i++){
        printf("\nNome: %s\n", (*vetor_produtos)[i].nome);
        printf("Codigo do item: %d\n", (*vetor_produtos)[i].codigoItem);
        printf("Preco: %.2f\n", (*vetor_produtos)[i].valor);
        printf("estoque:%d\n", (*vetor_produtos)[i].quantidade);
        printf("Quantidade vendida:%d \n",(*vetor_produtos)[i].quant_vendida);
        printf("--------------------------");
        }
system("pause");
}
