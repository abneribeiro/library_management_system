#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Livro.h"
#include "RHashing.h"
#include "hashrequisicoes.h"
#include "Pessoa.h"
#include "RLista.h"
#include "Biblioteca.h"
#include "Uteis.h"

void manageBooksMenu(BIBLIOTECA *Bib)
{
    char input[10];
    int option;

    printf("\n #-------------------------------------------------------------#");
    printf("\n | (1) Adicionar livros a biblioteca                           |");
    printf("\n | (2) Listar todos os livros por area                         |");
    printf("\n | (3) Verificar a area com mais livros                        |");
    printf("\n | (4) Verificar se um livro existe pelo ISBN                  |");
    printf("\n | (5) Encontrar o livro mais recente                          |");
    printf("\n | (6) Encontrar o livro mais requisitado                      |");
    printf("\n | (7) Determinar a area mais requisitada                      |");
    printf("\n | (8) Salvar informacoes dos livros                           |");
    printf("\n | (0) SAIR                                                    |");
    printf("\n #-------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nQual a sua opcao: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 7) || (option == 0 && input[0] != '0'));

    switch (option)
    {
    case 1:
        LIVRO *L = CriarLivro();
        AddLivroBiblioteca(Bib, L);
        break;
    case 2:
        ShowHashing(Bib->HLivros);
        break;
    case 3:
        printf("Area com mais livros: %s\n", AreaWithMostBooks(Bib));
        break;
    case 4:
        printf("Digite o ISBN do livro: ");
        char isbn[100];
        scanf("%s", isbn);
        VerificarEImprimirLivroPorISBN(Bib, isbn);

        break;
    case 5:
        printf("Livro mais recente: %s - %d\n", FindMostRecentBook(Bib)->TITULO, FindMostRecentBook(Bib)->ANO);
        break;
    case 6:
        printf("Livro mais requisitado:  %s\n", LivroMaisRequisitado(Bib)->TITULO);
        break;
    case 7:
        printf("Area mais requisitada: %s\n", AreaMaisRequisitada(Bib));
        break;
    case 8:
        if (SaveLivros(Bib, "import/livros.txt") == 0)
            printf("Livros salvos com sucesso!\n");
        else
            printf("Erro ao salvar os livros!\n");

        break;
    }
}

void ListClients(BIBLIOTECA *Bib)
{
    int option;
    char input[10];
    printf("\n #----------------------------------------------------------------#");
    printf("\n |Listar todos os clientes (ordenados a escolha do utilizdor)-----|\n");
    printf("\n | (1) Por ordem alfabetica do nome                               |\n");
    printf("\n | (2) Por ordem do campo ID Freguesia                            |\n");
    printf("\n | (3) Por ordem alfabetica do apelido                            |\n");
    printf("\n | (0) SAIR                                                       |\n");
    printf("\n #----------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nQual a sua opcao: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 3) || (option == 0 && input[0] != '0'));

    switch (option)
    {
    case 1:
        ShowRHashing(Bib->HRequisitantes, 40); // por ordem alfabetica do nome
        break;
    case 2:
        ShowRHashing(Bib->HRequisitantes, 51); // por ordem do campo | id_freguesia
        break;
    case 3:
        ShowRHashing(Bib->HRequisitantes, 62); // por ordem alfabetica do apelido (considera-se apelido a ultima palavra do nome completo)
        break;
    case 0:
        break;
    }
}

void manageRequisitantsMenu(BIBLIOTECA *Bib)
{
    int option;
    char input[10], reqName[100], name[100];

    printf("\n | ---------------------REQUISITANTES-----------------------------|");
    printf("\n | (1) Incluir novos requisitantes                                |");
    printf("\n | (2) Verificar se um requisitante existe (dando o seu nome)     |");
    printf("\n | (3) Listar todos os clientes (ordenados a escolha do utilizdor)|");
    printf("\n | (4) Determinar a idade maxima dos requisitantes                |");
    printf("\n | (5) Determinar a media das idades dos requisitantes            |");
    printf("\n | (6) Contar o numero de pessoas com idade superior a um valor   |");
    printf("\n | (7) Determinar a idade com mais requisitantes                  |");
    printf("\n | (8) Mostrar as requisicoes de um dado requisitante             |");
    printf("\n | (9) Mostrar pessoas que nunca requisitaram nada                |");
    printf("\n | (10) Listar requisitantes com livros requisitados              |");
    printf("\n | (11) Determinar o sobrenome mais comum dos requisitantes       |");
    printf("\n | (12) Determinar o numero de pessoas de um dado distrito        |");
    printf("\n | (13) Salvar informacoes dos requisitantes                      |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 13) || (option == 0 && input[0] != '0'));

    switch (option)
    {
    case 1: // ADICIONAR A LISTA DE REQUISITANTES
        PESSOA *P = CriarPessoa();
        AddRequisitanteBiblioteca(Bib, P);
        break;
    case 2:
        printf("Digite o nome do requisitante: ");
        fscanf(stdin, "%99[^\n]", reqName);
        CLEAR_BUFFER;

        VerificarRequisitanteRHASHING(Bib->HRequisitantes, reqName);
        break;
    case 3:
        ListClients(Bib);
        break;
    case 4:
        printf("Idade maxima dos requisitantes: %d", maxAge(Bib->HRequisitantes));
        break;
    case 5:
        printf("Media das idades dos requisitantes: %.2f", averageAge(Bib->HRequisitantes));
        break;
    case 6:
        printf("Digite a idade limite: ");
        int age_limit;
        scanf("%d", &age_limit);
        printf("Numero de pessoas com idade superior a %d: %d", age_limit, countPeopleAboveAge(Bib->HRequisitantes, age_limit));
        break;
    case 7:

        printf("A idade com mais requistantes eh %d", mostCommonAge(Bib->HRequisitantes));
        break;
    case 8:
        printf("Digite o nome do requisitante: ");
        fscanf(stdin, "%99[^\n]", name);
        CLEAR_BUFFER;

        MostrarRequisicoesRequisitante(Bib, name);
        break;
    case 9:
        MostrarPessoasSemRequisicoes(Bib);
        break;
    case 10:
        ListarRequisitantesComLivros(Bib->LRequi);
        break;
    case 11:
        printf("O sobrenome mais comum dos requisitantes eh %s", MostUsedSurnameRHASHING(Bib->HRequisitantes));
        break;
    case 12:
        // countPeopleFromDistrict();  Distrito (ou Concelho)
        break;
    case 13:
        if (SaveRequisitantes(Bib, "import/requisitantes.txt") == 0)
            printf("Requisitantes salvos com sucesso!\n");
        else
            printf("Erro ao salvar os requisi!\n");
        break;
    }
}

void manageRequisitionsMenu(BIBLIOTECA *Bib)
{
    int option;
    char input[10];

    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Requisicao de um livro por parte de um requisitante        |");
    printf("\n | (2) Listar livros atualmente requisitados                      |");
    printf("\n |     (organizados por area)                                     |");
    printf("\n | (3) Devolver um livro requisitado anteriormente                |");
    printf("\n | (4) Listar Livros requisitados e atrasados na entrega          |");
    printf("\n | (5) Listar requisitantes nascidos em Domingo                   |");
    printf("\n |     (ou cujo aniversario em um ano especifico eh um Domingo)   |");
    printf("\n | (6) Listar requisitantes com aniversario na quaresma           |");
    printf("\n |     (ou que nasceram na quaresma)                              |");
    printf("\n | (7) Salvar informacoes das requisicoes                         |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 5) || (option == 0 && input[0] != '0'));

    switch (option)
    {
    case 1:

        int Id;
        char isbn[15], ch;
        CLEAR_BUFFER;
        printf("Digite o ID do requisitante: ");
        scanf("%d", &Id);
        CLEAR_BUFFER;
        printf("Digite o ISBN do livro: ");

        fscanf(stdin, "%14[^\n]", isbn);
        CLEAR_BUFFER;
        RequestBook(Bib, isbn, Id);
        break;
    case 2:
        ShowPHashing(Bib->LRequi);
        break;
    case 3:
        CLEAR_BUFFER;
        printf("Digite o ID do requisitante: ");
        scanf("%d", &Id);
        CLEAR_BUFFER;
        printf("Digite o ISBN do livro: ");
        fscanf(stdin, "%14[^\n]", isbn);
        CLEAR_BUFFER;
        ReturnBook(Bib->LRequi, Id, isbn);
        break;
    case 4:
        ListOverdueBooks(Bib->LRequi);
        break;
    case 5:
        ListarPessoasNascidasDomingo(Bib->HRequisitantes);
        break;
    case 6:
        ListarRequisitantesNascidosNaQuaresma(Bib->HRequisitantes);

        break;
    case 7:
        if (SaveRequisicoes(Bib, "import/requisicoes.txt") == 0)
            printf("Requisicoes salvas com sucesso!\n");
        else
            printf("Erro ao salvar as requisicoes!\n");
        break;
    case 0:
        break;
    }
}

int menu()
{
    char input[10];
    int option;
    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Gerir os livros                                            |");
    printf("\n | (2) Gerir a lista de requisitantes                             |");
    printf("\n | (3) Gerir as requisicoes de livros                             |");
    printf("\n | (4) Salvar dados em XML (nome fornecido pelo usuario)          |");
    printf("\n | (5) Salvar dados em CSV (nome fornecido pelo usuario)          |");
    printf("\n | (6) Memoria das Estruturas de Dados                            |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 5) || (option == 0 && input[0] != '0'));
    return option;
}

int main()
{
    int option, sub_option;
    printf("\t\tBiblioteca-ESTGV!\n");
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    LoadFicheiroBiblioteca(Bib);

    do
    {
        option = menu();
        system("cls");
        switch (option)
        {
        case 1:
            manageBooksMenu(Bib);
            break;
        case 2:
            manageRequisitantsMenu(Bib);
            break;
        case 3:
            manageRequisitionsMenu(Bib);

            break;
        case 4:
            char filename[100];

            printf("Digite o nome do arquivo: ");
            fscanf(stdin, "%99[^\n]", filename);
            CLEAR_BUFFER;
            SaveAllToXML(Bib, filename);

            break;
        case 5:
            
            printf("Digite o nome do arquivo: ");
            fscanf(stdin, "%99[^\n]", filename);
            CLEAR_BUFFER;
            SaveAllToCSV(Bib, filename);

            break;
        case 6:
            size_t totalMemory = MemoryUsageBiblioteca(Bib);
            printf("Total memory used by the biblioteca: %zu bytes\n", totalMemory);
            break;

        case 0: // sair
            // Salvar dados antes de terminar o programa
            printf("\n\n ***** Salvando os dados *****\n");
            printf(" ***** Saindo do programa *****\n");
            break;
        }
    } while (option != 0);

    SaveFicheiroBiblioteca(Bib);

    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
