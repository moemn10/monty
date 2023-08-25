#include "monty.h"

/**
 * beat-poping
 * @stack: Ptr for Top of the Stack
 * @line_number: Line num the Current operation.
 */

void pop(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		user_stack(line_num);
	del_top(stack);
}

/**
 * NOP .
 * @stack: Ptr for top of The Stack
 * @line_number: Line num of the Current Operation.
 */

void nop(stack_t **stack, unsigned int line_num)
{
	UNUSED(stack);
	UNUSED(line_num);
}

/**
 * user_stack .
 * @line_number: Line num of The Current operation.
 */

void user_stack(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
