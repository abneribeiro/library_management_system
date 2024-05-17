#ifndef RLISTA_H_INCLUDED
#define RLISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#include "Pessoa.h"

typedef struct rno
{
    PESSOA  *Info;
    struct rno *Prox;
}RNO;

typedef struct
{
    int NEL;
    RNO *Inicio;
}RLISTA;





#endif // RLISTA_H_INCLUDED
