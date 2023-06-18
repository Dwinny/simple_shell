#include "shell.h"

/**
 *  * list_len - determines length of linked list
 *   * @h: pointer to 1st node
 *    * Return: size of list
 *     */
size_t list_len(const list_t *h)
{
	size_t m = 0;

	while (h)
	{
		h = h->next;
		m++;
	}
	return (m);
}

/**
 *  * list_to_strings - returns an array of strings of the list->str
 *   * @head: pointer to 1st node
 *    * Return: array of strings
 *     */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t q = list_len(head), d;
	char **strs;
	char *str;

	if (!head || !q)
		return (NULL);
	strs = malloc(sizeof(char *) * (q + 1));
	if (!strs)
		return (NULL);
	for (q = 0; node; node = node->next, q++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (d = 0; d < q; d++)
				free(strs[d]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[q] = str;
	}
	strs[q] = NULL;
	return (strs);
}


/**
 *  * print_list - prints all elements of a list_t linked list
 *   * @h: pointer to 1st node
 *    * Return: size of list
 *     */
size_t print_list(const list_t *h)
{
	size_t d = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		d++;
	}
	return (d);
}

/**
 *  * node_starts_with - returns node whose string starts with prefix
 *   * @node: pointer to list head
 *    * @prefix: string to match
 *     * @c: the next char after prefix to match
 *      * Return: match node or null
 *       */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 *  * get_node_index - gets the index of a node
 *   * @head: pointer to ls head
 *    * @node: pointer to the node
 *     * Return: index of node or -1
 *      */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t m = 0;

	while (head)
	{
		if (head == node)
			return (m);
		head = head->next;
		m++;
	}
	return (-1);
}#include "shell.h"

/**
 *  * list_len - determines length of linked list
 *   * @h: pointer to 1st node
 *    * Return: size of list
 *     */
size_t list_len(const list_t *h)
{
	size_t m = 0;

	while (h)
	{
		h = h->next;
		m++;
	}
	return (m);
}

/**
 *  * list_to_strings - returns an array of strings of the list->str
 *   * @head: pointer to 1st node
 *    * Return: array of strings
 *     */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t q = list_len(head), d;
	char **strs;
	char *str;

	if (!head || !q)
		return (NULL);
	strs = malloc(sizeof(char *) * (q + 1));
	if (!strs)
		return (NULL);
	for (q = 0; node; node = node->next, q++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (d = 0; d < q; d++)
				free(strs[d]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[q] = str;
	}
	strs[q] = NULL;
	return (strs);
}


/**
 *  * print_list - prints all elements of a list_t linked list
 *   * @h: pointer to 1st node
 *    * Return: size of list
 *     */
size_t print_list(const list_t *h)
{
	size_t d = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		d++;
	}
	return (d);
}

/**
 *  * node_starts_with - returns node whose string starts with prefix
 *   * @node: pointer to list head
 *    * @prefix: string to match
 *     * @c: the next char after prefix to match
 *      * Return: match node or null
 *       */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 *  * get_node_index - gets the index of a node
 *   * @head: pointer to ls head
 *    * @node: pointer to the node
 *     * Return: index of node or -1
 *      */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t m = 0;

	while (head)
	{
		if (head == node)
			return (m);
		head = head->next;
		m++;
	}
	return (-1);
}
