#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *NOME;
    int ID;
    char *DATA_NASCIMENTO;
    char *IDFRAGUESIA;
} PESSOA;

PESSOA *CriarPessoa();
PESSOA *CriarRequisitanteDaLinha(char *linha);
void MostrarPessoa(PESSOA *P);
void DestruirPessoa(PESSOA *P);

#endif // PESSOA_H_INCLUDED
