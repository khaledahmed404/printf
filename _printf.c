#include "main.h"


void print_buffer(char buffer[], int *buff_ind);


/**
 * _printf - the fun of printf.
 * @format: the formatt of fun.
 *
 * Return: characters that printed
 */

int _printf(const char *format, ...)
{
	int i;
	int prin_chars = 0;
	int prin = 0;

	int flags, precision, width, buff_ind, size  = 0;
	va_list list;

	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);


	va_start(list, format);


	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];

			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			prin_chars++;

		}
		else
		{
			print_buffer(buffer, &buff_ind);

			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);

			size = get_size(format, &i);
			++i;
			prin = handle_print(format, &i, list, buffer, flags,
					width, precision, size);

			if (prin == -1)
				return (-1);

			prin_chars += prin;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (prin_chars);

}



/**
 * print_buffer - print buffer's contents
 *
 * @buff_ind: index to add next characters
 * @buffer: array that contains characters
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}



