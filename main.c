#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Livro.h"
#include "Biblioteca.h"

extern int LerInteiro(char *txt);

void manageBooksMenu(BIBLIOTECA *Bib)
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

    printf("\n | (0) SAIR                                                    |");
    printf("\n #-------------------------------------------------------------#");

    printf("\n ");

    do
    {
        printf("\nQual a sua opcao: ");

        scanf(" %d", &option);
    } while (option < 0 || option > 7); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

    switch (option)
    {
    case 1:
        LIVRO *L = CriarLivro();
        AddLivroBiblioteca(Bib, L);
        break;
    case 2:
        ShowBiblioteca(Bib);
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
        // mostRequestedBook(); Se existir mais  do que um, deve devolver o primeiro encontrado)
        break;
    case 7:
        // mostRequestedArea(); Se existir mais    tdo que uma, deve devolver a primeira encontrada)
        break;
    case 8:
        // saveBooks();
        break;
    }
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
        scanf(" %d", &option);
    } while (option < 0 || option > 13); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

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
        scanf(" %d", &option);
    } while (option < 0 || option > 4); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!

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
        scanf(" %d", &option);
    } while (option < 0 || option > 3); // alterar de modo a permitir que seja inserido caracter e n�o terminar a execucao!!
    return option;
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

    SaveFicheiroBiblioteca(Bib);


    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
