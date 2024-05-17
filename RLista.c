#include "RLista.h"
#include "Pessoa.h"

RLISTA *CriarRLista()
{
    RLISTA *L = (RLISTA *)malloc(sizeof(RLISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddInicio(RLISTA *L, PESSOA *P)
{
    if (!L) return;
    RNO *aux = (RNO *)malloc(sizeof(RNO));
    aux->Info = P;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
}

void ShowRLista(RLISTA *L)
{
    if (!L) return;
    RNO *P = L->Inicio;
    while (P != NULL)
    {
        MostrarPessoa(P->Info);
        P = P->Prox;
    }
}