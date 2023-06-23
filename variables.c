#include "shell.h"

/**
 *  * is_chain - test if current character in buffer is a chain delimeter
 *   * @info: the parameter structure
 *    * @buf: the character buffer
 *     * @p: address of current position in buffer
 *      * Return: 1 if chain delimeter, 0 if it fail
 *       */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t a = *p;

	if (buf[a] == '|' && buf[a + 1] == '|')
	{
		buf[a] = 0;
		a++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[a] == '&' && buf[a + 1] == '&')
	{
		buf[a] = 0;
		a++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[a] == ';') /* found end of this command */
	{
		buf[a] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = a;
	return (1);
}

/**
 *  * check_chain - checks we should continue chaining based on last status
 *   * @info: the parameter structure
 *    * @buf: the character buffer
 *     * @p: address of current position in buffer
 *      * @i: starting position in buffer
 *       * @len: length of buffer
 *        * Return: Void
 *         */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t a = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			a = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			a = len;
		}
	}

	*p = a;
}

/**
 *  * replace_alias - replaces an aliases in the tokenized string
 *   * @info: the parameter structure
 *    * Return: 1 if replaced, 0 if it fail
 *     */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 *  * replace_vars - replaces vars in the tokenized string
 *   * @info: the parameter structure
 *    * Return: 1 if replaced, 0 if it fails
 *     */
int replace_vars(info_t *info)
{
	int b = 0;
	list_t *node;

	for (b = 0; info->argv[b]; b++)
	{
		if (info->argv[b][0] != '$' || !info->argv[b][1])
			continue;
		if (!_strcmp(info->argv[b], "$?"))
		{
			replace_string(&(info->argv[b]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[b], "$$"))
		{
			replace_string(&(info->argv[b]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[b][1], '=');
		if (node)
		{
			replace_string(&(info->argv[b]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[b], _strdup(""));

	}
	return (0);
}

/**
 *  * replace_string - replaces string
 *   * @old: address of old string
 *    * @new: new string
 *     *
 *      * Return: 1 if replaced, 0 otherwise
 *       */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
