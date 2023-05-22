#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

#include "tipos.h"

// funcoes
void submenu_produtos(Produto **, int *);
void imprimirTabelaProdutos(Produto **, int *);
void cadastrarProduto(Produto **, int *);
void salvarProdutos(Produto **, int *);
void carregarProdutos(Produto **, int *);
void atualizar_produtos(Produto **, int *);
void realizarVendas(Produto **, int *);
void salvarVendas(Produto **,int *);

#endif // 02PRODUTOS_H_INCLUDED
