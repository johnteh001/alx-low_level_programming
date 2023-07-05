#include <unistd.h>

/**
 * Putchar.c
 */
int _putchar(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}
