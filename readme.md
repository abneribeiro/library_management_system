**GOALS**

- [X] Criar Menu
- [x] Carregar Dados de Ficheiros
- [x] Validação de Dados "requisitantes.txt"
- [x] Registar erros de dados errados em "logs.txt" e descartar os mesmos
- [ ] Registar info de livros, requesitantes, requesições (no momento ou ao fim do programa)
- [ ] **Gerir os livros**
    - [x] Adicionar livros
    - [x] Listar livros
    - [x] Determinar qual a área com mais livros
    - [x] Verificar se livro existe(ISBN), se existe -> mostra dados
    - [x] Determinar livro/s mais recente/s(ano)
    - [ ] Determinar qual o livro mais requisitado (Se existir mais do que um, deve devolver o primeiro encontrado); 
    - [ ] Determinar area + requisitada(return a 1ª encontrada)
- [ ] **Gerir lista de requesitantes**
    - [ ] Adicionar requesitantes
    - [X] Check se visitante existe(return nome)
    - [X] Listar clientes
    - [X] Idade maxima de tds requesitantes
    - [X] Idade média de tds requesitantes
    - [X] Nº de pessoas com idade > x
    - [X] Determinar a idade com mais requesitantes
    - [ ] Mostrar as requisições de um dado requisitante
    - [ ] Devolver uma lista das pessoas que nunca requisitaram nada
    - [X] Listar os requisitantes que no momento têm livros requisitados
    - [X] Determinar qual o sobrenome mais usado pelos requisitantes;
    - [ ] **Listar requisitantes que nasceram num Domingo (ou cujo aniversário num determinado ano é ao Domingo);**
    - [ ] **Listar requisitantes cujo aniversário, num determinado ano, é na quaresma (entre o Carnaval e a Páscoa), (ou que nasceram na quaresma).**
- [ ] **Gerir Requesições de Livros**
    - [ ] Requesitar Livro
    - [ ] Devolver Livro Requesitado
    - [ ] Listar Livros Requesitados
- [ ] Determinar a memória ocupada por toda a Estrutura de Dados
- [ ] Gravar toda a informação para um dado ficheiro XML, cujo nome é introduzido pelo utilizador;
- [ ] Libertar toda memoria usadas pelas estruturas antes do programa terminar

----
Dúvidas:
1. As funções necessárias para o hashing devem estar nos ficheiros hashing.h e hashing.c / o que é ?? 

Executar o projecto
```bash
    gcc main.c Lista.c RLista.c Pessoa.c Hashing.c RHashing.c Biblioteca.c texto.c Uteis.c Requisicao.c Livro.c Plista.c hash_requisicoes.c -o main
```




### Ver memoria alocada..