#include "main.h"

/**
 * get_size - a fun for size to cast calculations
 * @format: the format
 * @i: an argument to take the parameters
 *
 * Return: return the size
 */

int get_size(const char *format, int *i)
{

	int sizee = 0;

	int curr_i = *i + 1;


	if (format[curr_i] == 'l')
		sizee = S_LONG;
	else if (format[curr_i] == 'h')
		sizee = S_SHORT;


	if (sizee == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sizee);

}

