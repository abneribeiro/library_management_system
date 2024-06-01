#include <stdio.h>
#include "Freguesia.h"
#include "texto.h"

// FREGUESIA *CriarFREGUESIA();
FREGUESIA *CriarFreguesiaDaLinha(char *linha)
{
    FREGUESIA *L = (FREGUESIA *)malloc(sizeof(FREGUESIA));
    FILE *F_Logs = fopen("logs.txt", "a");

    if (L == NULL)
    {
        printf("Erro ao alocar memoria para a pessoa\n");
        return NULL;
    }
    // ID_FREGUESIA FREGUESIA
    // Verificar os dados  antes de passar
    char *token = strtok(linha, "\t");
    if (!ValidarIDFreguesia(token)){
        fprintf(F_Logs, "Erro ao validar ID Freguesia: %s\n", token);
        printf("Erro ID: %s\n", token);

        free(L);
        return NULL;
    }

    L->id_freguesia = strdup(token);

    token = strtok(NULL, "\t");
    // if (!ValidarNomeFreguesia(token)){
    //     fprintf(F_Logs, "Erro ao validar Nome Freguesia: %s\n", token);
    //     printf("Erro nome Freguesia: %s\n", token);
    //     free(L);
    //     return NULL;
    // }

    L->FREGUESIA = strdup(token);

    fclose(F_Logs);

    return L;
}

void MostrarFreguesia(FREGUESIA *L)
{
    printf("ID: %s\n", L->id_freguesia);
    printf("Freguesia: %s\n", L->FREGUESIA);
}

void DestruirFreguesia(FREGUESIA *L)
{
    free(L->id_freguesia);
    free(L->FREGUESIA);
    free(L);
}


