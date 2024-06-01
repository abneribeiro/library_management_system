#include "Freguesia.h"

typedef struct NO_FREGUESIA {
    FREGUESIA *Info;
    struct NO_FREGUESIA *Prox;
} NO_FREGUESIA;

typedef struct {
    NO_FREGUESIA *Inicio;
    int NEL;
} LISTA_FREGUESIAS;


LISTA_FREGUESIAS* CriarListaFreguesias();
void AdicionarFreguesiaLista(LISTA_FREGUESIAS *lista, FREGUESIA *freguesia);
void MostrarFreguesias(LISTA_FREGUESIAS *lista);

void DestruirListaFreguesias(LISTA_FREGUESIAS *lista);