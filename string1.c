#include "shell.h"
/**
 * _strcpy – copy of the str
 * @dest: the dest
 * @src: the src
 *
 * Return: ptr to the dest
 */
char *_strcpy(char *dest, char *src)
{
        int y = 0;
        if (dest == src || src == 0)
                return (dest);
        while (src[y])
        {
                dest[y] = src[y];
                y++;
        }
        dest[y] = 0;
        return (dest);
}
/**
 * _strdup - dup the str
 * @str: str to be duplicated
 *
 * Return: ptr to duplicated string
 */
char *_strdup(const char *str)
{
        int h = 0;
        char *t;
        if (str == NULL)
                return (NULL);
        while (*str++)
                h++;
        t = malloc(sizeof(char) * (h + 1));
        if (!t)
                return (NULL);
        for (h++; h--;)
                ret[h] = *--str;
        return (t);
}
/**
 * _puts - print the input str
 * @str: str to the print
 *
 * Return: Null
 */
void _puts(char *str)
{
        int x = 0;
        if (!str)
                return;
        while (str[x] != '\0')
        {
                _putchar(str[x]);
                x++;
        }
}
/**
 * _putchar - writes the char to the standout
 * @c: char to be printed
 *
 * Return: if successful one
 *  error then -1 will be returned, the error is set
 */
int _putchar(char c)
{
        static int v;
        static char buf[WRITE_BUF_SIZE];
        if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
        {
                write(1, buf, v);
                v = 0;
        }
        if (c != BUF_FLUSH)
                buf[v++] = c;
        return (1);
}
