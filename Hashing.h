#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Livro.h"

typedef struct no_chave
{
    char *KEY; // Assim nao temos tamanho fixo!, Bem melhor!, mas depois ser� necess�rio fazer o free!
    LISTA *DADOS;
    struct no_chave *Prox;
}NO_CHAVE;

typedef struct
{
    int NEL;
    NO_CHAVE *Inicio;
}LISTA_CHAVES;

typedef struct
{
    LISTA_CHAVES *LChaves;
}HASHING;


HASHING *CriarHashing();
//--------------------------------------------------------
void DestruirHashing(HASHING *H);
//--------------------------------------------------------
void AddHashing(HASHING *H, LIVRO *L);
//--------------------------------------------------------
void ShowHashing(HASHING *H);
//--------------------------------------------------------
NO_CHAVE *FuncaoHashing(HASHING *H, LIVRO *L);

#endif // HASHING_H_INCLUDED
