#include "Distrito.h"


typedef struct NO_DISTRITO {
    DISTRITO *Info;
    struct NO_DISTRITO *Prox;
} NO_DISTRITO;

typedef struct {
    NO_DISTRITO *Inicio;
    int NEL;
} LISTA_DISTRITOS;


LISTA_DISTRITOS* CriarListaDistritos();
void AdicionarDistritoLista(LISTA_DISTRITOS *lista, DISTRITO *distrito);
void MostrarDistritos(LISTA_DISTRITOS *lista);

void DestruirListaDistritos(LISTA_DISTRITOS *lista);