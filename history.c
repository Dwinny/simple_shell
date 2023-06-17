#include "shell.h"
/**
 * get_history_file – it gets all the history file
 * @info: the para of struct
 *
 * Return: this will allocate str which contains the history file
 */
char *get_history_file(info_t *info)
{
	char *f, *r;

	r = _getenv(info, "HOME=");
	if (!r)
		return (NULL);
	f = malloc(sizeof(char) * (_strlen(r) + _strlen(HIST_FILE) + 2));
	if (!f)
		return (NULL);
	f[0] = 0;
	_strcpy(f, r);
	_strcat(f, "/");
	_strcat(f, HIST_FILE);
	return (f);
}
/**
 * write_history – this creates the file, or will append an existing file
 * @info: this is the para struct
 *
 * Return: one if successful, -1 otherwise
 */
int write_history(info_t *info)
{
	ssize_t d;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	d = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (d == -1)
	return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, d);
		_putfd('\n', d);
	}
	_putfd(BUF_FLUSH, d);
	close(d);
	return (1);
}
/**
 * read_history - reads the history from the file
 * @info: this is the para struct
 *
 * Return: histcount when successful, else zero
 */
int read_history(info_t *info)
{
	int t, lt = 0, lc = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *f = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	f = malloc(sizeof(char) * (fsize + 1));
	if (!f)
		return (0);
	rdlen = read(fd, f, fsize);
	f[fsize] = 0;
	if (rdlen <= 0)
		return (free(f), 0);
	close(fd);
	for (t = 0; t < fsize; t++)
		if (f[t] == '\n')
		{
			f[t] = 0;
			build_history_list(info, f + lt, lc++);
			lt = t + 1;
		}
	if (lt != t)
		build_history_list(info, f + lt, lc++);
	free(f);
	info->histcount = lc;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list – add the entries to histories linked list
 * @info: this structure that contains the potential arguments.
 * @buf: this is the buffer
 * @linecount: hist linecunt, histc
 *
 * Return: zero
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *e = NULL;

	if (info->history)
		e = info->history;
	add_node_end(&e, buf, linecount);
	if (!info->history)
		info->history = e;
	return (0);
}
/**
 * renumber_history – renumbers all history links the list changes
 * @info: this structure that contains the potential arguments.
 *
 * Return: the new hstcout
 */
int renumber_history(info_t *info)
{
	list_t *e = info->history;
	int p = 0;

	while (e)
	{
		e->num = p++;
		e = e->next;
	}
	return (info->histcount = p);
}
