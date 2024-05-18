#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

// Validação do ID
bool ValidarID(char *id)
{
    int len = strlen(id);
    if (len != 9)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (id[i] < '0' || id[i] > '9')
        {
            return false;
        }
    }
    return true;
}

// Validação do nome
bool ValidarNome(char *nome)
{
    int len = strlen(nome);
    for (int i = 0; i < len; i++)
    {
        if (!((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == ' '))
        {
            return false;
        }
    }
    return true;
}

// Validação da data de nascimento


bool ValidarDataNascimento(char *data)
{
    struct tm tm;
    if (sscanf(data, "%d-%d-%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) != 3)
    {
        return false;
    }
    tm.tm_year -= 1900; // tm_year is years since 1900
    tm.tm_mon--;        // tm_mon is months since January (0-11)
    // Check if the date is logical
    if (tm.tm_mday > 31 || tm.tm_mon >= 12)
    {
        return false;
    }
    if ((tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10) && tm.tm_mday > 30)
    {
        return false;
    }
    if (tm.tm_mon == 1 && ((tm.tm_year % 4 == 0 && tm.tm_year % 100 != 0) || tm.tm_year % 400 == 0) && tm.tm_mday > 29)
    {
        return false;
    }
    if (tm.tm_mon == 1 && tm.tm_year % 4 != 0 && tm.tm_mday > 28)
    {
        return false;
    }
    return true;
}


// Validação do ID da freguesia
bool ValidarIDFreguesia(char *idFreguesia)
{
    int len = strlen(idFreguesia);
    if (len != 6)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (idFreguesia[i] < '0' || idFreguesia[i] > '9')
        {
            return false;
        }
    }
    return true;
}