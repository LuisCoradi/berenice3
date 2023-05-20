#ifndef CADASTRAR_H_INCLUDED
#define CADASTRAR_H_INCLUDED

typedef struct
{
    int codigoItem;
    char nome[100];
    float valor;
    int quantidade;
} Produto;

void cadastrarProduto(Produto **vetor_produtos, int *tam, int quantidade);
void salvarProdutos(Produto *vetor_produtos, int tam);
void carregarProdutos(Produto **vetor_produtos, int *tam);

#endif // CADASTRAR_H_INCLUDED
