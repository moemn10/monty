#include "monty.h"

/**
 * Z_sub - Prints an error message of program
 * @line_num: number of the lines of  the current operation.
 * Return: void
 */

void Z_sub(int line_num)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * Z_num - Checks if a string formating in int
 * @num: The string to check
 * Return: 1 if the string is a valid integer, 0 otherwise
 */

int Z_num(char *num)
{
	int x = 0;

	if (num[x] == '-')
		x++;

	while (num[x])
	{
		if (!(num[x] >= '0' && num[x] <= '9'))
			return (0);
		x++;
	}

	return (1);
}
