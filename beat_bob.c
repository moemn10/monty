#include "monty.h"

/**
 * _pop - pop function
 * @stack: pointer for Top of the Stack
 * @line_num: Line num the Current operation.
 */

void _pop(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		user_stack(line_num);
	del_top(stack);
}

/**
 * _nop - getting nop fun
 * @stack: Ptr for top of The Stack
 * @line_num: Line num of the Current Operation.
 *
*/

void _nop(stack_t **stack, unsigned int line_num)
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
