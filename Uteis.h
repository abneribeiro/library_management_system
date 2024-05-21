#ifndef UTEIS_H
#define UTEIS_H


int Aleatorio(int min, int max);
int Factorial(int N);
int LerInteiro(char *txt);
char *str_to_upper(char *str);
int is_blank(const char* s);
int calculateAge(char *birth_date);

#define CLEAR_BUFFER while ((ch = getchar()) != '\n' && ch != EOF)


#endif // UTEIS_H