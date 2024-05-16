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

LIVRO *CriarLivro(char *_titulo, char  *_area, char *_autor, char *_isbn, int _ano);
void MostrarLivro(LIVRO *P);
void DestruirLivro(LIVRO *P);


#endif // LIVRO_H_INCLUDED
