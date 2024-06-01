#include "Lconcelho.h"



LISTA_CONCELHOS* CriarListaConcelhos() {
    LISTA_CONCELHOS *lista = (LISTA_CONCELHOS*) malloc(sizeof(LISTA_CONCELHOS));
    lista->Inicio = NULL;
    lista->NEL = 0;
    return lista;
}

void AdicionarConcelhoLista(LISTA_CONCELHOS *lista, CONCELHO *concelho) {
    if (!lista) return;
    NO_CONCELHO *aux = (NO_CONCELHO *)malloc(sizeof(NO_CONCELHO));
    aux->Info = concelho;
    aux->Prox = lista->Inicio;
    lista->Inicio = aux;
    lista->NEL++;
}


void MostrarConcelhos(LISTA_CONCELHOS *lista) {
    NO_CONCELHO *aux = lista->Inicio;
    while (aux) {
        MostrarConcelho(aux->Info);
        aux = aux->Prox;
    }
}

void DestruirListaConcelhos(LISTA_CONCELHOS *lista) {
    NO_CONCELHO *aux = lista->Inicio;
    while (aux) {
        NO_CONCELHO *temp = aux;
        aux = aux->Prox;
        DestruirConcelho(temp->Info);
        free(temp);
    }
    free(lista);
}