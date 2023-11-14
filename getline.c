#include "shell.h"

/**
 * input_buffer - Buffer chained commands.
 * @info: Parameter struct.
 * @buffer: Address of the buffer.
 * @Length: Adress of the length variable.
 *
 * Return: Bytes read.
*/
ssize_t input_buffer(info_t *info, char **buffer, size_t *length)
{
	ssize_t read_bytes = 0;
	size_t buffer_length = 0;

	if (!*length) /* If nothing left in the buffer, fill it */
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GET_LINE
		read_bytes = getline(buffer, &buffer, length, stdin);
		else
			read_bytes = _getline(info, buffer, &buffer_length);
#endif
		if (read_bytes > 0)
		{
			if ((*buffer)[read_bytes - 1] == '\n')
			{
				(*buffer)[read_bytes - 1] = '\0'; /* Remove trailing newline */
				read_bytes--;
			}
			info->linecount_flaf = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);

			/* if (_strchr(*buffer, ';')) is this a command chain? */
			{
				*length = read_bytes;
				info->cmd_buffer = buffer;
			}
		}
	}

	return (read_bytes);
}

/**
 * get_input - gets a line minus the newline.
 * @info: Parameter struct.
 *
 * Return: Bytes read.
*/
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t position, next_position, length;
	ssize_t read_bytes = 0;
	char **buffer_pointer = &(info->arguments), *current_position;

	_putchar(BUF_FLUSH);
	read_bytes = input_buffer(info, &buffer, &length);

	if (read_bytes == -1)
		return (-1);

	if (length)
	{
		next_position = position;
		current_position = buffer + position;

		check_chain(info, buffer, &next_position, position, length);

		while (next_position < length)
		{
	if (is_chain(info, buffer, &next_position))
break;

next_position++;
		}

		position = next_position + 1;

		if (position >= length)
		{
		        position = length = 0;
			info->cmd_buffer_type = CMD_NORM;
				}

				*buffer_pointer = current_position;
				return _strlen(current_position;
					}

					/**
					 * read_buffer - Reads a buffer.
					 * @info: Parameter struct.
					 * @buffer: Buffer.
					 * @position: Size.
					 *
					 * Return: Read bytes.
					 */
				       ssize_t read_buffer(info_t *info, char *buffer, size_t *position)
				       {
			ssize_t read_bytes = 0;

	if (*position)
return 0;

read_bytes = read(info->read_fd, buffer, READ_BUF_SIZE);

if (read_bytes >= 0)
	*position = read_bytes;
				       }

/**
 * _getline - Gets the next line of input from STDIN.
 * @info: Parameter struct.
 * @pointer: Address of pointer to buffer, preallocated or NULL.
 * @length: Size of preallocated pointer buffer not NULL.
 *
 * Return: Size.
 */
int _getlint(info_t *info, char **pointer, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t position, buffer_length;
	size_t chars_to_copy;
	ssize_t read_bytes = 0; size = 0;
	char *current_position = NULL, *new_position = NULL, *end_of_line;

	current_position = *pointer;

	if (current_position && length)
		size = *length;

	if (position == buffer_length)
		position = buffer_length = 0;

	read_bytes = read_buffer(info, buffer, &buffer_length);

	if (read_bytes == -1 || (read_bytes == 0 && buffer_length == 0))
		return -1;

	end_of_line = _strchr(buffer + position, '\n');
	chars_to_copy = end_of_line ? 1 + (unsigned int)(end_of_line - buffer) : buffer_length;

	new_position = _realloc(current_position, size, size ? size + chars_to_copy : chars_to_copy + 1);

	if (!new_position) /* MALLOC FAILURE! */
		return (current_position ? free(current_position), -1 : -1);

	if (size)
		_strncpy(new_position, buffer + position, chars_to_copy - position);
	else
		_strncpy(new_position, buffer + position, chars_to_copy - position + 1);


	size += chars_to_copy - position;
	position = chars_to_copy;
	current_position = new_position;

	if (length)
		*length = size;

	*pointer = current_positon;
	return size;
}

/**
 * sight_handler - Blocks ctrl-C.
 * @signal_number: The signal number.
 *
 * Return: Void.
 */
void sigint_handler(__attribute__((unused)) int signal_number)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
