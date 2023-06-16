#include "shell.h"
/**
 * _myexit – this is the shell exit
 * @info:the structure that controls the potential argument.
 * Return: exits using an exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int ec;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		ec = _erratoi(info->argv[1]);
		if (ec == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd – this changes the process directory
 * @info: the structure that contains potential arguments.
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *y, *d, buffer[1024];
	int ch;

	y = getcwd(buffer, 1024);
	if (!y)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		d = _getenv(info, "HOME=");
		if (!d)
			ch = /* TODO: what should this be? */
				chdir((d = _getenv(info, "PWD=")) ? d : "/");
		else
		ch = chdir(d);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(y);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		ch = /* TODO: what should this be? */
			chdir((d = _getenv(info, "OLDPWD=")) ? d : "/");
	}
	else
		ch = chdir(info->argv[1]);
	if (ch == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp – this changes the directory of the process
 * @info: this contains the potential structure arguments.
 * Return: zero
 */
int _myhelp(info_t *info)
{
	char **ar;

	ar = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*ar); /* temp att_unused workaround */
	return (0);
}

