#include "main.h"
/**
 * handle_print -  a fun for Printting the arguments
 * @fmt: the format
 * @list: the list
 * @ind: the ind
 * @buffer: the buffer
 * @flags: Calculation of flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: return the printed characters
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{

	int print_char = -1, unknown_lens = 0;
	int i;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};


	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));


	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);

		unknown_lens += write(1, "%%", 1);

		if (fmt[*ind - 1] == ' ')
			unknown_lens += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_lens += write(1, &fmt[*ind], 1);
		return (unknown_lens);
	}
	return (print_char);
}


