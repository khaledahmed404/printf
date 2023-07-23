#include "main.h"


/**
 * print_non_printable - a fun to print the asscii code in hexadesimal
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{

	char *str = va_arg(types, char *);
	int i = 0, offs = 0;

	UNUSED(flags);
	UNUSED(width);

	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offs] = str[i];
		else
			offs += append_hexa_code(str[i], buffer, i + offs);

		i++;
	}


	buffer[i + offs] = '\0';
	return (write(1, buffer, i + offs));
}



/**
 * print_pointer - a fun to print variable pointer
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char extra_char = 0, pading = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;

	unsigned long num_addrs;
	char map[] = "0123456789abcdef";

	void *str = va_arg(types, void *);

	UNUSED(width);

	UNUSED(size);

	if (str == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);

	num_addrs = (unsigned long)str;
	while (num_addrs > 0)
	{
		buffer[ind--] = map[num_addrs % 16];
		num_addrs /= 16;

		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pading = '0';

	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;

	ind++;
	return (write_pointer(buffer, ind, length, width, flags, pading,
				extra_char, padd_start));
}




/**
 * print_rot13string - a fun to print strings in rott13
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int i, j;
	char *str;
	char x;
	int num = 0;

	char inchar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outchar[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; inchar[j]; j++)
		{
			if (inchar[j] == str[i])
			{
				x = outchar[j];
				write(1, &x, 1);
				num++;
				break;
			}
		}

		if (!inchar[j])
		{
			x = str[i];
			write(1, &x, 1);
			num++;
		}
	}
	return (num);
}

/**
 * print_reverse - a fun to print reversee strings
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i, numof = 0;
	char *str;

	UNUSED(buffer);
	UNUSED(flags);

	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);

		numof++;
	}

	return (numof);
}


