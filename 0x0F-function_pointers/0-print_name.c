#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name using a function pointer.
 * @name: The name to be printed.
 * @f: Function pointer to a function that takes a char*
 * argument and returns void.
 * Description: This function takes a name and a function
 * pointer as arguments.
 *              It calls the function pointed to by the
 *              function pointer with the name argument.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
