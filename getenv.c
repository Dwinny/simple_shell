#include "shell.h"
/**
 * get_environ – this returns a string array copy of env
 * @info: this structure that contains the potential arguments.
 * Return: zero
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
		return (info->environ);
}
/**
 * _unsetenv – this will remove the environ var
 * @info: this structure that contains the potential arguments.
 *  Return: one to delete, else zero
 * @var: str environ for the variable properties
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t b = 0;
	char *y;

	if (!node || !var)
		return (0);
	while (node)
	{
		y = starts_with(node->str, var);
		if (y && *y == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), b);
			b = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		b++;
	}
	return (info->env_changed);
}
/**
 * _setenv – this Initializes the new envi var
 * @info: this structure that contains the potential arguments.
 * @var: string of the environment variable
 * @value: string of the environment variable value
 *  Return: zero
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *f = NULL;
	char *b;
	list_t *node;

	if (!var || !value)
		return (0);
	f = malloc(_strlen(var) + _strlen(value) + 2);
	if (!f)
		return (1);
	_strcpy(f, var);
	_strcat(f, "=");
	_strcat(f, value);
	node = info->env;
	while (node)
	{
		b = starts_with(node->str, var);
		if (b && *b == '=')
		{
			free(node->str);
			node->str = f;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), f, 0);
	free(f);
	info->env_changed = 1;
	return (0);
}
