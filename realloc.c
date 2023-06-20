#include "shell.h"
/**
 * *_memset – fill the memory with the constant bit
 * *@s: pointer to the memo area
 * *@b: bit to fill s with
 * *@n: amount of bits to fill
 * *Return: s pointer to memo area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int y;

	for (y = 0; y < n; y++)
		s[y] = b;
	return (s);
}
/**
 * *ffree - free str of strs
 * *@pp: str of strs
 */
void ffree(char **pp)
{
	char **x = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(x);
}
/**
 * *_realloc - reallocate block of the memo
 * *@ptr: ptr to the prev malloc block
 * *@old_size: bit of size of the prev block
 * *@new_size: bit size of the new block
 **
 * *Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *b;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	b = malloc(new_size);
	if (!b)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		b[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (b);
}
