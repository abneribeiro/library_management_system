
#include "Lista.h"

//--------------------------------------------------
/** \brief Permite alocar mem�ria para uma lista
 *
 * \return LISTA* : Retorna a lista alocada
 * \date 10/04/2024
 * \author Docentes de ED
 */
LISTA *CriarLista()
{
    LISTA *L = (LISTA *)malloc(sizeof(LISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

//--------------------------------------------------
void AddInicio(LISTA *L, LIVRO *X)
{
    if (!L) return;
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = X;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
}

//--------------------------------------------------
void ShowLista(LISTA *L)
{
    if (!L) return;
    //printf("NEL = %d\n", L->NEL);
    NO *P = L->Inicio;
    while (P != NULL)
    {
        MostrarPessoa(P->Info);
        P = P->Prox;
    }
}

//--------------------------------------------------
void DestruirLista(LISTA *L)
{
    //printf("Implementar <%s>\n", __FUNCTION__);
    if (!L) return;
    NO *prox;
    NO *atual = L->Inicio;
    while (atual)
    {
        prox = atual->Prox;
        DestruirPessoa(atual->Info);
        free (atual);
        atual = prox;
    }
    free(L);
}


LIVRO *PesquisarLista(LISTA *L, char *_titulo)
{
    printf("Implementar <%s>\n", __FUNCTION__);
    if (L == NULL) return NULL;
    NO *P = L->Inicio;
    while (P)
    {
        if (stricmp(P->Info->TITULO, _titulo) == 0)
            return P->Info;
        P = P->Prox;
    }
    return NULL;
}


int SizeLista(LISTA *L)
{
    if (!L) return -1;
    return L->NEL;
}
