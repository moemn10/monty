#include "monty.h"

/**
 * pop - pop function
 * @stack: pointer for Top of the Stack
 * @line_num: Line num the Current operation.
 */

void pop(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		user_stack(line_num);
	delete_top(stack);
}

/**
 * nop - getting nop fun
 * @stack: Ptr for top of The Stack
 * @line_num: Line num of the Current Operation.
 *
*/

void nop(stack_t **stack, unsigned int line_num)
{
	UNUSED(stack);
	UNUSED(line_num);
}

/**
 * user_stack - mnaaklsjsd
 * @line_num: Line num of The Current operation.
 */

void user_stack(int line_num)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
