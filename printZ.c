#include "monty.h"

/**
 * _pint - print exds
 * @stack: Ptr To top of Stack
 * @line_num: Line num the Current operation
 */

void _pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_pint(line_num);

	printf("%d\n", (*stack)->i);
}
/**
 * Z_pint - print erro
 * @line_num: Line num  the Current operation.
 */
void Z_pint(int line_num)
{

	fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * _swap - swaping elments
 * @stack: Ptr for top oF The Stack
 * @line_num: Line num the Current operation.
 */

void _swap(stack_t **stack, unsigned int line_num)
{
	int t;

	if (stack == NULL || *stack == NULL)
		Z_swap(line_num);

	if ((*stack)->next)
	{
		t = (*stack)->i;
		(*stack)->i = (*stack)->next->i;
		(*stack)->next->i = t;
	}
	else
		Z_swap(line_num);
}
/**
 * Z_swap - changing
 * @line_num: Line num The Current operation
 */

void Z_swap(int line_num)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
