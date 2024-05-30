#include "hashrequisicoes.h"
#include "Plista.h"
#include "Requisicao.h"

PHASHING *CriarPHashing()
{
    PHASHING *PHas = (PHASHING *)malloc(sizeof(PHASHING));
    PHas->PLChaves = CriarPListaCHAVES();
    return PHas;
}

PLISTA_CHAVES *CriarPListaCHAVES()
{

    PLISTA_CHAVES *L = (PLISTA_CHAVES *)malloc(sizeof(PLISTA_CHAVES));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

PNO_CHAVE *AddPCHAVE(PLISTA_CHAVES *L, char *key)
{

    if (!L)
        return NULL;
    PNO_CHAVE *aux = (PNO_CHAVE *)malloc(sizeof(PNO_CHAVE));
    aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(aux->KEY, key);
    aux->DADOS = criarListaReq();
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
    return aux;
}

PNO_CHAVE *FuncaoPHashing(PHASHING *H, REQUISICAO *R)
{
    if (!H || !H->PLChaves)
        return NULL;

    PNO_CHAVE *P = H->PLChaves->Inicio;
    while (P)
    {
        if (stricmp(P->KEY, R->Ptr_Livro->AREA) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}

void AddPHashing(PHASHING *H, REQUISICAO *R)
{
    if (!H || !H->PLChaves)
        return;

    PNO_CHAVE *Key_colocar = FuncaoPHashing(H, R);
    if (!Key_colocar)
    {
        Key_colocar = AddPCHAVE(H->PLChaves, R->Ptr_Livro->AREA);
    }
    AddInicioReq(Key_colocar->DADOS, R);
}

void ShowPHashing(PHASHING *H)
{
    if (!H || !H->PLChaves)
        return;
    PNO_CHAVE *P = H->PLChaves->Inicio;
    while (P)
    {
        printf("Key: %s\n", P->KEY);
        ShowListaReq(P->DADOS);
        P = P->Prox;
    }
}

void ListarRequisitantesComLivros(PHASHING *H)
{
    if (!H || !H->PLChaves)
        return;

    PNO_CHAVE *P = H->PLChaves->Inicio;
    while (P)
    {
        PLISTA *listaRequisicoes = P->DADOS;
        NO_REQ *noRequisicao = listaRequisicoes->Inicio;
        while (noRequisicao)
        {
            REQUISICAO *requisicao = noRequisicao->Info;
            PESSOA *requisitante = requisicao->Ptr_Req;
            LIVRO *livro = requisicao->Ptr_Livro;
            printf("Requisitante: %s, Livro: %s\n", requisitante->NOME, livro->TITULO);
            noRequisicao = noRequisicao->Prox;
        }
        P = P->Prox;
    }
}

void DestruirPHashing(PHASHING *H)
{
    if (!H)
        return;
    PNO_CHAVE *Seguinte;
    PNO_CHAVE *P = H->PLChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirListaReq(P->DADOS);
        free(P);
        P = Seguinte;
    }
    free(H->PLChaves);
    free(H);
}