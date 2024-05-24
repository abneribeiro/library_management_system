#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Lista.h"
#include "Hashing.h"
#include "RHashing.h"
#include "Livro.h"
#include "Plista.h"
#include "hash_requisicoes.h"

typedef struct
{
    char *NOME;
    char FICHEIRO_LOGS[50];

    HASHING *HLivros;
    RHASHING *HRequisitantes;
    PHASHING *LRequi; // comecar a trabalhar a partir daqui amanha e depois criar as funcoes para ler os dados das fraguesias, concelhos e distritos
} BIBLIOTECA;

BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs);
void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);
void AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
void AddRequisitanteBiblioteca(BIBLIOTECA *B, PESSOA *P);
void LerLivros(BIBLIOTECA *B, char *filename);
void SaveLivros(BIBLIOTECA *B, char *filename);
void SaveFicheiroBiblioteca(BIBLIOTECA *B);
LIVRO *VerificarLivroPorISBN(BIBLIOTECA *B, char *isbn);
void VerificarEImprimirLivroPorISBN(BIBLIOTECA *B, char *isbn);
LIVRO *FindMostRecentBook(BIBLIOTECA *B);
char *AreaWithMostBooks(BIBLIOTECA *B);
void LerRequisitantes(BIBLIOTECA *B, char *filename);
PESSOA *FindRequesterByID(BIBLIOTECA *B, int id);
void RequestBook(BIBLIOTECA *B, PHASHING *H, char *isbn, int requestId, int period);






size_t MemoryUsageLivro(LIVRO *L);
size_t MemoryUsagePessoa(PESSOA *P);
size_t MemoryUsageNoLivro(NO *node);
size_t MemoryUsageNoPessoa(RNO *node);
size_t MemoryUsageNoChaveLivro(NO_CHAVE *node);
size_t MemoryUsageNoChavePessoa(RNO_CHAVE *node);
size_t MemoryUsageHashing(HASHING *H);
size_t MemoryUsageRHashing(RHASHING *H);
size_t MemoryUsagePHashing(PHASHING *H);
size_t MemoryUsageBiblioteca(BIBLIOTECA *B);

// int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
// LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B);
// char *ApelidoMaisComum(BIBLIOTECA *B);
// int AddRequisitante(BIBLIOTECA *B, LIVRO *X);
// LIVRO *PesquisarRequisitante(BIBLIOTECA *B, int cod);
#endif // BIBLIOTECA_H_INCLUDED
