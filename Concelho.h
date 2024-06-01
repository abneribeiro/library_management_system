#ifndef CONCELHO_H_INCLUDED
#define CONCELHO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *id_concelho, *concelho;
}CONCELHO;

//CONCELHO *CriarCONCELHO();
CONCELHO *CriarConcelhoDaLinha(char *linha);
void MostrarConcelho(CONCELHO *L);
void DestruirConcelho(CONCELHO *L);



#endif