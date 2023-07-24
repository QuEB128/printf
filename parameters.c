#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - this displays an unsigned number
 * @types: outlines arguments
 * @buffer: Buffer array to manipuate print
 * @flags:  Compute flags that are in operation
 * @width: acquire width
 * @precision: field where precision is specified
 * @size: field where size is specified
 * Return: Number of characters displayed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[a--] = (value % 10) + '0';
		value /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to manipulate print
 * @flags:  Compute flags that are in operation
 * @width: acquire width
 * @precision: field where Precision is specified
 * @size: field where Size is specified
 * Return: Number of characters displayed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);
	unsigned long int init_num = value;

	UNUSED(width);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[a--] = (value % 8) + '0';
		value /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to manipulate print
 * @flags:  Compute flags that are in operation
 * @width: acquire width
 * @precision: field where Precision is specified
 * @size: field where Size is specified
 * Return: Number of characters displayed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to manipulate print
 * @flags:  Compute flags that are in operation
 * @width: acquire width
 * @precision: field where Precision is specified
 * @size: field where Size is specified
 * Return: Number of characters displayed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: display arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to manipulate print
 * @flags:  Computes flags that are in operation
 * @flag_ch: Computes flags that are in operation
 * @width: acquire width
 * @precision: field where Precision is specified
 * @size: field where Size is specified
 * @size: field where Size is specified
 * Return: Number of characters displayed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);
	unsigned long int init_num = value;

	UNUSED(width);

	vlaue = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (value > 0)
	{
		buffer[a--] = map_to[value % 16];
		value /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
