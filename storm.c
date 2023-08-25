#include "monty.h"

/**
 * _stack - stacks functions.
 * @stack: Ptr for top of the Stack.
 * @line_num: Line num of Current operation.
 */

void _stack(stack_t **stack, unsigned int line_num)
{
	UNUSED(stack);
	UNUSED(line_num);
	data.data_mode = STACK;
}


/**
 * queue - find queue normal
 * @stack: Ptr for Top of The Stack
 * @line_num: Line num of the Current operation.
 */

void queue(stack_t **stack, unsigned int line_num)
{
	UNUSED(stack);
	UNUSED(line_num);
	data.data_mode = QUEUE;
}
