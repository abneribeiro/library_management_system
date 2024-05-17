#ifndef RHASHING_H_INCLUDED
#define RHASHING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RLista.h"


typedef struct rno_chave
{
    char *KEY; 
    RLISTA *DADOS;
    struct no_chave *Prox;
}RNO_CHAVE;

typedef struct
{
    int NEL;
    RNO_CHAVE *Inicio;
}RLISTA_CHAVES;

typedef struct
{
    RLISTA_CHAVES *RLChaves;
}RHASHING;



#endif // 
