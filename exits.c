#include "shell.h"

/**
 *  **_strncpy - copies a string
 *   *@dest: the dest string to be copied to
 *    *@src: the source string
 *     *@n: the amt of char to be copied
 *      *Return: the concatend string
 *       */
char *_strncpy(char *dest, char *src, int n)
{
	int m, k;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		k = m;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 *  **_strncat - concatenates two strings
 *   *@dest: the 1st string
 *    *@src: the 2nd string
 *     *@n: the amt of bytes to be maximally used
 *      *Return: the concatend string
 *       */
char *_strncat(char *dest, char *src, int n)
{
	int m, r;
	char *s = dest;

	m = 0;
	r = 0;
	while (dest[m] != '\0')
		m++;
	while (src[r] != '\0' && j < n)
	{
		dest[m] = src[r];
		m++;
		r++;
	}
	if (r < n)
		dest[m] = '\0';
	return (s);
}

/**
 *  **_strchr - locates a char in a string
 *   *@s: the string to be parsed
 *    *@c: the char to look for
 *     *Return: (s) a pointer to the memory area s
 *      */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}#include "shell.h"

/**
 *  **_strncpy - copies a string
 *   *@dest: the dest string to be copied to
 *    *@src: the source string
 *     *@n: the amt of char to be copied
 *      *Return: the concatend string
 *       */
char *_strncpy(char *dest, char *src, int n)
{
	int m, k;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		k = m;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 *  **_strncat - concatenates two strings
 *   *@dest: the 1st string
 *    *@src: the 2nd string
 *     *@n: the amt of bytes to be maximally used
 *      *Return: the concatend string
 *       */
char *_strncat(char *dest, char *src, int n)
{
	int m, r;
	char *s = dest;

	m = 0;
	r = 0;
	while (dest[m] != '\0')
		m++;
	while (src[r] != '\0' && j < n)
	{
		dest[m] = src[r];
		m++;
		r++;
	}
	if (r < n)
		dest[m] = '\0';
	return (s);
}

/**
 *  **_strchr - locates a char in a string
 *   *@s: the string to be parsed
 *    *@c: the char to look for
 *     *Return: (s) a pointer to the memory area s
 *      */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
