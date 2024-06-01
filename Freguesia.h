#ifndef FREGUESIA_H_INCLUDED
#define FREGUESIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *id_freguesia, *FREGUESIA;
}FREGUESIA;

//FREGUESIA *CriarFREGUESIA();
FREGUESIA *CriarFreguesiaDaLinha(char *linha);
void MostrarFreguesia(FREGUESIA *L);
void DestruirFreguesia(FREGUESIA *L);


#endif