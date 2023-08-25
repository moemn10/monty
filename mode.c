#include "monty.h"

/**
 * add - add For The Stack .
 * @stack: Ptr To Stack.
 * @line_number: Current operation line num
 */

void add(stack_t **stack, unsigned int line_num)
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
 * padd- Print the ERR.
 * @line_number: Current operation to line num.
 */

void Z_add(int line_num)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * sub - Sub_Tracks.
 * @stack: stack ptr
 * @line_number: Current operation num line.
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		psub(line_num);

	if ((*stack)->next)
	{
		(*stack)->next->i -= (*stack)->i;
		del_top(stack);
	}
	else
		Z_sub(line_num);
}


/**
 * mod - compute The RESET of The Division the Second top Elements.
 * of The stack With the Top Elements of the Stack.
 * @stack: stack ptr
 * @line_number: Crrent operation num line
 */
void mod(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		pmod(line_num);

	if ((*stack)->next)
	{
		if ((*stack)->i == 0)
			Z_div_one(line_number);
		(*stack)->next->i %= (*stack)->i;
		del_top(stack);
	}
	else
		Z_mod(line_num);
}
