#include "main.h"
/**
 * _strstr - Locates a substring
 * @haystack: The string to search
 * @needle: The substring to locate
 *
 * Return: The pointer to the beginning of the located substring, or NULL if
 *         the substring is not found.
 */
char *_strstr(char *haystack, char *needle) {
    int len_needle = _strlen(needle);

    while (*haystack) {
        if (_strncmp(haystack, needle, len_needle) == 0) {
            return haystack;
        }
        haystack++;
    }

    return NULL;
}
