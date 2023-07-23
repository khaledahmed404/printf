#include "main.h"

/**
 * get_width - a fun for the width calculations
 * @format: the format
 * @i: an argument to take the parameters
 * @list: the list
 *
 * Return: return the width
 */

int get_width(const char *format, int *i, va_list list)
{

	int widthh = 0;

	int curr_i;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			widthh *= 10;

			widthh += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			widthh = va_arg(list, int);

			break;
		}
		else
			break;
	}


	*i = curr_i - 1;
	return (widthh);

}

