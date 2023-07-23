#include "main.h"

/**
 * print_octal - a fun to print octal num
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{

	int i = BUFF_SIZE - 2;

	unsigned long int numm = va_arg(types, unsigned long int);
	unsigned long int init_num = numm;

	UNUSED(width);
	numm = convert_size_unsgnd(numm, size);

	if (numm == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';


	while (numm > 0)
	{
		buffer[i--] = (numm % 8) + '0';
		numm /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_unsigned - a fun to print unsigned numbers
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int numm = va_arg(types, unsigned long int);

	numm = convert_size_unsgnd(numm, size);

	if (numm == 0)
		buffer[i--] = '0';


	buffer[BUFF_SIZE - 1] = '\0';

	while (numm > 0)
	{
		buffer[i--] = (numm % 10) + '0';

		numm /= 10;
	}

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexa_upper - a fun to print upper hexadecimal num
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}



/**
 * print_hexadecimal - a fun to print hexadecimal num
 * @types: a list
 * @buffer: arrayy of bufferss
 * @flags: flagss
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}




/**
 * print_hexa - a fun to print in lower or upper hexadecimal number
 * @types:a list
 * @map_to: a valuess in an array to mapp
 * @buffer: arrayy of bufferss
 * @flags:  flagss
 * @flag_ch: flags
 * @width: thee width
 * @precision: the precision
 * @size: the size of
 *
 * Return: number of chars which was printed
 */

int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{

	unsigned long int numm = va_arg(types, unsigned long int);
	unsigned long int init_num = numm;

	int i = BUFF_SIZE - 2;

	UNUSED(width);
	numm = convert_size_unsgnd(numm, size);

	if (numm == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (numm > 0)
	{
		buffer[i--] = map_to[numm % 16];
		numm /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


