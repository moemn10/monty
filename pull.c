#include "monty.h"

/**
 * pull - Prints all value On the stack,
 * Starting Tthe top of the stack.
 * @stack: Ptr To the top of the stack
 * @line_num: Line num Of current operation
 */

void pull(stack_t **stack, unsigned int line_num)
{
	UNUSED(line_num);
	p_stack(*stack);
}

/**
 * _push - Pushes For element To the Stack.
 * @stack: Ptr the top Of the stack.
 * @line_num: Line num of the Current operation
 */

void _push(stack_t **stack, unsigned int line_num)
{
	int i = 0;

	if (data.arg2)
	{
		if (Z_num(data.arg2))
		{
			i = atoi(data.arg2);
			if (data.data_mode == STACK)
				ext_stack_end(stack, i);
		}
		else
			Z_push(line_num);

	}
	else
		Z_push(line_num);
}
/**
 * Z_push - Prints Err of Push .and get
 * @line_num: Line num OF The Current operation
 */

void Z_push(int line_num)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * f_All - del all.
 */

void f_All(void)
{
	data_stack(data.stack);
	fclose(data.file);
	free(data.l);
}
