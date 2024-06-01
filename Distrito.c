#include "Distrito.h"
#include "texto.h"

// DISTRITO *CriarDISTRITO();

DISTRITO *CriarDistritoDaLinha(char *linha)
{
    DISTRITO *D = (DISTRITO *)malloc(sizeof(DISTRITO));
    FILE *F_Logs = fopen("log.txt", "a");

    if (D == NULL)
    {
        printf("Erro ao alocar memoria para o distrito\n");
        return NULL;
    }

    // ID_DISTRITO;DISTRITO
    // Verificar os dados  antes de passar
    char *token = strtok(linha, "\t");

    D->id_distrito = strdup(token);

    token = strtok(NULL, "\n");
    // if (token == NULL || !ValidarNome(token))
    // {
    //     fprintf(F_Logs, "Erro ao validar Nome: %s\n", token);
    //     printf("Erro nome: %s\n", token);
    //     free(D);
    //     return NULL;
    // }

    D->distrito = strdup(token);

    fclose(F_Logs);

    return D;
}



void MostrarDistrito(DISTRITO *L)
{
    printf("ID: %s\n", L->id_distrito);
    printf("Distrito: %s\n", L->distrito);
}
void DestruirDistrito(DISTRITO *L)
{
    free(L->id_distrito);
    free(L->distrito);
    free(L);
}