#include "shell.h"

/**
 *  * _eputs - prints an input string
 *   * @str: the string to be printed
 *    * Return: 0
 */
void _eputs(char *str)
{
	int s = 0;

	if (!str)
		return;
	while (str[s] != '\0')
	{
		_eputchar(str[s]);
		s++;
	}
}

/**
 *  * _eputchar - writes the char c to standard error
 *   * @c: The char to print
 *    * Return: 1 on success.
 *     * return -1 on error, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 *  * _putfd - writes the char c to given fd
 *   * @c: The char to print
 *    * @fd: The fdescriptor to write to
 *     * Return:1 on success.
 *      * return -1 on error, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(fd, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}

/**
 *  * _putsfd - prints an input string
 *   * @str: the string to be printed
 *    * @fd: the fdescriptor to write to
 *     * Return: the num of chars put
 */
int _putsfd(char *str, int fd)
{
	int n = 0;

	if (!str)
		return (0);
	while (*str)
	{
		n += _putfd(*str++, fd);
	}
	return (n);
}
