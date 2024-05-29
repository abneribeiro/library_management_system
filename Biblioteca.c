#include "Biblioteca.h"
#include "Lista.h"
#include "Livro.h"
#include "Pessoa.h"
#include "RLista.h"
#include "RHashing.h"
#include "Plista.h"
#include "hashrequisicoes.h"
#include "Requisicao.h"

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

int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    LerLivros(B, "import/livros.txt");
    LerRequisitantes(B, "import/requisitantes.txt");

    fclose(F_Logs);
    return EXIT_SUCCESS;
}

void SaveFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    SaveLivros(B, "import/livros.txt");
    // SaveRequisitantes(B, "Requisitantes.txt");

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

void SaveLivros(BIBLIOTECA *B, char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return;
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

    free(B);

    fclose(F_Logs);
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
