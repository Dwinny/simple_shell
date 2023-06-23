#include "shell.h"

/**
 *  * input_buf - bufs chained commands
 *   * @info: parameter structure
 *    * @buf: address of buf
 *     * @len: address of len var
 *      * Return: bytes read
 *       */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t m = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		m = getline(buf, &len_p, stdin);
#else
		m = _getline(info, buf, &len_p);
#endif
		if (m > 0)
		{
			if ((*buf)[m - 1] == '\n')
			{
				(*buf)[m - 1] = '\0'; /* remove trailing newline */
				m--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = m;
				info->cmd_buf = buf;
			}
		}
	}
	return (m);
}

/**
 *  * get_input - gets a line minus the newline
 *   * @info: parameter structure
 *    * Return: bytes read
 *     */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t m, s, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
				return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		s = m; /* init new iterator to current buf position */
		p = buf + m; /* get pointer for return */

		check_chain(info, buf, &s, m, len);
		while (s < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &s))
				break;
			s++;
		}

		m = s + 1; /* increment past nulled ';'' */
		if (m >= len) /* reached end of buffer? */
		{
			m = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 *  * read_buf - reads a buffer
 *   * @info: parameter struct
 *    * @buf: buffer
 *     * @i: size
 *      * Return: m
 *       */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t m = 0;

	if (*i)
		return (0);
	m = read(info->readfd, buf, READ_BUF_SIZE);
	if (m >= 0)
		*i = m;
	return (m);
}

/**
 *  * _getline - gets the next line of input from STDIN
 *   * @info: parameter structure
 *    * @ptr: address of pointer to buf, preallocated or NULL
 *     * @length: size of preallocated ptr buffer if not NULL
 *      * Return: a
 *       */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t d, len;
	size_t g;
	ssize_t e = 0, a = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		a = *length;
	if (d == len)
		d = len = 0;

	e = read_buf(info, buf, &len);
	if (e == -1 || (e == 0 && len == 0))
		return (-1);

	c = _strchr(buf + d, '\n');
	g = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, a, a ? a + g : g + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (a)
		_strncat(new_p, buf + d, g - d);
	else
		_strncpy(new_p, buf + d, g - d + 1);

	a += g - d;
	d = g;
	p = new_p;

	if (length)
		*length = a;
	*ptr = p;
	return (a);
}

/**
 *  * sigintHandler - blocks ctrl-C
 *   * @sig_num: the signal numb
 *    * Return: void
 *     */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
