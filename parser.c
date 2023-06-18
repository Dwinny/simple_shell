#include "shell.h"

/**
 *  * is_cmd - determines if a file is an executable command
 *   * @info: the info structure
 *    * @path: path to the file
 *     * Return: 1 if true, 0 if false
 *      */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 *  * dup_chars - duplicates char
 *   * @pathstr: the path string
 *    * @start: index to start
 *     * @stop: index to stop
 *      * Return: pointer to new buf
 *       */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 *  * find_path - finds this command in the path string
 *   * @info: the info structure
 *    * @pathstr: the path string
 *     * @cmd: the command to find path
 *      * Return: full path of command if found or NULL if not found
 *       */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int m = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[m])
				break;
			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}
#include "shell.h"

/**
 *  * is_cmd - determines if a file is an executable command
 *   * @info: the info structure
 *    * @path: path to the file
 *     * Return: 1 if true, 0 if false
 *      */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 *  * dup_chars - duplicates char
 *   * @pathstr: the path string
 *    * @start: index to start
 *     * @stop: index to stop
 *      * Return: pointer to new buf
 *       */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 *  * find_path - finds this command in the path string
 *   * @info: the info structure
 *    * @pathstr: the path string
 *     * @cmd: the command to find path
 *      * Return: full path of command if found or NULL if not found
 *       */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int m = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[m])
				break;
			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}

