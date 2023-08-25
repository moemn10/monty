#include "monty.h"

/**
 * data_stack - free all of the stacks
 * @kr: pointer to stack_t's head
 * Return: void
 */
void data_stack(stack_t *kr)
{
	stack_t *xc;

	xc = kr;
	while (kr)
	{
		xc = kr;
		kr = kr->next;
		if (xc)
			free(xc);
	}
}
