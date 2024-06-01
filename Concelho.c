#include <stdio.h>
#include  "Concelho.h"
#include "texto.h"



CONCELHO *CriarConcelhoDaLinha(char *linha){
    CONCELHO *C = (CONCELHO *)malloc(sizeof(CONCELHO));
    FILE *F_Logs = fopen("log.txt", "a");

    if (C == NULL)
    {
        printf("Erro ao alocar memoria para o concelho\n");
        return NULL;
    }

    // ID_CONCELHO;CONCELHO
    // Verificar os dados  antes de passar
    char *token = strtok(linha, "\t");


    C->id_concelho = strdup(token);

    token = strtok(NULL, "\t");
    // if(!ValidarNome(token)){
    //     fprintf(F_Logs, "Erro ao validar Nome: %s\n", token);
    //     printf("Erro nome: %s\n", token);
    //     free(C);
    //     return NULL;
    // }

    C->concelho = strdup(token);

    fclose(F_Logs);

    return C;
}

void MostrarConcelho(CONCELHO *L){
    printf("ID: %s\n", L->id_concelho);
    printf("Concelho: %s\n", L->concelho);
}

void DestruirConcelho(CONCELHO *L){
    free(L->id_concelho);
    free(L->concelho);
    free(L);
}