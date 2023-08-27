#include "monty.h"

/**
 * pop_up_nop - Its nothing.
 * @stack: Ptr to a ptr pointing to the Top Node of A Stack.
 * @line_num: Interger represenT the Line number For the opcode.
 */
void pop_up_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * swap_n - Swap's the top Two Element of the Stack.
 * @stack: Ptr to a pointer point to top Node for the Stack.
 * @line_num: Interger represent The line number of A the opcode.
 */
void swap_n(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_2(8, line_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_n - Add the top Two element for the Stack.
 * @stack: Ptr to a ptr point to top Node of the sack.
 * @line_num: Interger represent the line number for the opcode.
 */
void add_n(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_2(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->i + (*stack)->prev->i;
	(*stack)->i = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_n - Add for top Two Elements for the stack.
 * @stack: Ptr to A ptr point to top Node of The stack.
 * @line_num: Interger represent the line Number for The opcode.
 */
void sub_n(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		errors_2(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->i - (*stack)->prev->i;
	(*stack)->i = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_n - Add top Two Element of The Stack.
 * @stack: ptr to A ptrr point to Top Node for the stack.
 * @line_num: Interger represet the line Number for the opcode.
 */
void div_n(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_2(8, line_num, "div");

	if ((*stack)->i == 0)
		errors_2(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->i / (*stack)->prev->i;
	(*stack)->i = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
