#include "main.h"


/**
 * print_string - a fun to print string
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_string(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}


/**
 * print_char - a fun to print a char
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}


/**
 * print_percent - a fun to print a sign
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_percent(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);

	UNUSED(size);


	return (write(1, "%%", 1));
}





/**
 * print_binary - a fun to print unsigned number
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int t, p, i, summ;
	int count;
	unsigned int a[32];


	UNUSED(buffer);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);

	p = 2147483648;
	t = va_arg(types, unsigned int);

	a[0] = t / p;

	for (i = 1; i < 32; i++)
	{
		p /= 2;
		a[i] = (t / p) % 2;
	}

	for (i = 0, summ = 0, count = 0; i < 32; i++)
	{
		summ += a[i];

		if (summ || i == 31)
		{
			char u = '0' + a[i];

			write(1, &u, 1);
			count++;
		}

	}

	return (count);

}



/**
 * print_int - a fun to print a int
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_int(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int is_negative = 0;
	int i = BUFF_SIZE - 2;
	unsigned long int num;
	long int n = va_arg(types, long int);

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);

		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';

		num /= 10;
	}
	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

