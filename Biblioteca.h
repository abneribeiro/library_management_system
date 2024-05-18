#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Lista.h"
#include "Hashing.h"
#include "RHashing.h"
#include "Livro.h"


typedef struct
{
    char *NOME;
    char FICHEIRO_LOGS[50];

    HASHING *HLivros;
    RHASHING *HRequisitantes;
    
    // LISTA_Requisicoes *LRequisicoes;
} BIBLIOTECA;

BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs);
void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);
void AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
void AddRequisitanteBiblioteca(BIBLIOTECA *B, PESSOA *P);
void LerLivros(BIBLIOTECA *B, char *nomeLivros);
void SaveLivros(BIBLIOTECA *B, char *filename);
void SaveFicheiroBiblioteca(BIBLIOTECA *B);
LIVRO *VerificarLivroPorISBN(BIBLIOTECA *B, char *isbn);
void VerificarEImprimirLivroPorISBN(BIBLIOTECA *B, char *isbn);
LIVRO *FindMostRecentBook(BIBLIOTECA *B);
char *AreaWithMostBooks(BIBLIOTECA *B);


// int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
// LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B);
// char *ApelidoMaisComum(BIBLIOTECA *B);
// int AddRequisitante(BIBLIOTECA *B, LIVRO *X);
// LIVRO *PesquisarRequisitante(BIBLIOTECA *B, int cod);
#endif // BIBLIOTECA_H_INCLUDED
