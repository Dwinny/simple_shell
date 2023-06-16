#include "shell.h"
/**
 * _myhistory – it shows history list, 1 command by line, starting at 0.
 * @info: the structure which contains the potential arguments.
 * Return: zero
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to str
 * @info: para struct
 * @str: str alias
 *
 * Return: zero if successful, else one
 */
int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int t;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	t = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (t);
}
/**
 * set_alias - sets alias to str
 * @info: para struct
 * @str: stri alias
 *
 * Return: zero if successful, else one
 */
int set_alias(info_t *info, char *str)
{
	char *s;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	if (!*++s)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: zero if successful, else one
 */
int print_alias(list_t *node)
{
	char *x = NULL, *y = NULL;

	if (node)
	{
		x = _strchr(node->str, '=');
		for (y = node->str; y <= x; y++)
		_putchar(*y);
		_putchar('\'');
		_puts(x + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias – it mimic alias builtin
 * @info: the structure that contains the potential arguments.
 * Return: zero
 */
int _myalias(info_t *info)
{
	int b = 0;
	char *y = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (b = 1; info->argv[b]; b++)
	{
		y = _strchr(info->argv[b], '=');
		if (y)
			set_alias(info, info->argv[b]);
		else
			print_alias(node_starts_with(info->alias, info->argv[b], '='));
	}
	return (0);
}
