#include "monty.h"

/**
 * _mul -multiplication for the second top elements
 * of the stack with the top element of the stack.
 * @stack: is pointer of stack
 * @line_num: number line of cuurent operation
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_mul(line_num);

	if ((*stack)->next)
	{
		(*stack)->next->i *= (*stack)->i;
		del_top(stack);
	}
	else
		Z_mul(line_num);

}


/**
 * Z_mul - prints error if there are not mul.
 * @line_num:number line of current operations
 */
void Z_mul(int line_num)
{

	fprintf(stderr, "L%d: can't be multiplied, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}


/**
 * _div - Dividing the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer of stack
 * @line_num: number line of current operation
 */
void _div(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		Z_div(line_num);

	if ((*stack)->next)
	{
		if ((*stack)->i == 0)
			Z_div_zero(line_num);
		(*stack)->next->i /= (*stack)->i;
		del_top(stack);
	}
	else
		Z_div(line_num);
}


/**
 * Z_div - printing division errors .
 * @line_num: number line of the current operation
 */
void Z_div(int line_num)
{
	fprintf(stderr, "L%d: can't be divided, stack too short\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}


/**
 * Z_div_zero- printing 0 if there are errors.
 * @line_num: number line of the current opearation
 */
void Zdiv_zero(int line_num)
{

	fprintf(stderr, "L%d: division by zero\n", line_num);
	f_All();
	exit(EXIT_FAILURE);
}
