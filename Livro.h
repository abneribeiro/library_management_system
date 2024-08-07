#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *TITULO, *AUTOR, *AREA , *ISBN;
    int ANO;
}LIVRO;

LIVRO *CriarLivro();
LIVRO *CriarLivroDaLinha(char *linha);
void MostrarLivro(LIVRO *L);
void DestruirLivro(LIVRO *L);



#endif // LIVRO_H_INCLUDED
