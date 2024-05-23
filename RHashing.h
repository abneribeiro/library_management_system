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
void ShowRHashing(RHASHING *H, int numToShow);
RNO_CHAVE *FuncaoRHashing(RHASHING *H, char *key);
void AddROrdenado(RLISTA *L, PESSOA *P);
int CompararChaves(const void *a, const void *b);
int mostCommonAge(RHASHING *H);
int countPeopleAboveAge(RHASHING *H, int age_limit);
int maxAge(RHASHING *H);
PESSOA *ProcurarRequisitanteRHASHING(RHASHING *H, char *nome);
void VerificarRequisitanteRHASHING(RHASHING *H, char *nome);
char *MostUsedSurnameRHASHING(RHASHING *H);
double averageAge(RHASHING *H);





#endif // 
