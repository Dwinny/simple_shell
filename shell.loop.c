#include "shell.h"

/**
 *  * hsh - main shell loop
 *   * @info: the param and R info structure
 *    * @av: the arg vector from main()
 *     * Return: 0 if it read success and 1 on err, or err code
 */
int hsh(info_t *info, char **av)
{
	ssize_t m = 0;
	int builtin_ret = 0;

	while (m != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		m = get_input(info);
		if (m != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 *  * find_builtin - finds a builtin command
 *   * @info: the param & R info structure
 *    * Return: return -1 if builtin is not found,
 *     * return 0 if builtin execution is  successfull,
 *      * return 1 if builtin is found but not on success,
 *       * return 2 if it show builtin signal()
 */
int find_builtin(info_t *info)
{
	int m, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (m = 0; builtintbl[m].type; m++)
		if (_strcmp(info->argv[0], builtintbl[m].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[m].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 *  * find_cmd - finds a path in command
 *   * @info: the param & R info structure
 *    * Return: NULL
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int m, d;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (m = 0, d = 0; info->arg[m]; m++)
		if (!is_delim(info->arg[m], " \t\n"))
			d++;
	if (!d)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 *  * fork_cmd - forks an executed thread to run command
 *   * @info: the param & R info structure
 *    * Return: NULL
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
