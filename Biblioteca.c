#include <stdio.h>
#include "Biblioteca.h"
#include "Lista.h"
#include "Livro.h"
#include "Pessoa.h"
#include "RLista.h"
#include "RHashing.h"
#include "Plista.h"
#include "hashrequisicoes.h"
#include "Requisicao.h"
#include "Freguesia.h"
#include "Concelho.h"
#include "Distrito.h"

/** \brief Aloca Memoria para uma Biblioteca
 *
 * \param _nome char* : Nome da Biblioteca
 * \param _logs char* : Ficheiro dos Logs
 * \return BIBLIOTECA* : Retorna o ponteiro para a biblioteca
 * \author Docentes & Alunos
 * \date   11/04/2024
 *
 */

BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs)
{
    BIBLIOTECA *Bib = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    Bib->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(Bib->NOME, _nome);
    strcpy(Bib->FICHEIRO_LOGS, _logs);
    Bib->HLivros = CriarHashing();
    Bib->HRequisitantes = CriarRHashing();
    Bib->LRequi = CriarPHashing();
    Bib->LFreguesias = CriarListaFreguesias();
    Bib->LConcelhos = CriarListaConcelhos();
    Bib->LDistritos = CriarListaDistritos();

    return Bib;
}

void LerLivros(BIBLIOTECA *B, char *filename)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");

    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file))
    {
        LIVRO *L = CriarLivroDaLinha(linha);
        if (L != NULL)
        {
            AddLivroBiblioteca(B, L);
        }
    }

    fclose(file);
}

void LerRequisitantes(BIBLIOTECA *B, char *filename)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
    }

    char linhar[256];
    while (fgets(linhar, sizeof(linhar), file))
    {
        PESSOA *R = CriarRequisitanteDaLinha(linhar);
        if (R != NULL)
        {
            AddRequisitanteBiblioteca(B, R);
        }
    }

    fclose(file);
}

void LerConcelhos(BIBLIOTECA *B, char *filename)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");

    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file))
    {
        CONCELHO *C = CriarConcelhoDaLinha(linha);
        if (C != NULL)
        {
            AdicionarConcelhoLista(B->LConcelhos, C);
        }
    }

    fclose(file);
}

void LerDistritos(BIBLIOTECA *B, char *filename)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");

    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file))
    {
        DISTRITO *D = CriarDistritoDaLinha(linha);
        if (D != NULL)
        {
            AdicionarDistritoLista(B->LDistritos, D);
        }
    }

    fclose(file);
}

void LerFreguesias(BIBLIOTECA *B, char *filename)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");

    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file))
    {
        FREGUESIA *F = CriarFreguesiaDaLinha(linha);
        if (F != NULL)
        {
            AdicionarFreguesiaLista(B->LFreguesias, F);
        }
    }

    fclose(file);
}

// DESElVOLVER AS FUNCOES ABAIXO
void RequestBook(BIBLIOTECA *B, char *isbn, int requestId)
{
    // Check if the book exists
    LIVRO *book = VerificarLivroPorISBN(B, isbn);
    if (book == NULL)
    {
        printf("Livro com ISBN %s não encontrado.\n", isbn);
        return;
    }

    // // Check if the requester exists
    PESSOA *requester = FindRequesterByID(B, requestId);
    if (requester == NULL)
    {
        printf("Requisitante com o ID %d não foi encontrado.\n", requestId);
        return;
    }

    REQUISICAO *newRequest = CriarRequisicao(requestId, requester, book);

    // Add the book to the requester's list of requested books
    AddPHashing(B->LRequi, newRequest);
    printf("Livro %s foi requisitado com sucesso.\n", book->TITULO);
}

REQUISICAO *CriarRequisicaoDaLinha(char *linha, BIBLIOTECA *B)
{

    REQUISICAO *R = (REQUISICAO *)malloc(sizeof(REQUISICAO));
    FILE *F_Logs = fopen("logs.txt", "a");

    // ID;IDREQ;IDLIVRO;DATA_VENC;DATA_REQ;DATA_DEV
    char *token = strtok(linha, "\t");

    if (FindRequesterByID(B, atoi(token)) == NULL)
    {
        printf("Erro ID: %s\n", token);
        free(R);
        return NULL;
    }

    R->ID = atoi(token);
    R->Ptr_Req = FindRequesterByID(B, atoi(token));

    token = strtok(NULL, "\t");
    if (VerificarLivroPorISBN(B, token) == NULL)
    {
        printf("Erro ISBN: %s\n", token);
        free(R);
        return NULL;
    }
    R->Ptr_Livro = VerificarLivroPorISBN(B, token);

    int day, month, year;
    token = strtok(NULL, "\t");
    sscanf(token, "%d-%d-%d", &day, &month, &year);
    R->Data_Vencimento.tm_mday = day;
    R->Data_Vencimento.tm_mon = month - 1;
    R->Data_Vencimento.tm_year = year - 1900;

    token = strtok(NULL, "\t");
    sscanf(token, "%d-%d-%d", &day, &month, &year);
    R->Data_Requisicao.tm_mday = day;
    R->Data_Requisicao.tm_mon = month - 1;
    R->Data_Requisicao.tm_year = year - 1900;

    fclose(F_Logs);
    return R;
}

void AddRequisicacoBiblioteca(BIBLIOTECA *B, REQUISICAO *R)
{
    // Open the log file
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Create a new request node
    NO_REQ *newReq = (NO_REQ *)malloc(sizeof(NO_REQ));
    newReq->Info = R;
    newReq->Prox = NULL;

    PNO_CHAVE *atual = FuncaoPHashing(B->LRequi, R);

    if (atual == NULL)
    {
        atual = (PNO_CHAVE *)malloc(sizeof(PNO_CHAVE));
        atual->KEY = strdup(R->Ptr_Livro->AREA);
        atual->DADOS = (PLISTA *)malloc(sizeof(PLISTA));
        atual->DADOS->NEL = 0;
        atual->DADOS->Inicio = NULL;
        atual->Prox = B->LRequi->PLChaves->Inicio;
        B->LRequi->PLChaves->Inicio = atual;
        B->LRequi->PLChaves->NEL++;
    }

    newReq->Prox = atual->DADOS->Inicio;
    atual->DADOS->Inicio = newReq;
    atual->DADOS->NEL++;

    // Close the log file
    fclose(F_Logs);
}

void LerRequisicoes(BIBLIOTECA *B, char *filename)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    fclose(F_Logs);

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file))
    {
        REQUISICAO *R = CriarRequisicaoDaLinha(linha, B);
        if (R != NULL)
        {
            AddRequisicacoBiblioteca(B, R);
        }
    }

    fclose(file);
}

void MostrarPessoasSemRequisicoes(BIBLIOTECA *B)
{
    // Iterate over all keys in the person hash table
    RNO_CHAVE *atual = B->HRequisitantes->RLChaves->Inicio;
    while (atual != NULL)
    {
        // Iterate over all persons in the current key
        RNO *currentPerson = atual->DADOS->Inicio;
        while (currentPerson != NULL)
        {
            PESSOA *pessoa = currentPerson->Info;

            int found = 0;

            // Iterate over all keys in the requests hash table
            PNO_CHAVE *P = B->LRequi->PLChaves->Inicio;
            while (P)
            {
                // Iterate over the requests in the list
                NO_REQ *noRequisicao = P->DADOS->Inicio;
                while (noRequisicao)
                {
                    REQUISICAO *requisicao = noRequisicao->Info;
                    // If the request belongs to the person, set found to 1
                    if (requisicao->Ptr_Req == pessoa)
                    {
                        found = 1;
                        break;
                    }
                    noRequisicao = noRequisicao->Prox;
                }
                if (found)
                {
                    break;
                }
                P = P->Prox;
            }

            // If no request was found for the person, print the person
            if (!found)
            {
                printf("Pessoa %s nunca fez uma requisicao\n", pessoa->NOME);
            }

            currentPerson = currentPerson->Prox;
        }
        atual = atual->Prox;
    }
}

LIVRO *LivroMaisRequisitado(BIBLIOTECA *B)
{
    // Create a map to store the count of requests for each book
    int *bookCount = malloc(B->HRequisitantes->RLChaves->NEL * sizeof(int));
    LIVRO **books = malloc(B->HRequisitantes->RLChaves->NEL * sizeof(LIVRO *));
    int numBooks = 0;

    for (int i = 0; i < B->HRequisitantes->RLChaves->NEL; i++)
    {
        bookCount[i] = 0;
        books[i] = NULL;
    }

    // Iterate over all keys in the requests hash table
    PNO_CHAVE *P = B->LRequi->PLChaves->Inicio;
    while (P)
    {
        // Iterate over the requests in the list
        NO_REQ *noRequisicao = P->DADOS->Inicio;
        while (noRequisicao)
        {
            REQUISICAO *requisicao = noRequisicao->Info;
            LIVRO *book = requisicao->Ptr_Livro;

            // Find the book in the books array
            int i;
            for (i = 0; i < numBooks; i++)
            {
                if (books[i] == book)
                {
                    break;
                }
            }

            // If the book was not found in the books array, add it
            if (i == numBooks)
            {
                books[numBooks] = book;
                numBooks++;
            }

            // Increment the count for the book
            bookCount[i]++;

            noRequisicao = noRequisicao->Prox;
        }
        P = P->Prox;
    }

    // Find the book with the highest count
    int maxCount = 0;
    LIVRO *mostRequestedBook = NULL;
    for (int i = 0; i < numBooks; i++)
    {
        if (bookCount[i] > maxCount)
        {
            maxCount = bookCount[i];
            mostRequestedBook = books[i];
        }
    }

    free(bookCount);
    free(books);

    return mostRequestedBook;
}

char *AreaMaisRequisitada(BIBLIOTECA *B)
{
    // Create a map to store the count of requests for each area
    int *areaCount = malloc(B->HRequisitantes->RLChaves->NEL * sizeof(int));
    char **areas = malloc(B->HRequisitantes->RLChaves->NEL * sizeof(char *));
    int numAreas = 0;

    for (int i = 0; i < B->HRequisitantes->RLChaves->NEL; i++)
    {
        areaCount[i] = 0;
        areas[i] = NULL;
    }

    // Iterate over all keys in the requests hash table
    PNO_CHAVE *P = B->LRequi->PLChaves->Inicio;
    while (P)
    {
        // Iterate over the requests in the list
        NO_REQ *noRequisicao = P->DADOS->Inicio;
        while (noRequisicao)
        {
            REQUISICAO *requisicao = noRequisicao->Info;
            LIVRO *book = requisicao->Ptr_Livro;
            char *area = book->AREA; // Assuming each book has an 'area' field

            // Find the area in the areas array
            int i;
            for (i = 0; i < numAreas; i++)
            {
                if (strcmp(areas[i], area) == 0)
                {
                    break;
                }
            }

            // If the area was not found in the areas array, add it
            if (i == numAreas)
            {
                areas[numAreas] = area;
                numAreas++;
            }

            // Increment the count for the area
            areaCount[i]++;

            noRequisicao = noRequisicao->Prox;
        }
        P = P->Prox;
    }

    // Find the area with the highest count
    int maxCount = 0;
    char *mostRequestedArea = NULL;
    for (int i = 0; i < numAreas; i++)
    {
        if (areaCount[i] > maxCount)
        {
            maxCount = areaCount[i];
            mostRequestedArea = areas[i];
        }
    }

    free(areaCount);
    free(areas);

    return mostRequestedArea;
}

int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    LerLivros(B, "import/livros.txt");
    LerRequisitantes(B, "import/requisitantes.txt");
    LerRequisicoes(B, "import/requisicoes.txt");
    LerFreguesias(B, "import/freguesias.txt");
    LerDistritos(B, "import/distritos.txt");
    // LerConcelhos(B, "import/concelhos.txt");

    fclose(F_Logs);
    return EXIT_SUCCESS;
}

void SaveFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    
    SaveLivros(B, "import/livros.txt");
    SaveRequisitantes(B, "import/requisitantes.txt");
    SaveRequisicoes(B, "import/requisicoes.txt");

    fclose(F_Logs);
}

void AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // criar um novo no para o livro
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = L;
    aux->Prox = NULL;

    // cria um novo no chave se nao existir
    NO_CHAVE *atual = FuncaoHashing(B->HLivros, L);

    if (atual == NULL)
    {
        atual = (NO_CHAVE *)malloc(sizeof(NO_CHAVE));
        atual->KEY = strdup(L->AREA);
        atual->DADOS = (LISTA *)malloc(sizeof(LISTA));
        atual->DADOS->NEL = 0;
        atual->DADOS->Inicio = NULL;
        atual->Prox = B->HLivros->LChaves->Inicio;
        B->HLivros->LChaves->Inicio = atual;
        B->HLivros->LChaves->NEL++;
    }

    aux->Prox = atual->DADOS->Inicio;
    atual->DADOS->Inicio = aux;
    atual->DADOS->NEL++;

    fclose(F_Logs);
}

void AddRequisitanteBiblioteca(BIBLIOTECA *B, PESSOA *P)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    RNO *aux = (RNO *)malloc(sizeof(RNO));
    aux->Info = P;
    aux->Prox = NULL;

    // cria um novo no chave se nao existir
    RNO_CHAVE *atual = FuncaoRHashing(B->HRequisitantes, P->NOME);

    if (atual == NULL)
    {
        atual = (RNO_CHAVE *)malloc(sizeof(RNO_CHAVE));

        char *key = (char *)malloc(2 * sizeof(char));
        key[0] = P->NOME[0];
        key[1] = '\0';
        atual->KEY = key;
        atual->DADOS = (RLISTA *)malloc(sizeof(RLISTA));
        atual->DADOS->NEL = 0;
        atual->DADOS->Inicio = NULL;
        atual->Prox = B->HRequisitantes->RLChaves->Inicio;
        B->HRequisitantes->RLChaves->Inicio = atual;
        B->HRequisitantes->RLChaves->NEL++;
    }

    AddROrdenado(atual->DADOS, P);

    fclose(F_Logs);
}

int SaveLivros(BIBLIOTECA *B, char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    NO_CHAVE *atual = B->HLivros->LChaves->Inicio;
    while (atual != NULL)
    {
        NO *aux = atual->DADOS->Inicio;
        while (aux != NULL)
        {
            LIVRO *L = aux->Info;
            fprintf(file, "%s\t%s\t%s\t%s\t%d\n", L->TITULO, L->AUTOR, L->AREA, L->ISBN, L->ANO);
            aux = aux->Prox;
        }
        atual = atual->Prox;
    }

    fclose(file);

    return EXIT_SUCCESS;
}

int SaveRequisitantes(BIBLIOTECA *B, char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Could not open file"); // This will print the specific error
        printf("Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    RNO_CHAVE *atual = B->HRequisitantes->RLChaves->Inicio;

    while (atual != NULL)
    {
        RNO *aux = atual->DADOS->Inicio;
        while (aux != NULL)
        {
            PESSOA *P = aux->Info;
            fprintf(file, "%d\t%s\t%s\t%s\n", P->ID, P->NOME, P->DATA_NASCIMENTO, P->IDFRAGUESIA);
            aux = aux->Prox;
        }
        atual = atual->Prox;
    }
    fclose(file);

    return EXIT_SUCCESS;
}

int SaveRequisicoes(BIBLIOTECA *B, char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Could not open file"); // This will print the specific error
        printf("Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    PNO_CHAVE *atual = B->LRequi->PLChaves->Inicio;

    while (atual != NULL)
    {
        NO_REQ *aux = atual->DADOS->Inicio;
        while (aux != NULL)
        {
            REQUISICAO *R = aux->Info;

            char time_str_vencimento[11];
            strftime(time_str_vencimento, sizeof(time_str_vencimento), "%d-%m-%Y", &R->Data_Vencimento);

            char time_str_requisicao[11];
            strftime(time_str_requisicao, sizeof(time_str_requisicao), "%d-%m-%Y", &R->Data_Requisicao);

            fprintf(file, "%d\t%s\t%s\t%s\n", R->Ptr_Req->ID, R->Ptr_Livro->ISBN, time_str_vencimento, time_str_requisicao);

            aux = aux->Prox;
        }
        atual = atual->Prox;
    }
    fclose(file);

    return EXIT_SUCCESS;
}

LIVRO *VerificarLivroPorISBN(BIBLIOTECA *B, char *isbn)
{
    NO_CHAVE *atual = B->HLivros->LChaves->Inicio;
    while (atual != NULL)
    {
        NO *aux = atual->DADOS->Inicio;
        while (aux != NULL)
        {
            LIVRO *L = aux->Info;
            if (strcmp(L->ISBN, isbn) == 0)
            {
                return L;
            }
            aux = aux->Prox;
        }
        atual = atual->Prox;
    }
    return NULL;
}

PESSOA *FindRequesterByID(BIBLIOTECA *B, int id)
{
    // Iterate over all keys
    RNO_CHAVE *atual = B->HRequisitantes->RLChaves->Inicio;
    while (atual != NULL)
    {
        // Iterate over all persons in the current key
        RNO *currentPerson = atual->DADOS->Inicio;
        while (currentPerson != NULL)
        {
            if (currentPerson->Info->ID == id)
            {
                // Found the correct person
                return currentPerson->Info;
            }
            currentPerson = currentPerson->Prox;
        }
        atual = atual->Prox;
    }

    // Requester not found
    return NULL;
}

void VerificarEImprimirLivroPorISBN(BIBLIOTECA *B, char *isbn)
{
    LIVRO *L = VerificarLivroPorISBN(B, isbn);
    if (L != NULL)
    {
        printf("Livro encontrado:\n");
        printf("Titulo: %s\n", L->TITULO);
        printf("Autor: %s\n", L->AUTOR);
        printf("Area: %s\n", L->AREA);
        printf("ISBN: %s\n", L->ISBN);
        printf("Ano: %d\n", L->ANO);
    }
    else
    {
        printf("Livro com ISBN %s não encontrado.\n", isbn);
    }
}

LIVRO *FindMostRecentBook(BIBLIOTECA *B)
{
    LIVRO *most_recent_book = NULL;
    int latest_year = -1;

    NO_CHAVE *atual = B->HLivros->LChaves->Inicio;
    while (atual != NULL)
    {
        NO *aux = atual->DADOS->Inicio;
        while (aux != NULL)
        {
            LIVRO *L = aux->Info;
            if (L->ANO > latest_year)
            {
                most_recent_book = L;
                latest_year = L->ANO;
            }
            aux = aux->Prox;
        }
        atual = atual->Prox;
    }

    return most_recent_book;
}

char *AreaWithMostBooks(BIBLIOTECA *B)
{
    int maxCount = 0;
    char *maxArea = NULL;

    NO_CHAVE *atual = B->HLivros->LChaves->Inicio;
    while (atual != NULL)
    {
        int count = atual->DADOS->NEL;
        if (count > maxCount)
        {
            maxCount = count;
            maxArea = atual->KEY;
        }
        atual = atual->Prox;
    }

    return maxArea;
}

void MostrarRequisicoesRequisitante(BIBLIOTECA *B, char *nome)
{
    // Find the requester
    PESSOA *requisitante = ProcurarRequisitanteRHASHING(B->HRequisitantes, nome);
    if (requisitante == NULL)
    {
        printf("Requisitante nao encontrado\n");
        return;
    }

    int found = 0;

    // Iterate over the keys in the requests hash table
    PNO_CHAVE *P = B->LRequi->PLChaves->Inicio;
    while (P)
    {
        // Iterate over the requests in the list
        NO_REQ *noRequisicao = P->DADOS->Inicio;
        while (noRequisicao)
        {
            REQUISICAO *requisicao = noRequisicao->Info;
            // If the request belongs to the requester, print it
            if (requisicao->Ptr_Req == requisitante)
            {
                MostrarRequisicao(requisicao);
                found = 1;
            }
            noRequisicao = noRequisicao->Prox;
        }
        P = P->Prox;
    }

    if (!found)
    {
        printf("Requisitante nao tem requisicoes\n");
    }
}

void ShowBiblioteca(BIBLIOTECA *B)
{
    if (B == NULL)
    {
        fprintf(stderr, "Biblioteca is NULL\n");
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);

    ShowHashing(B->HLivros);

    fclose(F_Logs);
}

void DestruirBiblioteca(BIBLIOTECA *B)
{
    if (B == NULL)
    {
        return;
    }

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    if (F_Logs == NULL)
    {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    fclose(F_Logs);

    if (B->NOME != NULL)
    {
        free(B->NOME);
    }

    if (B->HLivros != NULL)
    {
        DestruirHashing(B->HLivros);
    }

    if (B->HRequisitantes != NULL)
    {
        DestruirRHashing(B->HRequisitantes);
    }

    if (B->LRequi != NULL)
    {
        DestruirPHashing(B->LRequi);
    }
    if (B->LFreguesias != NULL)
    {
        DestruirListaFreguesias(B->LFreguesias);
    }
    if (B->LConcelhos != NULL)
    {
        DestruirListaConcelhos(B->LConcelhos);
    }
    if (B->LDistritos != NULL)
    {
        DestruirListaDistritos(B->LDistritos);
    }

    free(B);
}

//--------------------------------------------------------

// Function to calculate memory used by a book
size_t MemoryUsageLivro(LIVRO *L)
{
    if (L == NULL)
        return 0;
    return sizeof(LIVRO) + strlen(L->TITULO) + 1 + strlen(L->AUTOR) + 1 + strlen(L->AREA) + 1 + strlen(L->ISBN) + 1;
}

// Function to calculate memory used by a requester
size_t MemoryUsagePessoa(PESSOA *P)
{
    if (P == NULL)
        return 0;
    return sizeof(PESSOA) + strlen(P->NOME) + 1;
}

// Function to calculate memory used by a book list node
size_t MemoryUsageNoLivro(NO *node)
{
    if (node == NULL)
        return 0;
    return sizeof(NO) + MemoryUsageLivro(node->Info);
}

// Function to calculate memory used by a requester list node
size_t MemoryUsageNoPessoa(RNO *node)
{
    if (node == NULL)
        return 0;
    return sizeof(RNO) + MemoryUsagePessoa(node->Info);
}

// Function to calculate memory used by a book hash table node
size_t MemoryUsageNoChaveLivro(NO_CHAVE *node)
{
    if (node == NULL)
        return 0;
    size_t size = sizeof(NO_CHAVE) + strlen(node->KEY) + 1;
    NO *current = node->DADOS->Inicio;
    while (current != NULL)
    {
        size += MemoryUsageNoLivro(current);
        current = current->Prox;
    }
    return size;
}

// Function to calculate memory used by a requester hash table node
size_t MemoryUsageNoChavePessoa(RNO_CHAVE *node)
{
    if (node == NULL)
        return 0;
    size_t size = sizeof(RNO_CHAVE) + strlen(node->KEY) + 1;
    RNO *current = node->DADOS->Inicio;
    while (current != NULL)
    {
        size += MemoryUsageNoPessoa(current);
        current = current->Prox;
    }
    return size;
}

// Function to calculate memory used by the entire book hash table
size_t MemoryUsageHashing(HASHING *H)
{
    if (H == NULL)
        return 0;
    size_t size = sizeof(HASHING);
    NO_CHAVE *current = H->LChaves->Inicio;
    while (current != NULL)
    {
        size += MemoryUsageNoChaveLivro(current);
        current = current->Prox;
    }
    return size;
}

// Function to calculate memory used by the entire requester hash table
size_t MemoryUsageRHashing(RHASHING *H)
{
    if (H == NULL)
        return 0;
    size_t size = sizeof(RHASHING);
    RNO_CHAVE *current = H->RLChaves->Inicio;
    while (current != NULL)
    {
        size += MemoryUsageNoChavePessoa(current);
        current = current->Prox;
    }
    return size;
}

// Function to calculate memory used by the entire requests hash table
size_t MemoryUsagePHashing(PHASHING *H)
{
    if (H == NULL)
        return 0;
    size_t size = sizeof(PHASHING);
    // Add the size of individual request elements and any additional structures here
    return size;
}

// Function to calculate the total memory used by the biblioteca
size_t MemoryUsageBiblioteca(BIBLIOTECA *B)
{
    if (B == NULL)
        return 0;
    size_t size = sizeof(BIBLIOTECA);
    size += strlen(B->NOME) + 1;
    size += MemoryUsageHashing(B->HLivros);
    size += MemoryUsageRHashing(B->HRequisitantes);
    size += MemoryUsagePHashing(B->LRequi);
    return size;
}
