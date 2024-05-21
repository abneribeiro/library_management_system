#include "RHashing.h"
#include "Pessoa.h"
#include "RLista.h"
#include <conio.h>

RLISTA_CHAVES *CriarRListaCHAVES()
{
    RLISTA_CHAVES *R = (RLISTA_CHAVES *)malloc(sizeof(RLISTA_CHAVES));
    R->NEL = 0;
    R->Inicio = NULL;
    return R;
}


void AddROrdenado(RLISTA *L, PESSOA *P)
{
    if (!L)
        return;

    RNO *novo = (RNO *)malloc(sizeof(RNO));
    novo->Info = P;
    novo->Prox = NULL;

    if (L->Inicio == NULL || strcmp(L->Inicio->Info->NOME, P->NOME) > 0)
    {
        // Inserir no início da lista
        novo->Prox = L->Inicio;
        L->Inicio = novo;
    }
    else
    {
        // Encontrar o nó anterior ao ponto de inserção
        RNO *current = L->Inicio;
        while (current->Prox != NULL && strcmp(current->Prox->Info->NOME, P->NOME) < 0)
        {
            current = current->Prox;
        }
        // Inserir após o nó atual
        novo->Prox = current->Prox;
        current->Prox = novo;
    }

    L->NEL++;
}


RNO_CHAVE *RAddCHAVE(RLISTA_CHAVES *L, char *key)
{
    if (!L)
        return NULL;
    RNO_CHAVE *aux = (RNO_CHAVE *)malloc(sizeof(RNO_CHAVE));
    aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(aux->KEY, key);
    aux->DADOS = CriarRLista();
    aux->Prox = NULL;

    // Inserir a chave na posição correta para manter a lista em ordem alfabética
    if (L->Inicio == NULL || strcmp(L->Inicio->KEY, key) > 0)
    {
        // Inserir no início da lista
        aux->Prox = L->Inicio;
        L->Inicio = aux;
    }
    else
    {
        // Encontrar o nó anterior ao ponto de inserção
        RNO_CHAVE *current = L->Inicio;
        while (current->Prox != NULL && strcmp(current->Prox->KEY, key) < 0)
        {
            current = current->Prox;
        }
        // Inserir após o nó atual
        aux->Prox = current->Prox;
        current->Prox = aux;
    }

    L->NEL++;
    return aux;
}


RHASHING *CriarRHashing()
{
    RHASHING *RHas = (RHASHING *)malloc(sizeof(RHASHING));
    RHas->RLChaves = CriarRListaCHAVES();
    return RHas;
}

void DestruirRHashing(RHASHING *H)
{
    if (!H)
        return;
    RNO_CHAVE *Seguinte;
    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirRLista(P->DADOS);
        free(P->KEY);
        free(P);
        P = Seguinte;
    }
    free(H);
}

void AddRHashing(RHASHING *H, PESSOA *P)
{
    if (!H || !H->RLChaves)
        return;

    char key[2] = {P->NOME[0], '\0'};

    RNO_CHAVE *Key_colocar = FuncaoRHashing(H, key);
    if (!Key_colocar)
    {
        Key_colocar = RAddCHAVE(H->RLChaves, key);
    }
    AddROrdenado(Key_colocar->DADOS, P);
}

int CompararChaves(const void *a, const void *b)
{
    RNO_CHAVE *chaveA = *(RNO_CHAVE **)a;
    RNO_CHAVE *chaveB = *(RNO_CHAVE **)b;
    return strcmp(chaveA->KEY, chaveB->KEY);
}

void ShowRHashing(RHASHING *H, int numToShow)
{
    if (!H || !H->RLChaves)
        return;

    int numKeys = H->RLChaves->NEL;
    RNO_CHAVE **array = (RNO_CHAVE **)malloc(numKeys * sizeof(RNO_CHAVE *));
    RNO_CHAVE *P = H->RLChaves->Inicio;

    for (int i = 0; i < numKeys; i++)
    {
        array[i] = P;
        P = P->Prox;
    }

    qsort(array, numKeys, sizeof(RNO_CHAVE *), CompararChaves);

    int count = 0;
    for(int i = 0; i < numKeys; i++)
    {
        printf("Chave: %s\n", array[i]->KEY);
        ShowRLista(array[i]->DADOS);
        count++;
        if ( count >= numToShow){
            printf(".Pressione qualquer tecla para continuar...\n");
            while (!_kbhit()) {} // Aguarda a pressão de uma tecla
            _getch(); // Limpa a tecla pressionada do buffer
            count = 0;
        }
    }
    free(array);
}

RNO_CHAVE *FuncaoRHashing(RHASHING *H, char *key)
{
    if (!H || !H->RLChaves)
        return NULL;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (stricmp(P->KEY, key) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}
