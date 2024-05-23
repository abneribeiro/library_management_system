#ifndef PLISTA_H_INCLUDED
#define PLISTA_H_INCLUDED
#include "Requisicao.h"


typedef struct no_req
{
    REQUISICAO *Info;
    struct no_req *Prox;
}NO_REQ;

typedef struct
{
    int NEL;
    NO_REQ *Inicio;
}PLISTA;


PLISTA *criarListaReq();
void AddInicioReq(PLISTA *L, REQUISICAO *X);
void ShowListaReq(PLISTA *L);
void DestruirListaReq(PLISTA *L);
REQUISICAO *PesquisarListaReq(PLISTA *L, int _id);


#endif