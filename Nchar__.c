#include "monty.h"

/**
 * pchar Print Char.
 * @stack: Pointer To the Top OF the Stack.
 * @line_number: Line number of the current operation
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	int i;

	if (stack == NULL || *stack == NULL)
		char_emp(line_num);

	n = (*stack)->n;
	if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		printf("%c\n", n);
	else
		Z_pchar(line_num);
}

/**
 * pstr.
 * @stack: Ptr to The Top of the Stack.
 * @line_number: Line Number this of Current Operation
 */

void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *c;

	UNUSED(line_num);
	c = *stack;
	while (c)
	{
		if ((c->i >= 65 && c->i <= 90) || (c->i >= 97 && c->i <= 122))
		{
			printf("%c", c->n);
			c = c->next;
		}
		else
			break;
	}
	printf("\n");
}

/**
 * pchar.
 * @line_number: Line num of the Current OPeration
 */

void Z_pchar(int line_num)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * pchar_Stack_empty.
 * @line_number: Line num the Current operation.
 */

void char_emp(int line_num)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
