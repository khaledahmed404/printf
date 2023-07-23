#include "main.h"

/**
 * get_precision - a fun for precision calculations
 * @format: tge formate
 * @i: an argument to take the parameters
 * @list: list of an argumentts
 *
 * Return: return the precisions
 */
int get_precision(const char *format, int *i, va_list list)
{

	int precisions = -1;
	int curr_i = *i + 1;


	if (format[curr_i] != '.')
		return (precisions);
	precisions = 0;



	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{

		if (is_digit(format[curr_i]))
		{
			precisions *= 10;

			precisions += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precisions = va_arg(list, int);

			break;
		}
		else
			break;
	}

	*i = curr_i - 1;
	return (precisions);

}


