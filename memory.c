#include "shell.h"

/**
 *  * bfree - Frees a pointer whereby NULLs the address
 *   * @ptr: address of the pointer to free
 *    * Return: 1 if pointer is freed and 0 if pointer is not freed
 *     */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
