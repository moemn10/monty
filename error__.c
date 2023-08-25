#include "monty.h"

/**
 * Z_malloc - printing the errors of malloc .
 */
void Z_malloc(void)
{
	f_All();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}

/**
 * p_val - instruction thats Prints an
 * error message and exits
 * @line_num: current operation line number code
 * @op_code_code: the points to unrecognized op code
 */
void p_val(int line_num, char *op_code_user)
{

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code_user);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * root - prints the error file that we used
 */
void root(void)
{
	fprintf(stderr, "USAGE: the monty file :\n");
	exit(EXIT_FAILURE);
}

/**
 * open_ferror - prints the file name that holds the error
 * @fn: file name
 */
void open_ferror(char *fn)
{
	fprintf(stderr, "Error: Can't open this file %s\n", fn);
	exit(EXIT_FAILURE);
}
