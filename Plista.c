#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Requisicao.h"
#include "Plista.h"

PLISTA *criarListaReq()
{
    PLISTA *L = (PLISTA *)malloc(sizeof(PLISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddInicioReq(PLISTA *L, REQUISICAO *X)
{
    NO_REQ *N = (NO_REQ *)malloc(sizeof(NO_REQ));
    N->Info = X;
    N->Prox = L->Inicio;
    L->Inicio = N;
    L->NEL++;
}

void ShowListaReq(PLISTA *L)
{
    NO_REQ *P = L->Inicio;
    while (P)
    {
        MostrarRequisicao(P->Info);
        P = P->Prox;
    }
}

void DestruirListaReq(PLISTA *L)
{
    NO_REQ *P = L->Inicio;
    while (P)
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
    while (P)
    {
        if (P->Info->ID == _id)
            return P->Info;
        P = P->Prox;
    }
    return NULL;
}

typedef struct
{
    LIVRO *book;
    int freq;
} BOOK_FREQ;

BOOK_FREQ *findMostRequestedBook(PLISTA *L)
{
    BOOK_FREQ *bookFreqList = NULL;
    int bookFreqListSize = 0;
    NO_REQ *P = L->Inicio;

    while (P)
    {
        int found = 0;
        for (int i = 0; i < bookFreqListSize; i++)
        {
            if (strcmp(bookFreqList[i].book->ISBN, P->Info->Ptr_Livro->ISBN) == 0)
            {
                bookFreqList[i].freq++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            bookFreqList = (BOOK_FREQ *)realloc(bookFreqList, sizeof(BOOK_FREQ) * (bookFreqListSize + 1));
            bookFreqList[bookFreqListSize].book = P->Info->Ptr_Livro;
            bookFreqList[bookFreqListSize].freq = 1;
            bookFreqListSize++;
        }

        P = P->Prox;
    }

    BOOK_FREQ *mostRequestedBook = NULL;  
    for (int i = 0; i < bookFreqListSize; i++)
    {
        if (mostRequestedBook == NULL || bookFreqList[i].freq > mostRequestedBook->freq)
        {
            mostRequestedBook = &bookFreqList[i];
        }
    }

    free(bookFreqList);
    return mostRequestedBook;
}