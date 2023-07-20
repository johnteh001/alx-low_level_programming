#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/* Struct op - Represents an operation and its corresponding function */
typedef struct op
{
    char *op;
    void (*f)(va_list);
} op_t;
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

void print_int(va_list args);
void print_float(va_list args);
void print_char(va_list args);
void print_string(va_list args);

#endif /* VARIADIC_FUNCTIONS_H */
