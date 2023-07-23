#include "main.h"

/**
 * is_digit - a fun for verifing that character is a digitt or not
 * @c: the character
 *
 * Return: return 1 or 0
 */

int is_digit(char c)
{

	if (c >= '0' && c <= '9')
		return (1);
	return (0);

}

/**
 * is_printable - a fun for evaluation of characters
 * @c: characters
 *
 * Return: return 1 or 0
 */

int is_printable(char c)
{

	if (c >= 32 && c < 127)
		return (1);


	return (0);
}

/**
 * append_hexa_code -  a fun for appending
 * @buffer: arrayy of bufferss
 * @i: the index
 * @ascii_code: the asciii codee
 *
 * Return: return 3 always
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';

	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];

	buffer[i] = map[ascii_code % 16];

	return (3);
}



/**
 * convert_size_unsgnd - a fun for castting numbers
 * @num: the number
 * @size: the size of numbers
 *
 * Return: return value of casted number
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{

	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);


	return ((unsigned int)num);

}


/**
 * convert_size_number - a fun for castting numbers
 * @num: the number
 * @size: the size of numbers
 *
 * Return: return value of casted number
 */

long int convert_size_number(long int num, int size)
{

	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);


	return ((int)num);

}


