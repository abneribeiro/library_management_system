#include "Pessoa.h"
#include "Uteis.c"


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



void MostrarPessoa(PESSOA *P)
{
    printf("\tPESSOA: ID: %d [%s] [%s] [%s]\n", P->ID, P->NOME, P->DATA_NASCIMENTO, P->IDFRAGUESIA);
}
void DestruirPessoa(PESSOA *P)
{
    free (P->ID);  
    free (P->NOME);
    free (P->DATA_NASCIMENTO);
    free (P->IDFRAGUESIA);
    free (P);
}
