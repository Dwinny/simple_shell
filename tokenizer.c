#include "shell.h"
/**
 * ***strtow – split the str to words
 * *@str: input str
 * *@d: deli str
 ** Return: ptr to array of str, else zero
 */
char **strtow(char *str, char *d)
{
	int a, c, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
	if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
		numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, c = 0; c < numwords; c++)
	{
		while (is_delim(str[a], d))
			a++;
		k = 0;
		while (!is_delim(str[a + k], d) && str[a + k])
			k++;
		s[c] = malloc((k + 1) * sizeof(char));
		if (!s[c])
		{
			for (k = 0; k < c; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[c][m] = str[a++];
		s[c][m] = 0;
	}
	s[c] = NULL;
	return (s);
}
/**
 * ***strtow2 - split str to words
 * *@str: input str
 * *@d: deli str
 * *Return: ptr to array of the str, else zero
 */
char **strtow2(char *str, char d)
{
	int b, j, k, w, num = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (b = 0; str[b] != '\0'; b++)
		if ((str[b] != d && str[b + 1] == d) ||
				(str[b] != d && !str[b + 1]) || str[b + 1] == d)
			num++;
	if (num == 0)
		return (NULL);
	s = malloc((1 + num) * sizeof(char *));
	if (!s)
		return (NULL);
	for (b = 0, j = 0; j < num; j++)
	{
		while (str[b] == d && str[b] != d)
			b++;
		k = 0;
		while (str[b + k] != d && str[b + k] && str[b + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (w = 0; w < k; w++)
			s[j][w] = str[b++];
		s[j][w] = 0;
	}
	s[j] = NULL;
	return (s);
}
