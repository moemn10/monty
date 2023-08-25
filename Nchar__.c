#include "monty.h"

/**
 * pchar - Print Char.
 * @stack: Pointer To the Top OF the Stack.
 * @line_num: Line number of the current operation
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	int i;

	if (stack == NULL || *stack == NULL)
		char_emp(line_num);

	i = (*stack)->i;
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
		printf("%c\n", i);
	else
		Z_pchar(line_num);
}

/**
 * _pstr - print strings
 * @stack: Ptr to The Top of the Stack.
 * @line_num: Line Number this of Current Operation
 */

void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *x;

	UNUSED(line_num);
	x = *stack;
	while (x)
	{
		if ((x->i >= 65 && x->i <= 90) || (x->i >= 97 && x->i <= 122))
		{
			printf("%c", x->i);
			x = x->next;
		}
		else
			break;
	}
	printf("\n");
}

/**
 * Z_pchar - print charcter
 * @line_num: Line num of the Current OPeration
 */

void Z_pchar(int line_num)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * char_emp - empty charcter
 * @line_num: Line num the Current operation.
 */

void char_emp(int line_num)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
