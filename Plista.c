#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Requisicao.h"
#include "Plista.h"


PLISTA *criarListaReq()
{
    PLISTA *L = (PLISTA*)malloc(sizeof(PLISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddInicioReq(PLISTA *L, REQUISICAO *X)
{
    NO_REQ *N = (NO_REQ*)malloc(sizeof(NO_REQ));
    N->Info = X;
    N->Prox = L->Inicio;
    L->Inicio = N;
    L->NEL++;
}

void ShowListaReq(PLISTA *L)
{
    NO_REQ *P = L->Inicio;
    while(P)
    {
        MostrarRequisicao(P->Info);
        P = P->Prox;
    }
}

void DestruirListaReq(PLISTA *L)
{
    NO_REQ *P = L->Inicio;
    while(P)
    {
        NO_REQ *T = P->Prox;
        DestruirRequisicao(P->Info);
        free(P);
        P = T;
    }
    free(L);
}

REQUISICAO *PesquisarListaReq(PLISTA *L, int _id)
{
    NO_REQ *P = L->Inicio;
    while(P)
    {
        if(P->Info->ID == _id)
            return P->Info;
        P = P->Prox;
    }
    return NULL;
}