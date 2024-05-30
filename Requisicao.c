#include "Requisicao.h"
#include "Pessoa.h"
#include "Livro.h"

REQUISICAO *CriarRequisicao(int requestId, PESSOA *requester, LIVRO *book)
{
    int REQUEST_PERIOD = 8;
    REQUISICAO *newRequest = (REQUISICAO *)malloc(sizeof(REQUISICAO));
    if (newRequest == NULL)
    {
        printf("Falha na alocação de memória para nova requisição.\n");
        return NULL;
    }

    newRequest->ID = requestId;
    newRequest->Ptr_Req = requester;
    newRequest->Ptr_Livro = book;

    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);

    newRequest->Data_Requisicao = currentTime;
    newRequest->Data_Vencimento = currentTime;
    newRequest->Data_Vencimento.tm_mday += REQUEST_PERIOD; // Add the request period to the current date

    // Normalize the date
    mktime(&newRequest->Data_Vencimento);

    return newRequest;

    return newRequest;
}

void MostrarRequisicao(REQUISICAO *R)
{
    char data_vencimento[20];
    if (strftime(data_vencimento, 20, "%d-%m-%Y", &(R->Data_Vencimento)) == 0)
    {
        printf("Failed to format Data_Vencimento\n");
    }

    char data_requisicao[20];
    if (strftime(data_requisicao, 20, "%d-%m-%Y", &(R->Data_Requisicao)) == 0)
    {
        printf("Failed to format Data_Requisicao\n");
    }

    printf("REQ ID = %d\n, Req: %s, Livro: %s, Data Vencimento: [%s], Data Requisicao: [%s],\n",
           R->ID, R->Ptr_Req->NOME, R->Ptr_Livro->TITULO, data_vencimento, data_requisicao);
}

// Fazer amanha as requisições e a parte de ficheiros para carregar as requisi

void DestruirRequisicao(REQUISICAO *R)
{
    free(R->Ptr_Livro);
    free(R->Ptr_Req);
    free(R);
}
