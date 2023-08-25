#include "monty.h"

/**
 * _add - add For The Stack .
 * @stack: Ptr To Stack.
 * @line_num: Current operation line num
 */

void _add(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_add(line_num);

	if ((*stack)->next)
	{
		(*stack)->next->i += (*stack)->i;
		del_top(stack);
	}
	else
		Z_add(line_num);
}

/**
 * Z_add - Print the ERR.
 * @line_num: Current operation to line num.
 */

void Z_add(int line_num)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * _sub - Sub_Tracks.
 * @stack: stack ptr
 * @line_num: Current operation num line.
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_sub(line_num);

	if ((*stack)->next)
	{
		(*stack)->next->i -= (*stack)->i;
		del_top(stack);
	}
	else
		Z_sub(line_num);
}


/**
 * _mod - compute The RESET of The Division the Second top Elements.
 * of The stack With the Top Elements of the Stack.
 * @stack: stack ptr
 * @line_num: Crrent operation num line
 */
void _mod(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_mod(line_num);

	if ((*stack)->next)
	{
		if ((*stack)->i == 0)
			Z_div_one(line_num);
		(*stack)->next->i %= (*stack)->i;
		del_top(stack);
	}
	else
		Z_mod(line_num);
}
