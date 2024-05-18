#include "Pessoa.h"
#include "Uteis.h"
#include "texto.h"
#include <time.h>


/** \brief Permite Alocar e inicializar uma estrutura Pessoa
 *
 * \param _id int
 * \param _nome char*
 * \param _categoria char*
 * \return PESSOA*
 *
 */
/*
PESSOA *CriarPessoa()
{
    char _nome[100],  _data_nascimento[100], _idfraguesia[100];
    int _id, ch;
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));

    str_to_upper(_nome);
    P->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(P->NOME, _nome);

    str_to_upper(_data_nascimento);
    P->DATA_NASCIMENTO = (char *)malloc((strlen(_data_nascimento) + 1) * sizeof(char));
    strcpy(P->DATA_NASCIMENTO, _data_nascimento);

    str_to_upper(_idfraguesia);
    P->IDFRAGUESIA = (char *)malloc((strlen(_idfraguesia) + 1) * sizeof(char));

    printf("Digite o ID da pessoa: ");
    scanf("%d", &_id);
    
    P->ID = _id;

    return P;
}*/

PESSOA *CriarRequisitanteDaLinha(char *linha)
{
    char *token;
    PESSOA *R = (PESSOA *)malloc(sizeof(PESSOA));

    // Validar e atribuir o ID
    token = strtok(linha, "\t");
    if (token == NULL || !ValidarID(token))
    {
        free(R);
        return NULL;
    }
    R->ID = atoi(token);

    // Validar e atribuir o nome
    token = strtok(NULL, "\t");
    if (token == NULL || !ValidarNome(token))
    {
        free(R);
        return NULL;
    }
    R->NOME = strdup(token);

    // Validar e atribuir a data de nascimento
    token = strtok(NULL, "\t");
    if (token == NULL || !ValidarDataNascimento(token))
    {
        free(R);
        return NULL;
    }
    R->DATA_NASCIMENTO = strdup(token);

    // Validar e atribuir o número de telefone
    token = strtok(NULL, "\t");
    if (token == NULL || !ValidarIDFreguesia(token))
    {
        free(R);
        return NULL;
    }
    R->IDFRAGUESIA = strdup(token);
    printf("ID: %d\n", R->ID);
    return R;
}


void MostrarPessoa(PESSOA *P)
{
    printf("\tPESSOA: ID: %s [%s] [%s] [%s]\n", P->ID, P->NOME, P->DATA_NASCIMENTO, P->IDFRAGUESIA);
}


void DestruirPessoa(PESSOA *P)
{ 
    free (P->NOME);
    free (P->DATA_NASCIMENTO);
    free (P->IDFRAGUESIA);
    free (P);
}
