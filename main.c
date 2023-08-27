#include "monty.h"
        stack_t *head = NULL;

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_n();
	return (0);
}

/**
 * create_n - Creates a new node.
 * @i: Number to be stored in the node.
 * Return: Pointer to the newly created node, or NULL on failure.
 */
stack_t *create_n(int i)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors_1(4);
		node->next = NULL;
		node->prev = NULL;
		node->i = i;
		return (node);
}

/**
 * free_n - Frees all nodes in the stack.
 */
void free_n(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}

/**
 * add_queue_ - Adds a node to the queue.
 * @n_node: Pointer to the new node.
 * @lnm: Line number of the opcode.
 */
void add_queue_(stack_t **n_node, __attribute__((unused)) unsigned int lnm)
{
	stack_t *t;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	t = head;
	while (t->next != NULL)
	t = t->next;

	t->next = *n_node;
	(*n_node)->prev = t;
}
