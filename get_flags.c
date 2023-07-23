#include "main.h"

/**
 * get_flags - a fun for active flag calculations
 * @format: the formate
 * @i: an argument to take the parameters
 *
 * Return: return the flags
 */

int get_flags(const char *format, int *i)
{
	int flagd = 0;

	int k, curr_i;

	const int flag_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char flag_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{

		for (k = 0; flag_CH[k] != '\0'; k++)
			if (format[curr_i] == flag_CH[k])
			{
				flagd |= flag_ARR[k];

				break;
			}


		if (flag_CH[k] == 0)
			break;
	}


	*i = curr_i - 1;
	return (flagd);
}

