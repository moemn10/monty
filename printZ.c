#include "monty.h"

/**
 * printZ .
 * @stack: Ptr To top of Stack
 * @line_number: Line num the Current operation
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_pint(line_num);

	printf("%d\n", (*stack)->n);
}
/**
 * Z_pint .
 * @line_number: Line num  the Current operation.
 */
void Z_pint(int line_num)
{

	fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}

/**
 * swap .
 * @stack: Ptr for top oF The Stack
 * @line_number: Line num the Current operation.
 */

void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (stack == NULL || *stack == NULL)
		Z_swap(line_num);

	if ((*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
		Z_swap(line_num);
}
/**
 * pswap .
 * @line_number: Line num The Current operation
 */

void pswap(int line_num)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
