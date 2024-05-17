
#include "Uteis.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//necess�rio p/ fun��o time()
#include <ctype.h>


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

int is_blank(char *str) {
    while (*str) {
        if (!isspace((unsigned char)*str))
            return 0; // false
        str++;
    }
    return 1; // true
}


#define CLEAR_BUFFER while ((ch = getchar()) != '\n' && ch != EOF)