#include "shell.h"
/**
 * _myenv – it prints out its current environ
 * @info: this is the structure that contains potential arguments
 * Return: zero
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv – it gets value of environment var
 * @info: this is the structure that contains the potential arguments.
 * @name: environ name
 *
 * Return: val
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv – this Initializes an environ var
 * @info: the structure that contains the potential arguments.
 *  Return: zero
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv – this removes an envi var
 * @info:the Structure that contains potential arguments.
 * Return:zero
 */
int _myunsetenv(info_t *info)
{
	int u;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (u = 1; u <= info->argc; u++)
		_unsetenv(info, info->argv[u]);
	return (0);
}
/**
 * populate_env_list - this populate the environment list
 * @info: Structure containing potential arguments.
 * Return: zero
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t s;

	for (s = 0; environ[s]; s++)
		add_node_end(&node, environ[s], 0);
	info->env = node;
	return (0);
}
