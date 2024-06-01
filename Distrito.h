#ifndef DISTRITO_H_INCLUDED
#define DISTRITO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *id_distrito, *distrito;
}DISTRITO;

//DISTRITO *CriarDISTRITO();
DISTRITO *CriarDistritoDaLinha(char *linha);
void MostrarDistrito(DISTRITO *L);
void DestruirDistrito(DISTRITO *L);


#endif // DISTRITO_H_INCLUDED
