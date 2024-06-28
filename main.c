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
    printf("\n | (1) Add books to the library                                 |");
    printf("\n | (2) List all books by area                                   |");
    printf("\n | (3) Check the area with the most books                       |");
    printf("\n | (4) Check if a book exists by ISBN                           |");
    printf("\n | (5) Find the most recent book                                |");
    printf("\n | (6) Find the most requested book                             |");
    printf("\n | (7) Determine the most requested area                        |");
    printf("\n | (8) Save book information                                    |");
    printf("\n | (0) EXIT                                                     |");
    printf("\n #-------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nEnter your choice: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 8) || (option == 0 && input[0] != '0'));

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
    printf("\n | List all clients (sorted as chosen by the user)                |");
    printf("\n | (1) Alphabetical order by name                                 |");
    printf("\n | (2) Order by District ID                                       |");
    printf("\n | (3) Alphabetical order by last name                            |");
    printf("\n | (0) EXIT                                                       |");
    printf("\n #----------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nEnter your choice: ");
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

    printf("\n | ---------------------REQUESTERS--------------------------------|");
    printf("\n | (1) Add new requesters                                         |");
    printf("\n | (2) Check if a requester exists (by giving their name)         |");
    printf("\n | (3) List all clients (sorted as chosen by the user)            |");
    printf("\n | (4) Determine the maximum age of requesters                    |");
    printf("\n | (5) Calculate the average age of requesters                    |");
    printf("\n | (6) Count the number of people older than a certain age        |");
    printf("\n | (7) Determine the age with the most requesters                 |");
    printf("\n | (8) Show requests of a given requester                         |");
    printf("\n | (9) Show people who have never requested anything              |");
    printf("\n | (10) List requesters with requested books                      |");
    printf("\n | (11) Determine the most common last name among requesters      |");
    printf("\n | (12) Determine the number of people from a given district      |");
    printf("\n | (13) Save requester information                                |");
    printf("\n | (0) EXIT                                                        |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nEnter your choice: ");
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
    printf("\n | (1) Request a book by a requester                              |");
    printf("\n | (2) List currently requested books (sorted by area)            |");
    printf("\n | (3) Return a previously requested book                         |");
    printf("\n | (4) List overdue requested books                               |");
    printf("\n | (5) List requesters born on a Sunday                           |");
    printf("\n |     (or whose birthday in a specific year is on a Sunday)      |");
    printf("\n | (6) List requesters born in Lent (or who were born in Lent)    |");
    printf("\n | (7) Save request information                                   |");
    printf("\n | (0) EXIT                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nEnter your choice: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 7) || (option == 0 && input[0] != '0'));

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
    printf("\n | (1) Manage books                                               |");
    printf("\n | (2) Manage the list of requesters                              |");
    printf("\n | (3) Manage book requests                                       |");
    printf("\n | (4) Save data to XML (name provided by user)                   |");
    printf("\n | (5) Save data to CSV (name provided by user)                   |");
    printf("\n | (6) Data Structures Memory                                     |");
    printf("\n | (0) EXIT                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nEnter your choice: ");
        fgets(input, 10, stdin);
        option = atoi(input);

    } while ((option < 0 || option > 6) || (option == 0 && input[0] != '0'));
    return option;
}

int main()
{
    int option, sub_option;
    printf("\t\tLibrary-PTOL!\n");
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Library-PTOL", "log.txt");
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
            printf("\nMemoria total usada pela biblioteca: %zu bytes\n", totalMemory);
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
