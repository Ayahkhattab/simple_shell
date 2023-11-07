#include "shell.h"

/**
 *  custom_exit - Exit the shell.
 *  @info: Structure containing arguments.
 *  Return: Exits with a given exit status.
*/
int custom_exit(info_t *info)
{
	int exit_status = 0;

	if (info->arg[1])
	{
		exit_status = _atoi(info->arg[1]);
		if (exit_status == -1)
		{
			info->err_num = 2;
			print_error(info, "Invalid number: ");
			_eputs(info->arg[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_status;
	}
	else
	{
		info->err_num = -1;
	}

	return (-2);
}

/**
 * custom_change_directory - Change the current directory of the process.
 * @info: Structure containing arguments.
 * Return: Always 0.
*/
int custom_change_directory(info_t *info)
{
	char *current_dir, *dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);

	if (!info->arg[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
		{
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		}
		else
		{
			chdir_ret = chdir(dir);
		}
	}
	else if (_strcmp(info->arg[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{
		chdir_ret = chdir(info->arg[1]);

	}

	if (chdir_ret == -1)
	{
		print_error(info, "Can't change directory to ");
		_eputs(info->arg[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}
/**
 * custom_help - Display help message.
 * @info: Structure containing arguments.
 * Return: Always 0.
*/
int custom_help(info_t *info)
{
	char **arg_array = info->arg;

	_puts("Help message: Function not yet implemented\n");

	if (0)
	{
		{
		_puts(*arg_array); /* Temporary unused workaround */
	}

	return (0);
	}