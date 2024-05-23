#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



bool ValidarID(char *id)
{
    size_t len = strlen(id);
    int sum = 0;

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
        sum += id[i] - '0'; // convert char to int and add to sum
    }

    // Check if sum is a multiple of 10
    if (sum % 10 != 0)
    {
        return false;
    }

    return true;
}


// Improved ValidarNome
bool ValidarNome(char *nome)
{
    int len = strlen(nome);
    for (int i = 0; i < len; i++)
    {
        if (!((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == ' ' || nome[i] == '-' || nome[i] == '\''))
        {
            return false;
        }
    }
    return true;
}



bool ValidarDataNascimento(char *data)
{
    struct tm tm;
    if (sscanf(data, "%d-%d-%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) != 3)
    {
        return false;
    }
    int actualYear = tm.tm_year; // Save the actual year for leap year check
    tm.tm_year -= 1900; // tm_year is years since 1900
    tm.tm_mon--;        // tm_mon is months since January (0-11)
    // Check if the date is logical
    if (tm.tm_mday < 1 || tm.tm_mday > 31 || tm.tm_mon < 0 || tm.tm_mon >= 12)
    {
        return false;
    }
    // Corrected the months to check for 30 days
    if ((tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10) && tm.tm_mday > 30)
    {
        return false;
    }
    // Corrected the leap year check for February
    if (tm.tm_mon == 1)
    {
        if (((actualYear % 4 == 0 && actualYear % 100 != 0) || actualYear % 400 == 0) && tm.tm_mday > 29)
        {
            return false;
        }
        if (!(actualYear % 4 == 0 && actualYear % 100 != 0) && !(actualYear % 400 == 0) && tm.tm_mday > 28)
        {
            return false;
        }
    }
    return true;
}


// Improved ValidarIDFreguesia
bool ValidarIDFreguesia(char *idFreguesia)
{
    size_t len = strlen(idFreguesia);
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