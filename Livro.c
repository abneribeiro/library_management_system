#include "Livro.h"
#include "Biblioteca.h"

LIVRO *CriarLivro(char *_titulo, char *_area, char *_autor, char *_isbn, int _ano)
{
    LIVRO *L = (LIVRO *)malloc(sizeof(LIVRO));
    L->TITULO = (char *)malloc((strlen(_titulo) + 1) * sizeof(char));
    strcpy(L->TITULO, _titulo);

    L->AREA = (char *)malloc((strlen(_area) + 1) * sizeof(char));
    strcpy(L->AREA, _area);

    L->AUTOR = (char *)malloc((strlen(_autor) + 1) * sizeof(char));
    strcpy(L->AUTOR, _autor);

    L->ISBN = (char *)malloc((strlen(_isbn) + 1) * sizeof(char));
    strcpy(L->ISBN, _isbn);
    L->ANO = _ano;
    return L;
}

LIVRO *CriarLivroDaLinha(char *linha)
{
    LIVRO *L = (LIVRO *)malloc(sizeof(LIVRO));
    if (L == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // Assuming the line is in the format: "Title,Author,ISBN"
    char *token = strtok(linha, ";");
    L->TITULO = strdup(token);

    token = strtok(NULL, ";");
    L->AUTOR = strdup(token);
    token = strtok(NULL, ";");
    L->AREA = strdup(token);

    token = strtok(NULL, ";");
    L->ISBN = strdup(token);

    token = strtok(NULL, ";");
    L->ANO = atoi(token);

    return L;
}



void MostrarLivro(LIVRO *L)
{
    printf("\tTitulo: %s | Autor: [%s] | Area: [%s] | ISBN: [%s], Ano: [%d] \n", L->TITULO, L->AUTOR, L->AREA, L->ISBN, L->ANO);
}

void DestruirLivro(LIVRO *L)
{
    free(L->TITULO);
    free(L->AUTOR);
    free(L->AREA);
    free(L->ISBN);
    free(L);
}
