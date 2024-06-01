#include "Concelho.h"

typedef struct NO_CONCELHO {
    CONCELHO *Info;
    struct NO_CONCELHO *Prox;
} NO_CONCELHO;

typedef struct {
    NO_CONCELHO *Inicio;
    int NEL;
} LISTA_CONCELHOS;


LISTA_CONCELHOS* CriarListaConcelhos();
void AdicionarConcelhoLista(LISTA_CONCELHOS *lista, CONCELHO *concelho);
void MostrarConcelhos(LISTA_CONCELHOS *lista);
void DestruirListaConcelhos(LISTA_CONCELHOS *lista);