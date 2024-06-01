#include <time.h>
#include "Pessoa.h"
#include "Uteis.h"
#include "texto.h"



PESSOA *CriarPessoa()
{
    char _nome[100], _data_nascimento[100], _idfraguesia[100];
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
    FILE *F_Logs = fopen("log.txt", "a");

    if (R == NULL)
    {
        printf("Erro ao alocar memoria para a pessoa\n");
        return NULL;
    }
    // ID   NOME DATA_NASCIMENTO    IDFRAGUESIA
    // Verificar os dados  antes de passar
    char *token = strtok(linha, "\t");
    if (!ValidarID(token))
    {
        fprintf(F_Logs, "%s\n Erro ao validar ID Do Requisitante: %s\n", linha, token);

        free(R);
        return NULL;
    }

    R->ID = atoi(token);

    token = strtok(NULL, "\t");
    if (!ValidarNome(token))
    {
        fprintf(F_Logs, "%s\nErro ao validar Nome Do Requisitante: %s\n", linha, token);

        fclose(F_Logs);
        free(R);
        return NULL;
    }

    R->NOME = strdup(token);

    token = strtok(NULL, "\t");
    if (!ValidarDataNascimento(token))
    {
        fprintf(F_Logs, "%s\nErro ao validar Data Nascimento: %s\n",linha, token);

        fclose(F_Logs);
        free(R);
        return NULL;
    }

    R->DATA_NASCIMENTO = strdup(token);

    token = strtok(NULL, "\t");

    size_t len = strlen(token);
    if (len > 0 && token[len - 1] == '\n')
    {
        token[len - 1] = '\0';
    }

    if (!ValidarIDFreguesia(token))
    {
        fprintf(F_Logs, "%s\nErro ao validar ID Freguesia: %s\n", linha, token);
        fclose(F_Logs);

        free(R);
        return NULL;
    }

    
    R->IDFRAGUESIA = strdup(token);
    fclose(F_Logs);
    return R;
}

void MostrarPessoa(PESSOA *P)
{
    printf("PESSOA: ID: %d [%s] [%s] [%s]\n", P->ID, P->NOME, P->DATA_NASCIMENTO, P->IDFRAGUESIA);
}

void DestruirPessoa(PESSOA *P)
{

    free(P->NOME);
    free(P->DATA_NASCIMENTO);
    free(P->IDFRAGUESIA);
    free(P);
}
