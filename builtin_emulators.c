#include "shell.h"

/**
 * custom_exit - Exit the shell.
 * @info: Structure containing arguments.
 *
 * Description: This function handles the "exit" built-in command.
 * It exits the shell with a given exit status.
 *
 * Return: Exits the shell with a given exit status.
 * -2 if successful, 1 if there's an error.
*/
int custom_exit(info_t *info)
{
	if (info->args[1])
	{
	return; /* Fix: Add parentheses */
	}
	else
	{
		info->err_num = -1;
	}
	return (1);
}

int handle_exit_with_status(info_t *info, char *status_str)
{
	int handle_exit_with_status(info_t *info, char *status_str);
	int custom_change_directory(info_t *info);
	int handle_cd_with_no_arguments(info_t *info);
	int handle_cd_with_dash_argument(info_t *info, char *current_dir);
	int custom_help(info_t *info);
	if (exit_status == -1)

	{
		info->err_num = -2;
		print_error(info, "Invalid number: ");
		_eputs(status_str);
		_eputchar('\n');
		return (1);
	}
	info->err_num = exit_status;
	return (-2);
}

/**
 * custom_change_directory - Change the current directory of the process.
 * @info: Structure containing arguments.
 *
 * Return: Always 0.
*/
int custom_change_directory(info_t *info)
{
	char *current_dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);

	if (!info->args[1])
	{
	return (-2); /* Fix; Add parentheses */
	}
	else if (_strcmp(info->args[1], "-") == 0)
	{
	return (0); /* Fix: Add parentheses */
	}
	else
	{
		chdir_ret = chdir(info->args[1]);
	}

	if (chdir_ret == -1)
	{
		print_error(info, "Can't change directory to ");
		_eputs(info->args[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}


int handle_cd_with_no_arguments(info_t *info)
{
	char *dir;
	int chdir_ret;

	dir = _getenv(info, "HOME=");


	if (!dir)
	{
		chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
	}
	else
	{
		chdir_ret = chdir(dir);
	}

	return (0);
}

int handle_cd_with_dash_argument(info_t *info, char *current_dir)
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
	return (0);
}

/**
 * custom_help - Display help message.
 * @info: Structure containing arguments.
 *
 * Description: This function handles the "help" built-in command.
 * It displays a help message.
 *
 * Return: Always 0.
*/
int custom_help(info_t *info)
{
	char **arg_array;

	arg_array = info->args;
	_puts("Help message: Function not yet implemented\n");
	if (0)
	{
		_puts(*arg_array); /* Temporary unused workaround */
	}

	return (0);
}

