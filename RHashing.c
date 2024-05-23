#include <string.h>
#include <conio.h>
#include "RHashing.h"
#include "Pessoa.h"
#include "RLista.h"
#include "Uteis.h"



RLISTA_CHAVES *CriarRListaCHAVES()
{
    RLISTA_CHAVES *R = (RLISTA_CHAVES *)malloc(sizeof(RLISTA_CHAVES));
    R->NEL = 0;
    R->Inicio = NULL;
    return R;
}

void AddROrdenado(RLISTA *L, PESSOA *P)
{
    if (!L)
        return;

    RNO *novo = (RNO *)malloc(sizeof(RNO));
    novo->Info = P;
    novo->Prox = NULL;

    if (L->Inicio == NULL || strcmp(L->Inicio->Info->NOME, P->NOME) > 0)
    {
        // Inserir no início da lista
        novo->Prox = L->Inicio;
        L->Inicio = novo;
    }
    else
    {
        // Encontrar o nó anterior ao ponto de inserção
        RNO *current = L->Inicio;
        while (current->Prox != NULL && strcmp(current->Prox->Info->NOME, P->NOME) < 0)
        {
            current = current->Prox;
        }
        // Inserir após o nó atual
        novo->Prox = current->Prox;
        current->Prox = novo;
    }

    L->NEL++;
}

RNO_CHAVE *RAddCHAVE(RLISTA_CHAVES *L, char *key)
{
    if (!L)
        return NULL;
    RNO_CHAVE *aux = (RNO_CHAVE *)malloc(sizeof(RNO_CHAVE));
    aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(aux->KEY, key);
    aux->DADOS = CriarRLista();
    aux->Prox = NULL;

    // Inserir a chave na posição correta para manter a lista em ordem alfabética
    if (L->Inicio == NULL || strcmp(L->Inicio->KEY, key) > 0)
    {
        // Inserir no início da lista
        aux->Prox = L->Inicio;
        L->Inicio = aux;
    }
    else
    {
        // Encontrar o nó anterior ao ponto de inserção
        RNO_CHAVE *current = L->Inicio;
        while (current->Prox != NULL && strcmp(current->Prox->KEY, key) < 0)
        {
            current = current->Prox;
        }
        // Inserir após o nó atual
        aux->Prox = current->Prox;
        current->Prox = aux;
    }

    L->NEL++;
    return aux;
}

RHASHING *CriarRHashing()
{
    RHASHING *RHas = (RHASHING *)malloc(sizeof(RHASHING));
    RHas->RLChaves = CriarRListaCHAVES();
    return RHas;
}

void DestruirRHashing(RHASHING *H)
{
    if (!H)
        return;
    RNO_CHAVE *Seguinte;
    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirRLista(P->DADOS);
        free(P->KEY);
        free(P);
        P = Seguinte;
    }
    free(H);
}

void AddRHashing(RHASHING *H, PESSOA *P)
{
    if (!H || !H->RLChaves)
        return;

    char key[2] = {P->NOME[0], '\0'};

    RNO_CHAVE *Key_colocar = FuncaoRHashing(H, key);
    if (!Key_colocar)
    {
        Key_colocar = RAddCHAVE(H->RLChaves, key);
    }
    AddROrdenado(Key_colocar->DADOS, P);
}

int CompararChaves(const void *a, const void *b)
{
    RNO_CHAVE *chaveA = *(RNO_CHAVE **)a;
    RNO_CHAVE *chaveB = *(RNO_CHAVE **)b;
    return strcmp(chaveA->KEY, chaveB->KEY);
}

void ShowRHashing(RHASHING *H, int numToShow)
{
    if (!H || !H->RLChaves)
        return;

    int numKeys = H->RLChaves->NEL;
    RNO_CHAVE **array = (RNO_CHAVE **)malloc(numKeys * sizeof(RNO_CHAVE *));
    RNO_CHAVE *P = H->RLChaves->Inicio;

    for (int i = 0; i < numKeys; i++)
    {
        array[i] = P;
        P = P->Prox;
    }

    qsort(array, numKeys, sizeof(RNO_CHAVE *), CompararChaves);

    int count = 0;
    for (int i = 0; i < numKeys; i++)
    {
        printf("Chave: %s\n", array[i]->KEY);
        ShowRLista(array[i]->DADOS);
        count++;
        if (count >= numToShow)
        {
            printf(".Pressione qualquer tecla para continuar...\n");
            while (!_kbhit())
            {
            } // Aguarda a pressão de uma tecla
            _getch(); // Limpa a tecla pressionada do buffer
            count = 0;
        }
    }
    free(array);
}

RNO_CHAVE *FuncaoRHashing(RHASHING *H, char *key)
{
    if (!H || !H->RLChaves)
        return NULL;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (stricmp(P->KEY, key) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}

int mostCommonAge(RHASHING *H)
{
    if (H == NULL || H->RLChaves == NULL)
        return -1;

    int age_counts[170] = {0};
    int max_age = 0;
    int max_age_count = 0;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (P->DADOS == NULL)
        {
            P = P->Prox;
            continue;
        }

        RNO *person_node = P->DADOS->Inicio;
        while (person_node)
        {
            if (person_node->Info == NULL)
            {
                person_node = person_node->Prox;
                continue;
            }

            int age = calculateAge(person_node->Info->DATA_NASCIMENTO);
            printf("Age: %d\n", age);
            if (age >= 0 && age < 170)
            {
                age_counts[age]++;
                if (age_counts[age] > max_age_count)
                {
                    max_age = age;
                    max_age_count = age_counts[age];
                }
            }
            person_node = person_node->Prox;
        }

        P = P->Prox;
    }
    return max_age;
}

int countPeopleAboveAge(RHASHING *H, int age_limit)
{
    if (H == NULL || H->RLChaves == NULL)
        return -1;

    int count = 0;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (P->DADOS == NULL)
        {
            P = P->Prox;
            continue;
        }

        RNO *person_node = P->DADOS->Inicio;
        while (person_node)
        {
            if (person_node->Info == NULL)
            {
                person_node = person_node->Prox;
                continue;
            }

            int age = calculateAge(person_node->Info->DATA_NASCIMENTO);
            if (age > age_limit)
            {
                count++;
            }
            person_node = person_node->Prox;
        }

        P = P->Prox;
    }
    return count;
}

int maxAge(RHASHING *H)
{
    if (H == NULL || H->RLChaves == NULL)
        return -1;

    int max_age = 0;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (P->DADOS == NULL)
        {
            P = P->Prox;
            continue;
        }

        RNO *person_node = P->DADOS->Inicio;
        while (person_node)
        {
            if (person_node->Info == NULL)
            {
                person_node = person_node->Prox;
                continue;
            }

            int age = calculateAge(person_node->Info->DATA_NASCIMENTO);

            if (age > 500)
            {
                printf("prob na Age (%d) do utilizador [%d]\n", age, person_node->Info->ID);
                system("pause");
            }


            if (age > max_age)
            {
                max_age = age;
            }
            person_node = person_node->Prox;
        }

        P = P->Prox;
    }
    return max_age;
}

double averageAge(RHASHING *H)
{
    if (H == NULL || H->RLChaves == NULL)
        return -1;

    int total_age = 0;
    int total_people = 0;

    RNO_CHAVE *P = H->RLChaves->Inicio;
    while (P)
    {
        if (P->DADOS == NULL)
        {
            P = P->Prox;
            continue;
        }

        RNO *person_node = P->DADOS->Inicio;
        while (person_node)
        {
            if (person_node->Info == NULL)
            {
                person_node = person_node->Prox;
                continue;
            }

            int age = calculateAge(person_node->Info->DATA_NASCIMENTO);
            total_age += age;
            total_people++;
            person_node = person_node->Prox;
        }

        P = P->Prox;
    }
    return total_people == 0 ? -1 : (double)total_age / total_people;
}


PESSOA *ProcurarRequisitanteRHASHING(RHASHING *H, char *nome)
{
    if (!H)
        return NULL;

    RNO_CHAVE *currentKey = H->RLChaves->Inicio;
    while (currentKey != NULL)
    {
        RNO *currentData = currentKey->DADOS->Inicio;
        while (currentData != NULL)
        {
            if (strcasecmp(currentData->Info->NOME, nome) == 0)
            {
                // Requisitante encontrado
                return currentData->Info;
            }
            currentData = currentData->Prox;
        }
        currentKey = currentKey->Prox;
    }

    // Requisitante não encontrado
    return NULL;
}

void VerificarRequisitanteRHASHING(RHASHING *H, char *nome)
{
    PESSOA *requisitante = ProcurarRequisitanteRHASHING(H, nome);
    if (requisitante != NULL)
    {
        printf("Requisitante encontrado: %s\n", requisitante->NOME);
    }
    else
    {
        printf("Requisitante nao encontrado\n");
    }
}



char *MostUsedSurnameRHASHING(RHASHING *H)
{
    if (!H)
        return NULL;

    // Initialize the dictionary
    struct dict {
        char *key;
        int value;
    } dict[1000]; // Assuming there won't be more than 1000 unique surnames
    int dictSize = 0;

    RNO_CHAVE *currentKey = H->RLChaves->Inicio;
    while (currentKey != NULL)
    {
        RNO *currentData = currentKey->DADOS->Inicio;
        while (currentData != NULL)
        {
            // Split the full name into words
            char *name = strdup(currentData->Info->NOME);
            char *surname = NULL;
            char *word = strtok(name, " ");
            while (word != NULL)
            {
                surname = word;
                word = strtok(NULL, " ");
            }

            // Increment the count of the surname or add it to the dictionary
            int found = 0;
            for (int i = 0; i < dictSize; i++)
            {
                if (strcmp(dict[i].key, surname) == 0)
                {
                    dict[i].value++;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                dict[dictSize].key = strdup(surname);
                dict[dictSize].value = 1;
                dictSize++;
            }

            free(name);
            currentData = currentData->Prox;
        }
        currentKey = currentKey->Prox;
    }

    // Find the most used surname
    char *mostUsedSurname = NULL;
    int maxCount = 0;
    for (int i = 0; i < dictSize; i++)
    {
        if (dict[i].value > maxCount)
        {
            mostUsedSurname = dict[i].key;
            maxCount = dict[i].value;
        }
    }

    return mostUsedSurname;
}


