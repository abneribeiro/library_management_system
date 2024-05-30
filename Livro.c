#include "Livro.h"
#include "Biblioteca.h"
#include "Hashing.h"
#include "Uteis.h"

LIVRO *CriarLivro()
{
    char _titulo[100], _area[100], _autor[100], _isbn[100];
    int _ano;

    do
    {
        printf("Digite o titulo do livro: ");
        CLEAR_BUFFER;
        fscanf(stdin, "%99[^\n]", _titulo);
    } while (strlen(_titulo) == 0 || is_blank(_titulo));

    do
    {
        printf("Digite a area do livro: ");
        CLEAR_BUFFER;
        fscanf(stdin, "%99[^\n]", _area);
    } while (strlen(_area) == 0 || is_blank(_area));

    do
    {
        printf("Digite o autor do livro: ");
        CLEAR_BUFFER;
        fscanf(stdin, "%99[^\n]", _autor);
    } while (strlen(_autor) == 0 || is_blank(_autor));

  
    do
    {
        printf("Digite o ISBN do livro: ");
        CLEAR_BUFFER;
        fscanf(stdin, "%99[^\n]", _isbn);
        //adicionar verificação de ISBN
        
    } while (strlen(_isbn) == 0 || is_blank(_isbn) );

    printf("Digite o ano do livro: ");
    scanf("%d", &_ano);
    CLEAR_BUFFER;

    LIVRO *L = (LIVRO *)malloc(sizeof(LIVRO));

    str_to_upper(_titulo);
    L->TITULO = (char *)malloc((strlen(_titulo) + 1) * sizeof(char));
    strcpy(L->TITULO, _titulo);

    str_to_upper(_area);
    L->AREA = (char *)malloc((strlen(_area) + 1) * sizeof(char));
    strcpy(L->AREA, _area);

    str_to_upper(_autor);
    L->AUTOR = (char *)malloc((strlen(_autor) + 1) * sizeof(char));
    strcpy(L->AUTOR, _autor);

    str_to_upper(_isbn);
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
    char *token = strtok(linha, "\t");
    L->TITULO = strdup(token);

    token = strtok(NULL, "\t");
    L->AUTOR = strdup(token);
    token = strtok(NULL, "\t");
    L->AREA = strdup(token);

    token = strtok(NULL, "\t");
    L->ISBN = strdup(token);

    token = strtok(NULL, "\t");
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
