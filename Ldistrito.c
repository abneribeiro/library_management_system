#include "Ldistrito.h"

LISTA_DISTRITOS *CriarListaDistritos()
{
    LISTA_DISTRITOS *lista = (LISTA_DISTRITOS *)malloc(sizeof(LISTA_DISTRITOS));
    lista->Inicio = NULL;
    lista->NEL = 0;
    return lista;
}

void AdicionarDistritoLista(LISTA_DISTRITOS *lista, DISTRITO *distrito)
{
    if (!lista)
        return;
    NO_DISTRITO *aux = (NO_DISTRITO *)malloc(sizeof(NO_DISTRITO));
    aux->Info = distrito;
    aux->Prox = lista->Inicio;
    lista->Inicio = aux;
    lista->NEL++;
}


void MostrarDistritos(LISTA_DISTRITOS *lista)
{
    if (!lista)
        return;
    NO_DISTRITO *P = lista->Inicio;
    while (P != NULL)
    {
        MostrarDistrito(P->Info);
        P = P->Prox;
    }
}