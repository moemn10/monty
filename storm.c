#include "monty.h"

/**
 * storm .
 * @stack: Ptr for top of the Stack.
 * @line_number: Line num of Current operation.
 */

void stack(stack_t **stack, unsigned int line_num)
{
	UNUSED(stack);
	UNUSED(line_num);
	data.data_mode = STACK;
}


/**
 * queue .
 * @stack: Ptr for Top of The Stack
 * @line_number: Line num of the Current operation.
 */

void queue(stack_t **stack, unsigned int line_num)
{
	UNUSED(stack);
	UNUSED(line_num);
	data.data_mode = QUEUE;
}
