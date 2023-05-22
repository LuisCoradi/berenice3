#include "02produtos.h"
#include "tipos.h"

// Funcao Bool de Verificacao de Codigo Item - Retorno
// False = 0
// true = 1
bool verificaCodigo(int ptr_cod, int tam, Produto *vetor_produto)
{

    bool resultado = false; // Inicia o loop bool com o Resultado = False

    for(int i=0; i<tam; i++)
    {
        if(ptr_cod == vetor_produto[i].codigoItem)  // Esta checando se naquele determinado ponto do vetor que o codigoitem esta verificando se existe no codigo
        {
            resultado = true; // Apos fazer o LOOP BOOL corretamente o [resultado] passa a ser TRUE, entao a funcao funcionou com sucesso
            break;
        }
    }
    return resultado;   // Retorna a funcao BOOL que o resultado passou a ser verdadeiro, entao a funcao finalizou com exito
}

void salvarVendas(Produto **vetor_produtos, int *tam){  // Funcao para Salvar os Itens Vendidos em um Arquivo com Nome [ Ano, Mes, dia, hora, minuto e segundo ]
    time_t t = time(NULL);      // e um tipo de variavel da biblioteca "time.h" que define o horario, e data do ano
    struct tm *current_time = localtime(&t);    // struct de [tm] que aponta para valor de current_time = localtime(endereco de t)

    char filename[50];  // crio um variavel tipo char [filename] com tamanho 50
    sprintf(filename, "%04d-%02d-%02d_%02d-%02d-%02d.txt",      // printo a string para guardar no nome do arquivo na seguinte ordem [ Ano, Mes, dia, hora, minuto, segundo ]
            current_time->tm_year + 1900,   // Ano
            current_time->tm_mon + 1,   // Mes
            current_time->tm_mday,     // Dia
            current_time->tm_hour,  // Hora
            current_time->tm_min,   // Minuto
            current_time->tm_sec);  // Segundo

    FILE *salvarvenda_ = fopen(filename, "w");
    if (salvarvenda_ == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    }
        fprintf(salvarvenda_, "%d\n", *tam);
    for (int i = 0; i < *tam; i++)
    {
        fprintf(salvarvenda_, "%d\n", (*vetor_produtos)[i].codigoItem);
        fprintf(salvarvenda_, "%s\n", (*vetor_produtos)[i].nome);
        fprintf(salvarvenda_, "%.2f\n", (*vetor_produtos)[i].valor);
        fprintf(salvarvenda_, "%d\n", (*vetor_produtos)[i].quantidade);
        fprintf(salvarvenda_, "%d\n", (*vetor_produtos)[i].quant_vendida);

    }
    fclose(salvarvenda_);
    printf("Arquivo [%s\n] criado com sucesso:", filename);

    return 0;
}
