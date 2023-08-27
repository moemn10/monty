#include "monty.h"

/**
 * mul_n - Add the Tp Two Element of the Stack.
 * @stack: Ptr To a ptr point to top Node of the Stack.
 * @line_num: Interger represent the line Number for the opcode.
 */
void mul_n(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_2(8, line_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->i * (*stack)->prev->i;
	(*stack)->i = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_n - add  top Two Element of The Stack.
 * @stack: Ptr To a ptr point to Top Node fo A stack.
 * @line_num: Interger represent the Line Number for A opcode.
 */
void mod_n(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		errors_2(8, line_num, "mod");


	if ((*stack)->i == 0)
		errors_2(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->i % (*stack)->prev->i;
	(*stack)->i = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
