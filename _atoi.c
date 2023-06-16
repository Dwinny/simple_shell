#include "shell.h"
/**
 * interactive – it returns true only if the shell is in interactive mode
 * @info: the address
 *
 * Return: one when in interactive mode, else zero
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim – it checks if the char is delimeter
 * @c: character to be checked
 * @delim:string of delimeter
 * Return:one when true, else zero
 */
int is_delim(char c, char *delim)
{
	while (*delim)

		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha – this will check for alphabetic char
 * @c: This is the char to be inputed
 * Return: one only if alphabetic, else zero
 */
int _isalpha(int c)
{
	if ((c >= 'b' && c <= 'y') || (c >= 'B' && c <= 'Y'))
		return (1);
	else
		return (0);
}
/**
 * _atoi – it will convert a str to an int
 * @s: this is the str to be converted
 * Return: zero when no num is in str, else converted num
 */
int _atoi(char *s)
{
	int y, sign = 1, g = 0, output;
	unsigned int r = 0;

	for (y = 0; s[y] != '\0' && g != 2; y++)
	{
		if (s[y] == '-')
			sign *= -1;
		if (s[y] >= '0' && s[y] <= '9')
		{
			g = 1;
			r *= 10;
			r += (s[i] - '0');
		}
		else if (g == 1)
			g = 2;
	}
	if (sign == -1)
		output = -r;
	else
		output = r;
	return (output);
}
