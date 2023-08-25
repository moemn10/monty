#include "monty.h"

/**
 * pall:  Prints all value On the stack,
 * Starting Tthe top of the stack.
 * @stack: Ptr To the top of the stack
 * @line_number: Line num Of current operation
 */

void pall(stack_t **stack, unsigned int line_num)
{
	UNUSED(line_num);
	p_stack(*stack);
}

/**
 * push:Pushes For element To the Stack.
 * @stack: Ptr the top Of the stack.
 * @line_number: Line num of the Current operation
 */

void push(stack_t **stack, unsigned int line_num)
{
	int i = 0;

	if (data.arg2)
	{
		if (Znum(data.arg2))
		{
			n = atoi(data.arg2);
			if (data.data_mode == STACK)
				ext_stack_end(stack, n);
		}
		else
			Z_push(line_num);

	}
	else
		Z_push(line_num);
}
/**
 * ppush_error: Prints Err of Push .
 * @line_number: Line num OF The Current operation
 */

void Z_push(int line_number)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * free_all - del all.
 */

void f_All(void)
{
	data_stack(data.stack);
	fclose(data.file);
	free(data.l);
}
