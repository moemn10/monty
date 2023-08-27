#include "monty.h"

/**
 * errors_1 - Prints appropriate error messages based on the error code.
 * @error_s: The error codes and their meanings are as follows:
 * (1) => No file or multiple files provided to the program.
 * (2) => Unable to open or read the specified file.
 * (3) => Invalid instruction found in the file.
 * (4) => Memory allocation failed.
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The stack is empty for "pint" operation.
 * (7) => The stack is empty for "pop" operation.
 * (8) => The stack is too short for the current operation.
 */
void errors_1(int error_s, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, error_s);
	switch (error_s)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: Failed to allocate memory\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * errors_2 - Handles additional errors.
 * @error_s: The error codes and their meanings are as follows:
 * (6) => The stack is empty for "pint" operation.
 * (7) => The stack is empty for "pop" operation.
 * (8) => The stack is too short for the current operation.
 * (9) => Division by zero.
 */
void errors_2(int error_s, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, error_s);
	switch (error_s)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack is empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop, stack is empty\n",
				va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack is too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * str_errors - Handles string-related errors.
 * @error_s: The error codes and their meanings are as follows:
 * (10) ~> The value inside a node is outside the ASCII range.
 * (11) ~> The stack is empty.
 */
void str_errors(int error_s, ...)
{
	va_list args;
	int line_num;

	va_start(args, error_s);
	line_num = va_arg(args, int);
	switch (error_s)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value is out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack is empty\n", line_num);
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}
