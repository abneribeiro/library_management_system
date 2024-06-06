## Library Management System

**GOALS**

- [X] Create Menu
- [X] Load Data from Files
- [X] Validate Data in "requisitantes.txt"
- [X] Log incorrect data errors in "logs.txt" and discard them
- [X] Record information about books, requesters, and requests (at the moment or at the end of the program)
- [X] **Manage Books**
    - [X] Add books
    - [X] List books
    - [X] Determine the area with the most books
    - [X] Check if a book exists (ISBN); if it exists -> show details
    - [X] Determine the most recent book(s) (year)
    - [X] Determine the most requested book (if there is more than one, return the first found)
    - [X] Determine the most requested area (return the first found)
- [X] **Manage Requesters List**
    - [X] Add requesters
    - [X] Check if requester exists (return name)
    - [X] List clients
    - [X] Maximum age of all requesters
    - [X] Average age of all requesters
    - [X] Number of people older than X
    - [X] Determine the age with the most requesters
    - [X] Show the requests of a given requester
    - [X] Return a list of people who have never requested anything
    - [X] List requesters who currently have borrowed books
    - [X] Determine the most common surname among requesters
    - [X] **List requesters who were born on a Sunday (or whose birthday in a given year falls on a Sunday)**
    - [X] **List requesters whose birthday, in a given year, falls during Lent (between Carnival and Easter), (or who were born during Lent)**
- [X] **Manage Book Requests**
    - [X] Request a Book
    - [X] Return a Requested Book
    - [X] List Requested Books
- [X] Determine the memory occupied by the entire Data Structure
- [x] Save all information to a given XML file, the name of which is provided by the user
- [X] Free all memory used by the structures before the program ends

----

Run the project
```bash
    gcc main.c Lista.c RLista.c Pessoa.c Hashing.c RHashing.c Biblioteca.c texto.c Uteis.c Requisicao.c Livro.c Plista.c hashrequisicoes.c LFreguesia.c LConcelho.c LDistrito.c Freguesia.c Concelho.c Distrito.c -o main
```
