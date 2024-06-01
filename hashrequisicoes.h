#ifndef HASHREQUISICOES_H_INCLUDED
#define HASHREQUISICOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Plista.h"
#include "Requisicao.h"

typedef struct pno_chave
{
    char *KEY;
    PLISTA *DADOS;
    struct pno_chave *Prox;
} PNO_CHAVE;

typedef struct
{
    int NEL;
    PNO_CHAVE *Inicio;
} PLISTA_CHAVES;

typedef struct
{
    PLISTA_CHAVES *PLChaves;
} PHASHING;


PHASHING *CriarPHashing();
PLISTA_CHAVES *CriarPListaCHAVES();
PNO_CHAVE *AddPCHAVE(PLISTA_CHAVES *L, char *key);
PNO_CHAVE *FuncaoPHashing(PHASHING *H, REQUISICAO *R);
void AddPHashing(PHASHING *H, REQUISICAO *R);
void ShowPHashing(PHASHING *H);
void ListarRequisitantesComLivros(PHASHING *H);
void ReturnBook(PHASHING *H, int requesterId, char* isbn);
void ListOverdueBooks(PHASHING *H);

void DestruirPHashing(PHASHING *H);

PLISTA_CHAVES *CriarPListaCHAVES();
PNO_CHAVE *AddPCHAVE(PLISTA_CHAVES *L, char *key);



#endif // PHASHING_H_INCLUDED
