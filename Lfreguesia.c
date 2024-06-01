#include "Lfreguesia.h"



LISTA_FREGUESIAS* CriarListaFreguesias() {
    LISTA_FREGUESIAS *lista = (LISTA_FREGUESIAS*) malloc(sizeof(LISTA_FREGUESIAS));
    lista->Inicio = NULL;
    lista->NEL = 0;
    return lista;
}

void AdicionarFreguesiaLista(LISTA_FREGUESIAS *lista, FREGUESIA *freguesia) {
    if (!lista) return;
    NO_FREGUESIA *aux = (NO_FREGUESIA *)malloc(sizeof(NO_FREGUESIA));
    aux->Info = freguesia;
    aux->Prox = lista->Inicio;
    lista->Inicio = aux;
    lista->NEL++;
}


void MostrarFreguesias(LISTA_FREGUESIAS *lista) {
    if (!lista) return;
    NO_FREGUESIA *P = lista->Inicio;
    while (P != NULL) {
        MostrarFreguesia(P->Info);
        P = P->Prox;
    }
}

void DestruirListaFreguesias(LISTA_FREGUESIAS *lista) {
    NO_FREGUESIA *aux = lista->Inicio;
    while (aux) {
        NO_FREGUESIA *temp = aux;
        aux = aux->Prox;
        DestruirFreguesia(temp->Info);
        free(temp);
    }
    free(lista);
}
