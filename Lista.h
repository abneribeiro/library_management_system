#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#include "Livro.h"

typedef struct no
{
    LIVRO  *Info;
    struct no *Prox;
}NO;

typedef struct
{
    int NEL;
    NO *Inicio;
}LISTA;


LISTA *CriarLista();
void AddInicio(LISTA *L, LIVRO *X);
void ShowLista(LISTA *L);
void DestruirLista(LISTA *L);
LIVRO *PesquisarLista(LISTA *L, char *_titulo);
int SizeLista(LISTA *L);


#endif // LISTA_H_INCLUDED
