#include "monty.h"


/**
 * add_stack_ - Add To Node for The Stack.
 * @new_node: Ptr for New node.
 * @ln: Interger Represent the line number of the opcode.
 */
void add_stack_(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * p_stack - Add for node to The Stack.
 * @stack: Ptr to ptr pointing to top Node the stack.
 * @line_num: line number the opcode.
 */
void p_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_up_top - Add A Node to The Stack.
 * @stack: Ptr to A pointer pointing to Top Node of the stack.
 * @line_num: Interger Representing for line number of of the opcode.
 */
void pop_up_top(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * p_top - Print of the Top A Node the Stack.
 * @stack: Ptr for a pointer pointing to top Node of the Stack.
 * @line_num: Interger Represent The line number of the opcode.
 */
void p_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_num);
	printf("%d\n", (*stack)->n);
}
