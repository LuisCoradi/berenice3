#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#include "02produtos.h"

typedef struct
{
    int codigoItem;
    char nome[100];
    float valor;
    int quantidade;
    int quant_vendida;
} Produto;

#endif // TIPOS_H_INCLUDED
