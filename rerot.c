#include "monty.h"

/**
 * rotl - make rerotre
 * @stack: Point for the top of the stacks
 * @line_num: line number of the current operation
 */

void rotl(stack_t **stack, unsigned int line_num)
{
	int x = 0;
	stack_t *k = NULL;

	UNUSED(line_num);
	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		x = (*stack)->i;
		k = *stack;
		while (k->next)
		{
			k->i = k->next->i;
			k = k->next;
		}
		k->i = x;
	}
}

/**
 * rotr - makre a retore..
 * @stack: point for the top of the stacks
 * @line_num: line number of the current operation
 */

void rotr(stack_t **stack, unsigned int line_num)
{
	int le = 0;
	stack_t *k = NULL;

	UNUSED(line_num);

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		k = *stack;

		while (k->next != NULL)
		{
			le = k->i;
			k = k->next;
		}

		le = k->i;

		while (k->prev != NULL)
		{
			k->i = k->prev->i;
			k = k->prev;
		}

		(*stack)->i = le;
	}
}
