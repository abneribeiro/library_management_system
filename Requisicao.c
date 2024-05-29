#include "Requisicao.h"
#define REQUEST_PERIOD 10 // Define the request period as a constant


REQUISICAO *CriarRequisicao(int requestId, PESSOA *requester, LIVRO *book)
{
    REQUISICAO *newRequest = (REQUISICAO *)malloc(sizeof(REQUISICAO));
    newRequest->ID = requestId;
    newRequest->Ptr_Req = requester;
    newRequest->Ptr_Livro = book;
    time_t t = time(NULL);
    newRequest->Data_Requisicao = *localtime(&t);
    newRequest->Data_Vencimento = *localtime(&t);
    newRequest->Data_Vencimento.tm_mday += REQUEST_PERIOD; // Add the request period to the current date
    return newRequest;
}

void MostrarRequisicao(REQUISICAO *R)
{
    char data_vencimento[20];
    strftime(data_vencimento, 20, "%d/%m/%Y", &(R->Data_Vencimento));

    char data_requisicao[20];
    strftime(data_requisicao, 20, "%d/%m/%Y", &(R->Data_Requisicao));

    char data_devolucao[20];
    strftime(data_devolucao, 20, "%d/%m/%Y", &(R->Data_Devolucao));

    printf("REQ ID = %d\n, Req: %s, Livro: %s, Data Vencimento: %s, Data Requisicao: %s, Data Devolucao: %s\n",
           R->ID, R->Ptr_Req->NOME, R->Ptr_Livro->TITULO, data_vencimento, data_requisicao, data_devolucao);
}

void DestruirRequisicao(REQUISICAO *R)
{
    free(R->Ptr_Livro);
    free(R->Ptr_Req);
    free(R);
}
