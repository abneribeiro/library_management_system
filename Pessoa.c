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
}

PESSOA *CriarRequisitanteDaLinha(char *linha)
{
    PESSOA *R = (PESSOA *)malloc(sizeof(PESSOA));

    if(R == NULL)
    {
        printf("Erro ao alocar memoria para a pessoa\n");
        return NULL;
    }
    // ID;NOME;DATA_NASCIMENTO;IDFRAGUESIA
    char *token = strtok(linha, "\t");
    R->ID = atoi(token);

    token = strtok(NULL, "\t");
    R->NOME = strdup(token);

    token = strtok(NULL, "\t");
    R->DATA_NASCIMENTO = strdup(token);

    token = strtok(NULL, "\t");
    R->IDFRAGUESIA = strdup(token);
   
    return R;
}


void MostrarPessoa(PESSOA *P)
{
    printf("PESSOA: ID: %d [%s] [%s] [%s]\n", P->ID, P->NOME, P->DATA_NASCIMENTO, P->IDFRAGUESIA);
}


void DestruirPessoa(PESSOA *P)
{ 

    free (P->NOME);
    free (P->DATA_NASCIMENTO);
    free (P->IDFRAGUESIA);
    free (P);
}
