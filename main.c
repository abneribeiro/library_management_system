#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Livro.h"
#include "Biblioteca.h"

extern int LerInteiro(char *txt);

void manageBooksMenu()
{
    int option;

    printf("\n #-------------------------------------------------------------#");
    printf("\n | (1) Adicionar livros a biblioteca                           |");
    printf("\n | (2) Listar todos os livros por area                         |");
    printf("\n | (3) Verificar a area com mais livros                        |");
    printf("\n | (4) Verificar se um livro existe pelo ISBN                  |");
    printf("\n | (5) Encontrar os livros mais recentes                       |");
    printf("\n | (6) Encontrar o livro mais requisitado                      |");
    printf("\n | (7) Determinar a area mais requisitada                      |");
    printf("\n | (8) Salvar informacoes do livro                             |");
    printf("\n | (0) SAIR                                                    |");
    printf("\n #-------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 7); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

    do
    {
        switch (option)
        {
        case 1:
            // addBook();
            break;
        case 2:
            // listBooks();
            break;
        case 3:
            // areaWithMostBooks();
            break;
        case 4:
            // searchBook(); se existir deve mostrar os seus dados
            break;
        case 5:
            // mostRecentBooks(); o que tiver o ano mais recente!
            break;
        case 6:
            // mostRequestedBook(); Se existir mais  do que um, deve devolver o primeiro encontrado)
            break;
        case 7:
            // mostRequestedArea(); Se existir mais    tdo que uma, deve devolver a primeira encontrada)
            break;
        case 8:
            // saveBooks();
            break;
        }
    } while (option != 0);
}
void manageRequisitantsMenu()
{
    int option;

    printf("\n | ---------------------REQUISICOES-------------------------------|");
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
    printf("\n | (13) Salvar informacoes das requisicoes                        |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 22); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!
    do
    {
        switch (option)
        {
        case 1: // ADICIONAR A LISTA DE REQUISITANTES
            // addNodePos(requesters ,addRequester(), checkRequester);
            break;
        case 2:
            // searchRequisitant();
            break;
        case 3:
            // listRequisitants(); por ordem alfabetica do nome, por ordem do campo | id_freguesia, por ordem alfabetica do apelido (considera-se apelido a ultima palavra do nome completo)
            break;
        case 4:
            // maxAge();
            break;
        case 5:
            // averageAge();
            break;
        case 6:
            // countAge();  (introduzido pelo teclado)
            break;
        case 7:
            // mostAge();
            break;
        case 8:
            // showRequisitions();
            break;
        case 9:
            // neverRequested();
            break;
        case 10:
            // requisitantsWithBooks();
            break;
        case 11:
            // mostUsedSurname();
            break;
        case 12:
            // countPeopleFromDistrict();  Distrito (ou Concelho)
            break;
        case 13:
            // saveRequisitions();
            break;
        }
    } while (option != 0);
}
void manageRequisitionsMenu()
{
    int option;

    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Listar requisitantes nascidos em Domingo                   |");
    printf("\n |     (ou cujo aniversario em um ano especifico eh um Domingo)   |");
    printf("\n | (2) Devolver um livro requisitado anteriormente                |");
    printf("\n | (3) Listar livros atualmente requisitados                      |");
    printf("\n |     (organizados por area)                                     |");
    printf("\n | (4) Salvar informacoes dos requisitantes                       |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 22); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

    do
    {
        switch (option)
        {
        case 1:
            // bornOnSunday();
            break;
        case 2:
            // returnBook();
            break;
        case 3:
            // listRequisitions();
            break;
        case 4:
            // saveRequisitions();
            break;
        }
    } while (option != 0);
}

int menu()
{

    int option;
    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Gerir os livros                                            |");
    printf("\n | (2) Gerir a lista de requisitantes                             |");
    printf("\n | (3) Gerir as requisicoes de livros                             |");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");

    do
    {
        printf("\nQual a sua opcao: ");
        fflush(stdin);
        scanf(" %d", &option);
    } while (option < 0 || option > 22); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!
    return option;
}

//-----------------------------------------
void Exemplo_Hashing()
{
    HASHING *Has = CriarHashing();
    LIVRO *L = CriarLivro("Jonas", "CAT-A", "Joao", "1234", 2020);
    AddHashing(Has, L);
    L = CriarLivro("James Bond", "CAT-A", "Joao", "1234", 2020);
    AddHashing(Has, L);
    L = CriarLivro("Abner", "CAT-B", "Joao", "1234", 2020);
    AddHashing(Has, L);
    L = CriarLivro("Jonas", "CAT-C", "Joao", "1234", 2020);
    AddHashing(Has, L);
    L = CriarLivro("Jonas", "CAT-C", "Joao", "1234", 2020);
    AddHashing(Has, L);
    ShowHashing(Has);
    //
    DestruirHashing(Has);
}

/*
int Menu()
{
    printf("1- Load\n");
    printf("2- Show\n");
    printf("3- Nome mais Comum\n");
    printf("0-Sair\n");
    int op;
    op = LerInteiro("Qual a o opcao? ");
    return op;
}*/

int main()
{
    int option, sub_option;
    printf("Biblioteca-ESTGV!\n");
    // Exemplo_Hashing();
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    /*int OP;
    do
    {
        OP = Menu();
        switch(OP)
        {
            case 1: LoadFicheiroBiblioteca(Bib); break;
            case 2: ShowBiblioteca(Bib); break;
            default:
                printf("Opcao nao implementada\n"); break;
        }

    }while (OP != 0);*/

    do
    {
        option = menu();
        system("cls");
        switch (option)
        {
        case 1:
            manageBooksMenu();
            break;
        case 2:
            manageRequisitantsMenu();
            break;
        case 3:
            manageRequisitionsMenu();

            break;
        case 0: // sair
            // Salvar dados antes de terminar o programa
            printf("\n\n ***** Salvando os dados *****\n");
            printf(" ***** Saindo do programa *****\n");
            break;
        }
    } while (option != 0);

    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
