#include "RHashing.h"
#include "Pessoa.h"
#include "RLista.h"

RLISTA_CHAVES *CriarRListaCHAVES()
{
    RLISTA_CHAVES *R = (RLISTA_CHAVES *)malloc(sizeof(RLISTA_CHAVES));
    R->NEL = 0;
    R->Inicio = NULL;
    return R;
}

RNO_CHAVE *RAddCHAVE(RLISTA_CHAVES *L, char *key)
{
    if (!L)
        return NULL;
    RNO_CHAVE *aux = (RNO_CHAVE *)malloc(sizeof(RNO_CHAVE));
    aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(aux->KEY, key);
    aux->DADOS = CriarRLista();
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
    return aux;
}

RHASHING *CriarRHashing()
{
    RHASHING *RHas = (RHASHING *)malloc(sizeof(RHASHING));
    RHas->RLChaves = CriarRListaCHAVES();
    return RHas;
}

void DestruirRHashing(RHASHING *H)
{
    if (!H) return;
    RNO_CHAVE *Seguinte;
    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirRLista(P->DADOS);
        free(P->KEY);
        free(P);
        P = Seguinte;
    }
    free(H);
}

void AddRHashing(RHASHING *H, PESSOA *P)
{
    if (!H || !H->RLChaves)
        return;

    char key[2] = {P->NOME[0], '\0'};

    RNO_CHAVE *Key_colocar = FuncaoRHashing(H, key);
    if (!Key_colocar)
    {
        Key_colocar = RAddCHAVE(H->RLChaves, P->NOME);
    }
    AddRInicio(Key_colocar->DADOS, P);
}

void ShowRHashing(RHASHING *H)
{
    if (!H || !H->RLChaves)
        return;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    printf("KEY = %s\n", P->KEY);
    while (P)
    {
        printf("KEY = %s\n", P->KEY);
        ShowRLista(P->DADOS);
        P = P->Prox;
    }
}

RNO_CHAVE *FuncaoRHashing(RHASHING *H, char *key)
{
    if (!H || !H->RLChaves)
        return NULL;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (stricmp(P->KEY, key) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}
