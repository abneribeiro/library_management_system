#include "Uteis.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//necess�rio p/ fun��o time()
#include <ctype.h>
#include <string.h>
#include "RHashing.h"


int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int Factorial(int N)
{
    if (N == 0) return 1;
    return N * Factorial(N-1);
}

int LerInteiro(char *txt)
{
    int x;
    printf("%s : ", txt);
    scanf("%d", &x);
    return x;
}

char *str_to_upper(char *str) {
    char *ptr = str;
    while (*ptr) {
        *ptr = toupper((unsigned char)*ptr);
        ptr++;
    }
    return str;
}

int is_blank(const char *str) {
    while (*str) {
        if (!isspace((unsigned char)*str))
            return 0; // false
        str++;
    }
    return 1; // true
}



int calculateAge(char *birth_date) {
    // Extract the year from the birth_date string
    char year[5];
    strncpy(year, &birth_date[6], 4);
    year[5] = '\0'; // Null terminate the string
    // Convert the year string to an integer
    int birth_year = atoi(year);

    // Get the current year
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int current_year = tm->tm_year + 1900;

    // Calculate and return the age
    int Age = current_year - birth_year;
    return Age;
}



struct tm calcularPascoa(int ano) {
    int a = ano % 19;
    int b = ano / 100;
    int c = ano % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int mes = (h + l - 7 * m + 114) / 31;
    int dia = ((h + l - 7 * m + 114) % 31) + 1;

    struct tm pascoa = {0};
    pascoa.tm_year = ano - 1900;
    pascoa.tm_mon = mes - 1;
    pascoa.tm_mday = dia;
    pascoa.tm_isdst = -1;

    return pascoa;
}