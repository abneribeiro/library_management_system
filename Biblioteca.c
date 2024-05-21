#include "Biblioteca.h"
#include "Lista.h"
#include "Livro.h"
#include "Pessoa.h"
#include "RLista.h"
#include "RHashing.h"

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
    // Bib->LRequisitantes = CriarListaLIVROs();
    return Bib;
}


void LerLivros(BIBLIOTECA *B, char *filename)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
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

    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
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
            fprintf(file, "%s;%s;%s;%s;%d\n", L->TITULO, L->AUTOR, L->AREA, L->ISBN, L->ANO);
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

void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);
    // Vosso Codigo.....
    ShowHashing(B->HLivros);

    fclose(F_Logs);
}

void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Vosso Codigo.....
    free(B->NOME);
    DestruirHashing(B->HLivros);
    DestruirRHashing(B->HRequisitantes);
    
    free(B);

    fclose(F_Logs);
}

// int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn)
// {
//     FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
//     time_t now = time(NULL) ;
//     fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

//     // Aqui o teu codigo

//     fclose(F_Logs);
//     return EXIT_SUCCESS;
// }
// LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B)
// {
//     FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
//     time_t now = time(NULL) ;
//     fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

//     // Aqui o teu codigo

//     fclose(F_Logs);
//     return NULL;
// }
// char *ApelidoMaisComum(BIBLIOTECA *B)
// {
//     FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
//     time_t now = time(NULL) ;
//     fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

//     // Aqui o teu codigo

//     fclose(F_Logs);
//     return NULL;
// }
// char *AreaMaisComum(BIBLIOTECA *B)
// {
//     FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
//     time_t now = time(NULL) ;
//     fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

//     // Aqui o teu codigo

//     fclose(F_Logs);
//     return NULL;
// }
// int AddRequisitante(BIBLIOTECA *B, LIVRO *X)
// {
//     FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
//     time_t now = time(NULL) ;
//     fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

//     // Aqui o teu codigo

//     fclose(F_Logs);
//     return EXIT_SUCCESS;
// }
// LIVRO *PesquisarRequisitante(BIBLIOTECA *B, int cod)
// {
//     FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
//     time_t now = time(NULL) ;
//     fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

//     // Aqui o teu codigo

//     fclose(F_Logs);
//     return NULL;
// }
