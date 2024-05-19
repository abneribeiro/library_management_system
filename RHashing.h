#ifndef RHASHING_H_INCLUDED
#define RHASHING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RLista.h"
#include "Pessoa.h"

typedef struct rno_chave
{
    char *KEY; 
    RLISTA *DADOS;
    struct rno_chave *Prox;
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

RLISTA_CHAVES *CriarRListaCHAVES();
RNO_CHAVE *RAddCHAVE(RLISTA_CHAVES *L, char *key);
RHASHING *CriarRHashing();
void DestruirRHashing(RHASHING *H);
void AddRHashing(RHASHING *H, PESSOA *P);
void ShowRHashing(RHASHING *H);
RNO_CHAVE *FuncaoRHashing(RHASHING *H, char *key);


#endif // 
