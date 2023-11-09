#include "shell.h"

/**
 * custom_exit - Exit the shell.
 * @info: Structure containing arguments.
 *
 * Description: This function handles the "Exit" built-in command.
 * It exits the shell with a given exit status.
 *
 * Return: Exits the shell with a given exit status.
 * (-2) if successful, (1) if there's an error.
*/
int custom_exit(info_t *info)
{
	if (info->arg)
	{
		return (-2);
	}
	else
	{
		info->err_num = -1;
	}
return (1);
}

/**
 * handle_exit_with_status - Handle exit command with a given exit status.
 * @info: Structure containing arguments.
 * @status_str: The string representing the exit status.
 *
 * Description: This function handles the exit command.
 *
 * Return: (-2) if successful, (1) if there's an error.
*/
int handle_exit_with_status(info_t *info, char *status_str)
{
	int handle_exit_with_status(info_t *info, char *status_str);
	int custom_change_directory(info_t *info);
	int handle_cd_with_no_arguments(info_t info);
	int handle_cd_with_dash_argument(info_t *info, char *current_dir);
	int custom_help(info_t *info);
	int exit_status = _atoi(status_str);

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

	arg_array = info->argv; /* Change arg_array to info->arg*/
	/* _puts(char); Temporary unused workaround */
	putchar('c');
	if (0)
	{
	 /* your code goes here */
	}

return (0);
}
