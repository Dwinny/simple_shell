#include "shell.h"

/**
 *  * _erratoi - converts a string to an int
 *   * @s: the string to be converted
 *    * Return: 0 if no numbs in string, converted numbs otherwise
 *     * return -1 on error
 *      */
int _erratoi(char *s)
{
	int m = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (m = 0;  s[m] != '\0'; m++)
	{
		if (s[m] >= '0' && s[m] <= '9')
		{
			result *= 10;
			result += (s[m] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 *  * print_error - prints an err message
 *   * @info: the parameter and R info struct
 *    * @estr: string containing specified err type
 *     * Return: 0 if no numbers in string, converted number otherwise
 *      * return -1 on err
 *       */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 *  * print_d - funct prints a decimal (int) numb (base 10)
 *   * @input: the input
 *    * @fd: the fdescriptor to write to
 *     * Return: numb of chars printed
 *      */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int m, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (m = 1000000000; m > 1; m /= 10)
	{
		if (_abs_ / m)
		{
			__putchar('0' + current / m);
			count++;
		}
		current %= m;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 *  * convert_number - converter funct, a clone of itoa
 *   * @num: number
 *    * @base: base
 *     * @flags: argument flags
 *      * Return: string
 *       */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long i = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		i /= base;
	} while (i != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 *  * remove_comments - funct replaces 1st instance of '#' with '\0'
 *   * @buf: address of the string to modify
 *    * Return: 0;
 *     */
void remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}#include "shell.h"

/**
 *  * _erratoi - converts a string to an int
 *   * @s: the string to be converted
 *    * Return: 0 if no numbs in string, converted numbs otherwise
 *     * return -1 on error
 *      */
int _erratoi(char *s)
{
	int m = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (m = 0;  s[m] != '\0'; m++)
	{
		if (s[m] >= '0' && s[m] <= '9')
		{
			result *= 10;
			result += (s[m] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 *  * print_error - prints an err message
 *   * @info: the parameter and R info struct
 *    * @estr: string containing specified err type
 *     * Return: 0 if no numbers in string, converted number otherwise
 *      * return -1 on err
 *       */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 *  * print_d - funct prints a decimal (int) numb (base 10)
 *   * @input: the input
 *    * @fd: the fdescriptor to write to
 *     * Return: numb of chars printed
 *      */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int m, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (m = 1000000000; m > 1; m /= 10)
	{
		if (_abs_ / m)
		{
			__putchar('0' + current / m);
			count++;
		}
		current %= m;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 *  * convert_number - converter funct, a clone of itoa
 *   * @num: number
 *    * @base: base
 *     * @flags: argument flags
 *      * Return: string
 *       */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long i = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		i /= base;
	} while (i != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 *  * remove_comments - funct replaces 1st instance of '#' with '\0'
 *   * @buf: address of the string to modify
 *    * Return: 0;
 *     */
void remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}
