#include "main.h"

/**
 * _strncmp - Compare two strings up to n characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal, negative if s1 is less than s2,
 * positive if s1 is greater than s2.
 */
int _strncmp(char *s1, char *s2, int n) {
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }

    if (n == 0) {
        return 0;
    }

    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
