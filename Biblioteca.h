#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Lista.h"
#include "Hashing.h"
#include "Livro.h"


typedef struct
{
    char *NOME;
    char FICHEIRO_LOGS[50];

    HASHING *HLivros;
    //LISTA *LRequisitantes;
    // LISTA_Requisicoes *LRequisicoes;
} BIBLIOTECA;

BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs);
void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);
void AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
void LerLivros(BIBLIOTECA *B, char *nomeLivros);

// int AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
// int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
// LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B);
// char *ApelidoMaisComum(BIBLIOTECA *B);
// char *AreaMaisComum(BIBLIOTECA *B);
// int AddRequisitante(BIBLIOTECA *B, LIVRO *X);
// LIVRO *PesquisarRequisitante(BIBLIOTECA *B, int cod);
#endif // BIBLIOTECA_H_INCLUDED
