#include "02produtos.h"
#include "tipos.h"


void cadastrarProduto(Produto **vetor_produtos, int *tam)
{
    int quant, cod;
    printf("Quantos produtos deseja cadastrar?\n");
    scanf("%d", &quant);

    while(quant<0 || quant == 0){
        printf("Opcao Invalida, tente novamente: ");
        scanf("%d", &quant);
        setbuf(stdin, NULL);
    }
    Produto *novo_produto = realloc(*vetor_produtos, (*tam+quant) * sizeof(Produto)); // Realoca memoria para o vetor de produtos
    if(novo_produto == NULL){
        printf("Erro ao alocar a memoria");
        free(novo_produto);
        return;
    }

    *vetor_produtos = novo_produto;

    int aux = *tam;
    *tam = aux + quant;
     // loop pra cadastrar os produtos
    for (int i = aux; i < *tam; i++)
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &cod);
        getchar();
        //Verifica se o codigo ja existe
        while(verificaCodigo(cod, *tam, *vetor_produtos) == true){
            printf("\nCodigo Invalido, Tente Novamente\n");
            scanf("%d", &cod);
            getchar();

        }
        (*vetor_produtos)[i].codigoItem = cod;
        // Atribui cod a codigoItem


        printf("Digite o nome do produto: ");
        fgets((*vetor_produtos)[i].nome, sizeof((*vetor_produtos)[i].nome), stdin);
        (*vetor_produtos)[i].nome[strcspn((*vetor_produtos)[i].nome, "\n")] = '\0';
        printf("Digite o preco do produto: ");
        scanf("%f", &((*vetor_produtos)[i].valor));
        printf("Digite a quantidade do produto: ");
        scanf("%d", &((*vetor_produtos)[i].quantidade));
        // Esses printfs são usados para cadastrar


        (*vetor_produtos)[i].quant_vendida = 0;
        //Ao cadastrar um produto sua quantia vendida é inicializada nula/0 mesma coisa.
        printf("Produto cadastrado com sucesso!\n");
    }
}
