#ifndef REQUISICAO_H_INCLUDED
#define REQUISICAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pessoa.h"
#include "Livro.h"
typedef struct
{
    //int ID_PESSOA;
    //int ID_LIVRO;
    int ID;
    PESSOA *Ptr_Req;
    LIVRO *Ptr_Livro;
    //DATA Data_Requisicao;
}REQUISICAO;

REQUISICAO *CriarRequisicao(int _id, PESSOA *P, LIVRO *L);
void MostrarRequisicao(REQUISICAO *P);
void DestruirRequisicao(REQUISICAO *P);

#endif // REQUISICAO_H_INCLUDED
