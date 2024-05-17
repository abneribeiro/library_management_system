

#include "Biblioteca.h"
#include "Lista.h"
#include "Livro.h"

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
    //Bib->LRequisicoes = CriarListaRequisicoes();
    //Bib->LRequisitantes = CriarListaLIVROs();
    return Bib;
}

/** \brief Funcao para Mostrar toda a Biblioteca
 *
 * \param B BIBLIOTECA* : Pnteiro para a Biblioteca
 * \return void
 * \author : Docentes e Alunos
 * \date   : 11/04/2024
 */
void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);
    // Vosso Codigo.....
    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Vosso Codigo.....
    free (B->NOME);
    //------
    free(B);

    fclose(F_Logs);
}

void LerLivros(BIBLIOTECA *B, char *filename)
{
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

int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    LerLivros(B, "import/livros.txt");
   // LerRequisitantes(B, "Requisitantes.txt");
    

    fclose(F_Logs);
    return EXIT_SUCCESS;
}


void AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // criar um novo no para o livro
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = L;
    aux->Prox = NULL;

    //cria um novo no chave se nao existir
    NO_CHAVE *atual= FuncaoHashing(B->HLivros, L);

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
