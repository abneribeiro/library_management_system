#include "RLista.h"
#include "Pessoa.h"

RLISTA *CriarRLista()
{
    RLISTA *L = (RLISTA *)malloc(sizeof(RLISTA));
    if (!L) return NULL;
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddRInicio(RLISTA *L, PESSOA *P)
{
    if (!L) return;
    RNO *aux = (RNO *)malloc(sizeof(RNO));
    if (!aux) return;
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

void DestruirRLista(RLISTA *L)
{
    //printf("Implementar <%s>\n", __FUNCTION__);
    if (!L) return;
    RNO *prox;
    RNO *atual = L->Inicio;
    while (atual)
    {
        prox = atual->Prox;
        DestruirPessoa(atual->Info);
        free (atual);
        atual = prox;
    }
    free(L);
}

int SizeRLista(RLISTA *L)
{
    if (!L) return 0;
    return L->NEL;
}